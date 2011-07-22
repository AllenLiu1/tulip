#include <tulip/PluginManager.h>
#include <tulip/PluginLister.h>

#include <QtXml/QDomDocument>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QCoreApplication>

using namespace std;
using namespace tlp;

QMap<QString, LocationPlugins> PluginManager::_remoteLocations;

QList<tlp::PluginInformations*> PluginManager::pluginsList(Location list) {
  QMap<QString, tlp::PluginInformations*> result;

  if(list.testFlag(Local)) {
    for(std::map<std::string, PluginListerInterface*>::const_iterator it = PluginListerInterface::allFactories->begin(); it != PluginListerInterface::allFactories->end(); ++it) {
      PluginListerInterface* currentLister = it->second;
      Iterator<string>* plugins = currentLister->availablePlugins();

      while(plugins->hasNext()) {
        string pluginName = plugins->next();
        const AbstractPluginInfo& info = currentLister->pluginInformations(pluginName);
        PluginInformations* localinfo = new PluginInformations(info, currentLister->getPluginsClassName(), currentLister->getPluginLibrary(pluginName));
        result[pluginName.c_str()] = localinfo;
      }

      delete plugins;
    }
  }

  if(list.testFlag(Remote)) {
    for(QMap<QString, LocationPlugins>::const_iterator it = _remoteLocations.begin(); it != _remoteLocations.end(); ++it) {
      for(LocationPlugins::const_iterator locationIt = it.value().begin(); locationIt != it.value().end(); ++locationIt) {
        QMap<QString, tlp::PluginInformations*>::const_iterator current = result.find(locationIt.key());

        if(current == result.end()) {
          DistantPluginInfo* pluginInfo = locationIt.value();
          PluginInformations* pluginInformations = new PluginInformations(*pluginInfo, pluginInfo->getType(), pluginInfo->getLocation(), pluginInfo->getRemotePluginName());
          result[locationIt.key()] = pluginInformations;
        }
        else {
          current.value()->AddPluginInformations(locationIt.value());
        }
      }
    }
  }

  return result.values();
}

QString PluginManager::getPluginServerDescription(const QString& location) {

  QNetworkAccessManager manager;
  QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(location + "/serverDescription.xml")));

  while(!reply->isFinished()) {
    QCoreApplication::processEvents();
  }

  if(reply->error() != QNetworkReply::NoError) {
    std::cout << "error while retrieving server description (" << location.toStdString() << ") : " << reply->errorString().toStdString() << std::endl;
    return QString::null;
  }

  QString content(reply->readAll());
  return content;
}

LocationPlugins PluginManager::parseDescription(const QString& xmlDescription, const QString& location) {
  QDomDocument description;
  description.setContent(xmlDescription);
  QDomElement elm = description.documentElement();

  LocationPlugins remotePlugins;
  QDomNodeList pluginNodes = description.elementsByTagName("plugin");

  for(int i = 0; i < pluginNodes.count(); ++i) {
    const QDomNode& child = pluginNodes.at(i);
    QDomElement childElement = child.toElement();
    const QString name = childElement.attribute("name");
    const QString type = childElement.attribute("type");
    const std::string author = childElement.attribute("author").toStdString();
    const std::string date = childElement.attribute("date").toStdString();
    const std::string info = childElement.attribute("info").toStdString();
    const std::string fileName = childElement.attribute("fileName").toStdString();
    const std::string release = childElement.attribute("release").toStdString();
    const std::string group = childElement.attribute("group").toStdString();
    const std::string tulipRelease = childElement.attribute("tulipRelease").toStdString();
    const QString folder = childElement.attribute("folder");

    std::list<tlp::Dependency> dependencies;

    for(QDomNode n = child.firstChild(); !n.isNull(); n = n.nextSibling()) {
      QDomElement dependencyElement = n.toElement();
      tlp::Dependency dep(dependencyElement.attribute("name").toStdString(), dependencyElement.attribute("type").toStdString(), dependencyElement.attribute("version").toStdString());
      dependencies.push_back(dep);
    }

    tlp::DistantPluginInfo* pluginInfo = new DistantPluginInfo(author, date, group, name.toStdString(), info, release, tulipRelease, dependencies, type, location, folder);

    remotePlugins[pluginInfo->getName().c_str()] = pluginInfo;
  }

  return remotePlugins;
}

bool PluginManager::addRemoteLocation(const QString& location) {

  QString xmlDocument(getPluginServerDescription(location));

  if(xmlDocument.isEmpty() || _remoteLocations.contains(location)) {
    return false;
  }

  QDomDocument description;
  description.setContent(xmlDocument);
  QDomElement elm = description.documentElement();

  _remoteLocations[location] = parseDescription(xmlDocument, location);
  return true;
}

void PluginManager::removeRemoteLocation(const QString& location) {
  QString xmlDocument(getPluginServerDescription(location));
  QDomDocument description;
  description.setContent(xmlDocument);
  QDomElement elm = description.documentElement();

  _remoteLocations.remove(location);
}
