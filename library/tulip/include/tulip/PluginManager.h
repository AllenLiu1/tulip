/**
 *
 * This file is part of Tulip (www.tulip-software.org)
 *
 * Authors: David Auber and the Tulip development Team
 * from LaBRI, University of Bordeaux 1 and Inria Bordeaux - Sud Ouest
 *
 * Tulip is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * Tulip is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; witho  ut even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 */
#ifndef _TEMPLATEFACTORY_H
#define _TEMPLATEFACTORY_H

#include <list>
#include <string>
#include <set>

#include <tulip/PluginLoader.h>
#include <tulip/WithParameter.h>
#include <tulip/WithDependency.h>
#include <tulip/Iterator.h>
#include <tulip/AbstractPluginInfo.h>
#include <tulip/TlpTools.h>
#include <tulip/PluginContext.h>

namespace tlp {

/** @addtogroup plugins
 * @brief The Tulip plug-in system allows plug-ins to be loaded dynamically at run-time, and can check dependencies on other plug-ins, as well as multiple definitions.
 *
 * The Tulip plug-in system can be decomposed in 4 layers:
 *
 * 1: Tulip, who knows about TemplateFactories
 *
 * 2: TemplateFactories, who know about Plugin subclasses, usually called factories.
 *
 * 3: Plugin subclasses, who know about the plugin itself
 *
 * 4: The plugin itself, a subclass of Algorithm (more likely IntegerAlgorithm, DoubleAlgorithm, ...), View, ControllerViewsManager, ...
 */

/*@{*/

/**
 * @brief This interface lists functions used to regroup plug-ins.
 *
 * It is used to list plug-ins that register themselves into it.
 * 
 * The PluginManager's role is to list plug-ins, and retrive their dependencies for Tulip to check if they are met.
 * The only check performed should be the unicity of a plug-in in the system.
 * 
 * Each Tulip plug-in has a factory, which needs to be registered into a PluginManager.
 * TemplateFactories register themselves in the Tulip plug-in system, and Tulip lists the plug-ins of each PluginManager.
 * 
 **/
class PluginManagerInterface {
public:
  static TLP_SCOPE std::map< std::string, PluginManagerInterface* > *allFactories;
  static TLP_SCOPE PluginLoader *currentLoader;

  virtual ~PluginManagerInterface(){}

  /**
   * @brief Gets the list of plug-ins that registered themselves in this factory.
   *
   * @return :Iterator< std::string >* An iterator over the names of the plug-ins registered in this factory.
   **/
  virtual Iterator<std::string>* availablePlugins() const = 0;
  
  /**
   * @brief Checks if a given name is registered in this factory.
   *
   * @param pluginName The name of the plug-in to look for.
   * @return bool Whether there is a plug-in with the given name registered in this factory.
   **/
  virtual bool pluginExists(const std::string &pluginName) const = 0;
  
  /**
   * @brief Gets the list of parameters for the given plug-in.
   *
   * @param name The name of the plug-in to retrieve the parameters of.
   * @return :StructDef The parameters of the plug-in.
   **/
  virtual const StructDef getPluginParameters(std::string name) const = 0;

  /**
   * @brief Gets the release number of the given plug-in.
   *
   * @param name The name of the plug-in to retrieve the version number of.
   * @return :string The version number, ussually formatted as X[.Y], where X is the major, and Y the minor.
   **/
  virtual std::string getPluginRelease(std::string name) const = 0;

  /**
   * @brief Gets the dependencies of a plug-in.
   *
   * @param name The name of the plug-in to retrieve the dependencies of.
   * @return :list< tlp::Dependency, std::allocator< tlp::Dependency > > The list of dependencies of the plug-in.
   **/
  virtual std::list<tlp::Dependency> getPluginDependencies(std::string name) const = 0;

  /**
   * @brief Gets the class name for the plug-in's registered class.
   *  If the class is in the tlp namespace, the 'tlp::' prefix is removed.
   *
   * @return :string The class name of the plug-in.
   **/
  virtual std::string getPluginsClassName() const = 0;

  /**
   * @brief Removes a plug-in from this factory.
   * This is usefull when a plug-in has unmet dependencies, or appears more than once.
   *
   * @param name The name of the plug-in to remove.
   * @return void
   **/
  virtual void removePlugin(const std::string& name)=0;

  /**
   * @brief Adds a factory to a static map of factories.
   * This map is then used to list all the factories, and all the plug-ins for each factory.
   *
   * @param factory The factory to add.
   * @param name The name of the factory to add, used as key.   
   * @return void
   **/
  static void addFactory(PluginManagerInterface *factory, const std::string &name)  {
    if (!allFactories)
      allFactories = new std::map<std::string, PluginManagerInterface*>();
    //std::cerr << name.c_str() << " factory added" << std::endl;
    (*allFactories)[name] = factory;
  }

  /**
   * @brief Checks if a plug-in exists in a specific factory.
   * In debug mode, an assert checks the factory is registered in the factory map before accessing it.
   * 
   * @param factoryName The name of the factory to look into.
   * @param pluginName The name of the plugin to look for.
   * @return bool Whether the plug-in exists in the specified factory.
   **/
  static bool pluginExists(const std::string& factoryName, const std::string& pluginName) {
    assert(allFactories->find(factoryName) != allFactories->end());
    return (*allFactories)[factoryName]->pluginExists(pluginName);
  }

  static void checkLoadedPluginsDependencies(tlp::PluginLoader* loader) {
    // plugins dependencies loop
    bool depsNeedCheck;
    do {
      std::map<std::string, PluginManagerInterface *>::const_iterator it = PluginManagerInterface::allFactories->begin();
      depsNeedCheck = false;
      // loop over factories
      for (; it != PluginManagerInterface::allFactories->end(); ++  it) {
        PluginManagerInterface *tfi = (*it).second;
        // loop over plugins
        Iterator<std::string> *itP = tfi->availablePlugins();
        while(itP->hasNext()) {
          std::string pluginName = itP->next();
          std::list<Dependency> dependencies = tfi->getPluginDependencies(pluginName);
          std::list<Dependency>::const_iterator itD = dependencies.begin();
          // loop over dependencies
          for (; itD != dependencies.end(); ++itD) {
            std::string factoryDepName = (*itD).factoryName;
            std::string pluginDepName = (*itD).pluginName;
            if (!PluginManagerInterface::pluginExists(factoryDepName, pluginDepName)) {
              if (loader)
                loader->aborted(pluginName, tfi->getPluginsClassName() +
                " '" + pluginName + "' will be removed, it depends on missing " +
                factoryDepName + " '" + pluginDepName + "'.");
              tfi->removePlugin(pluginName);
              depsNeedCheck = true;
              break;
            }
            std::string release = (*PluginManagerInterface::allFactories)[factoryDepName]->getPluginRelease(pluginDepName);
            std::string releaseDep = (*itD).pluginRelease;
            if (getMajor(release) != getMajor(releaseDep) ||
              getMinor(release) != getMinor(releaseDep)) {
              if (loader) {
                loader->aborted(pluginName, tfi->getPluginsClassName() +
                " '" + pluginName + "' will be removed, it depends on release " +
                releaseDep + " of " + factoryDepName + " '" + pluginDepName + "' but " +
                release + " is loaded.");
              }
              tfi->removePlugin(pluginName);
              depsNeedCheck = true;
              break;
            }
          }
        }
        delete itP;
      }
    } while (depsNeedCheck);
  }
};

template <class PluginObject, class PluginContext>
class FactoryInterface;

/**
 * @brief This template class takes 3 parameters :
 * 
 * * The type of factory that it will list,
 * 
 * * The type of object said factories build,
 * 
 * * The type of object to pass as parameter to the objects when building them.
 *
 * When constructed it registers itself into the factories map automatically.
 **/
template<class ObjectType, class Context>
class PluginManager: public PluginManagerInterface {
private:
  struct PluginDescription {
    FactoryInterface<ObjectType, Context>* factory;
    StructDef parameters;
    std::list<tlp::Dependency> dependencies;
  };
  
public:

  PluginManager() {
    PluginManagerInterface::addFactory(this, tlp::demangleTlpClassName(typeid(ObjectType).name()));
  }

  typedef std::map<std::string , PluginDescription> ObjectCreator;

  /**
   * @brief Stores the the facotry, dependencies, and parameters of all the plugins that register into this factory.
   **/
  ObjectCreator objMap;

  /**
   * @brief Constructs a plug-in.
   *
   * @param name The name of the plug-in to instantiate.
   * @param p The context to give to the plug-in.
   * @return ObjectType* The newly constructed plug-in.
   **/
  ObjectType *getPluginObject(const std::string& name, Context p) const;

  //the following function are inherited from PluginManagerInterface, and by default inherit the doc.
  Iterator<std::string>* availablePlugins() const;
  bool pluginExists(const std::string& pluginName) const;
  const StructDef getPluginParameters(std::string name) const;
  std::string getPluginRelease(std::string name) const;
  std::list<tlp::Dependency> getPluginDependencies(std::string name) const;
  std::string getPluginsClassName() const;
  void registerPlugin(FactoryInterface<ObjectType, Context>* objectFactory);
  void removePlugin(const std::string &name);
};

template <class PropertyAlgorithm> class PropertyFactory : public FactoryInterface<PropertyAlgorithm, PropertyContext> {
public:
  virtual ~PropertyFactory() {}
};

/*@}*/

}
#include "cxx/PluginManager.cxx"
#endif
