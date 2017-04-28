/**
 *
 * This file is part of Tulip (www.tulip-software.org)
 *
 * Authors: David Auber and the Tulip development Team
 * from LaBRI, University of Bordeaux
 *
 * Tulip is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * Tulip is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 */
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <ctime>

#include <tulip/ExportModule.h>
#include <tulip/Graph.h>
#include <tulip/GraphProperty.h>
#include <tulip/TlpTools.h>
#include <tulip/MutableContainer.h>
#include <tulip/StringCollection.h>
#include <tulip/TulipRelease.h>
#include <tulip/PropertyTypes.h>

#define TLP_FILE_VERSION "2.3"

using namespace std;
using namespace tlp;

static string convert(const string &tmp) {
  string newStr;

  for (unsigned int i = 0; i < tmp.length(); ++i) {
    if (tmp[i] == '\"')
      newStr += "\\\"";
    else if (tmp[i] == '\n')
      newStr += "\\n";
    else if (tmp[i] == '\\')
      newStr += "\\\\";
    else
      newStr += tmp[i];
  }

  return newStr;
}

static const char *paramHelp[] = {
    // name
    "Name of the graph being exported.",

    // author
    "Authors",

    // comments
    "Description of the graph."};

namespace tlp {
/**
 * This plugin records a Tulip graph structure in a file using the TLP format.
 * TLP is the Tulip Software Graph Format.
 * See 'Tulip-Software.org->Docs->TLP File Format' for description.
 */
class TLPExport : public ExportModule {
public:
  PLUGININFORMATION("TLP Export", "Auber David", "31/07/2001", "Exports a graph in a file using the TLP format (Tulip Software Graph "
                                                               "Format).<br/>See <b>tulip-software.org->Framework->TLP File Format</b> for "
                                                               "description.",
                    "1.1", "File")

  string fileExtension() const {
    return "tlp";
  }

  DataSet controller;
  int progress;

  TLPExport(tlp::PluginContext *context) : ExportModule(context), progress(0) {
    addInParameter<string>("name", paramHelp[0], "");
    addInParameter<string>("author", paramHelp[1], "");
    addInParameter<string>("text::comments", paramHelp[2], "This file was generated by Tulip.");
  }
  //=====================================================
  ~TLPExport() {
  }
  //=====================================================
  std::string icon() const {
    return ":/tulip/gui/icons/logo32x32.png";
  }
  //====================================================
  inline node getNode(node n) {
    return node(graph->nodePos(n));
  }
  //====================================================
  inline edge getEdge(edge e) {
    return edge(graph->edgePos(e));
  }
  //=====================================================
  void saveGraphElements(ostream &os, Graph *g) {
    pluginProgress->setComment("Saving Graph Elements");
    pluginProgress->progress(progress, g->numberOfEdges() + g->numberOfNodes());

    if (g->getSuperGraph() != g) {
      os << "(cluster " << g->getId() << endl;
      if (inGuiTestingMode())
        g->sortElts();
      const std::vector<node> &nodes = g->nodes();
      unsigned int nbNodes = nodes.size();
      const std::vector<edge> &edges = g->edges();
      unsigned int nbEdges = edges.size();
      node beginNode, previousNode;
      unsigned int progupdate = 1 + (nbNodes + nbEdges) / 100;

      if (nbNodes) {
        os << "(nodes";

        for (unsigned int i = 0; i < nbNodes; ++i) {
          if (progress % progupdate == 0)
            pluginProgress->progress(progress, nbNodes + nbEdges);

          ++progress;
          node current = getNode(nodes[i]);

          if (!beginNode.isValid()) {
            beginNode = previousNode = current;
            os << " " << beginNode.id;
          } else {
            if (current.id == previousNode.id + 1) {
              previousNode = current;

              if (i == nbNodes - 1)
                os << ".." << current.id;
            } else {
              if (previousNode != beginNode) {
                os << ".." << previousNode.id;
              }

              os << " " << current.id;
              beginNode = previousNode = current;
            }
          }
        }

        os << ")" << endl;
      }

      edge beginEdge, previousEdge;
      if (nbEdges) {
        os << "(edges";

        for (unsigned int i = 0; i < nbEdges; ++i) {
          if (progress % progupdate == 0)
            pluginProgress->progress(progress, nbNodes + nbEdges);

          ++progress;
          edge current = getEdge(edges[i]);

          if (!beginEdge.isValid()) {
            beginEdge = previousEdge = current;
            os << " " << beginEdge.id;
          } else {
            if (current.id == previousEdge.id + 1) {
              previousEdge = current;

              if (i == nbEdges - 1)
                os << ".." << current.id;
            } else {
              if (previousEdge != beginEdge) {
                os << ".." << previousEdge.id;
              }

              os << " " << current.id;
              beginEdge = previousEdge = current;
            }
          }
        }

        os << ")" << endl;
      }
    } else {
      unsigned int nbElts = g->numberOfNodes();

      os << "(nb_nodes " << nbElts << ")" << endl;

      os << ";(nodes <node_id> <node_id> ...)" << endl;

      switch (nbElts) {
      case 0:
        os << "(nodes)" << endl;
        break;

      case 1:
        os << "(nodes 0)" << endl;
        break;

      case 2:
        os << "(nodes 0 1)" << endl;
        break;

      default:
        os << "(nodes 0.." << nbElts - 1 << ")" << endl;
      }

      nbElts = g->numberOfEdges();
      os << "(nb_edges " << nbElts << ")" << endl;

      os << ";(edge <edge_id> <source_id> <target_id>)" << endl;
      unsigned int progupdate = 1 + nbElts / 100;
      const std::vector<edge> &edges = g->edges();
      for (unsigned i = 0; i < nbElts; ++i) {
        if (progress % progupdate == 0)
          pluginProgress->progress(progress, nbElts);

        ++progress;
        edge e = edges[i];
        const pair<node, node> &ends = g->ends(e);
        os << "(edge " << i << " " << getNode(ends.first).id << " " << getNode(ends.second).id << ")";

        if (i != nbElts - 1)
          os << endl;
      }

      os << endl;
    }

    Iterator<Graph *> *itS = g->getSubGraphs();

    while (itS->hasNext())
      saveGraphElements(os, itS->next());

    delete itS;

    if (g->getSuperGraph() != g)
      os << ")" << endl;
  }
  //=====================================================
  void saveLocalProperties(ostream &os, Graph *g) {
    pluginProgress->setComment("Saving Graph Properties");
    progress = 0;
    Iterator<PropertyInterface *> *itP = nullptr;

    if (g->getSuperGraph() == g) {
      itP = g->getObjectProperties();
    } else {
      itP = g->getLocalObjectProperties();
    }

    int nonDefaultvaluatedElementCount = 1;

    while (itP->hasNext()) {
      PropertyInterface *prop = itP->next();

      Iterator<node> *itN = prop->getNonDefaultValuatedNodes(g);

      while (itN->hasNext()) {
        ++nonDefaultvaluatedElementCount;
        itN->next();
      }

      delete itN;

      Iterator<edge> *itE = prop->getNonDefaultValuatedEdges(g);

      while (itE->hasNext()) {
        ++nonDefaultvaluatedElementCount;
        itE->next();
      }

      delete itE;
    }

    delete itP;

    if (g->getSuperGraph() == g) {
      itP = g->getObjectProperties();
    } else {
      itP = g->getLocalObjectProperties();
    }

    PropertyInterface *prop;

    while (itP->hasNext()) {
      prop = itP->next();
      stringstream tmp;
      tmp << "Saving Property [" << prop->getName() << "]";
      pluginProgress->setComment(tmp.str());

      if (g->getSuperGraph() == g) {
        os << "(property "
           << " 0 " << prop->getTypename() << " ";
      } else {
        os << "(property "
           << " " << g->getId() << " " << prop->getTypename() << " ";
      }

      os << "\"" << convert(prop->getName()) << "\"" << endl;
      string nDefault = prop->getNodeDefaultStringValue();
      string eDefault = prop->getEdgeDefaultStringValue();

      bool isPathViewProp = (prop->getName() == string("viewFont") || prop->getName() == string("viewTexture"));

      // replace real path with symbolic one using TulipBitmapDir
      if (isPathViewProp && !TulipBitmapDir.empty()) {
        size_t pos = nDefault.find(TulipBitmapDir);

        if (pos != string::npos)
          nDefault.replace(pos, TulipBitmapDir.size(), "TulipBitmapDir/");

        pos = eDefault.find(TulipBitmapDir);

        if (pos != string::npos)
          eDefault.replace(pos, TulipBitmapDir.size(), "TulipBitmapDir/");
      }

      os << "(default \"" << convert(nDefault) << "\" \"" << convert(eDefault) << "\")" << endl;
      Iterator<node> *itN = prop->getNonDefaultValuatedNodes(g);

      while (itN->hasNext()) {
        if (progress % (1 + nonDefaultvaluatedElementCount / 100) == 0)
          pluginProgress->progress(progress, nonDefaultvaluatedElementCount);

        ++progress;
        node itn = itN->next();
        string tmp = prop->getNodeStringValue(itn);

        // replace real path with symbolic one using TulipBitmapDir
        if (isPathViewProp && !TulipBitmapDir.empty()) {
          size_t pos = tmp.find(TulipBitmapDir);

          if (pos != string::npos)
            tmp.replace(pos, TulipBitmapDir.size(), "TulipBitmapDir/");
        } else if (g->getId() != 0 && // if it is not the real root graph
                   prop->getTypename() == GraphProperty::propertyTypename) {
          unsigned int id = strtoul(tmp.c_str(), nullptr, 10);
          // we must check if the pointed subgraph
          // is a descendant of the currently export graph
          if (!graph->getDescendantGraph(id))
            continue;
        }
        os << "(node " << getNode(itn).id << " \"" << convert(tmp) << "\")" << endl;
      }

      delete itN;

      Iterator<edge> *itE = prop->getNonDefaultValuatedEdges(g);

      if (prop->getTypename() == GraphProperty::propertyTypename) {
        while (itE->hasNext()) {
          if (progress % (1 + nonDefaultvaluatedElementCount / 100) == 0)
            pluginProgress->progress(progress, nonDefaultvaluatedElementCount);

          ++progress;

          // for GraphProperty we must ensure the reindexing
          // of embedded edges
          edge ite = itE->next();
          const set<edge> &edges = ((GraphProperty *)prop)->getEdgeValue(ite);
          set<edge> rEdges;
          set<edge>::const_iterator its;

          for (its = edges.begin(); its != edges.end(); ++its) {
            rEdges.insert(getEdge(*its));
          }

          // finally save the vector
          os << "(edge " << getEdge(ite).id << " \"";
          EdgeSetType::write(os, rEdges);
          os << "\")" << endl;
        }
      } else {
        while (itE->hasNext()) {
          if (progress % (1 + nonDefaultvaluatedElementCount / 100) == 0)

            pluginProgress->progress(progress, nonDefaultvaluatedElementCount);

          ++progress;
          edge ite = itE->next();
          // replace real path with symbolic one using TulipBitmapDir
          string tmp = prop->getEdgeStringValue(ite);

          if (isPathViewProp && !TulipBitmapDir.empty()) {
            size_t pos = tmp.find(TulipBitmapDir);

            if (pos != string::npos)
              tmp.replace(pos, TulipBitmapDir.size(), "TulipBitmapDir/");
          }

          os << "(edge " << getEdge(ite).id << " \"" << convert(tmp) << "\")" << endl;
        }
      }

      delete itE;
      os << ")" << endl;
    }

    delete itP;
  }
  //=====================================================
  void saveProperties(ostream &os, Graph *g) {
    saveLocalProperties(os, g);
    Iterator<Graph *> *itS = g->getSubGraphs();

    while (itS->hasNext())
      saveProperties(os, itS->next());

    delete itS;
  }
  //=====================================================
  void saveAttributes(ostream &os, Graph *g) {
    const DataSet &attributes = g->getAttributes();

    if (!attributes.empty()) {

      // If nodes and edges are stored as graph attributes
      // we need to update their id before serializing them
      // as nodes and edges have been reindexed
      pair<string, DataType *> attribute;
      forEach(attribute, attributes.getValues()) {
        if (attribute.second->getTypeName() == string(typeid(node).name())) {
          node *n = reinterpret_cast<node *>(attribute.second->value);
          n->id = getNode(*n).id;
        } else if (attribute.second->getTypeName() == string(typeid(edge).name())) {
          edge *e = reinterpret_cast<edge *>(attribute.second->value);
          e->id = getEdge(*e).id;
        } else if (attribute.second->getTypeName() == string(typeid(vector<node>).name())) {
          vector<node> *vn = reinterpret_cast<vector<node> *>(attribute.second->value);

          for (size_t i = 0; i < vn->size(); ++i) {
            (*vn)[i].id = getNode((*vn)[i]).id;
          }
        } else if (attribute.second->getTypeName() == string(typeid(vector<edge>).name())) {
          vector<edge> *ve = reinterpret_cast<vector<edge> *>(attribute.second->value);

          for (size_t i = 0; i < ve->size(); ++i) {
            (*ve)[i].id = getEdge((*ve)[i]).id;
          }
        }
      }

      if (g->getSuperGraph() == g) {
        os << "(graph_attributes 0 ";
      } else {
        os << "(graph_attributes " << g->getId() << " ";
      }

      DataSet::write(os, attributes);
      os << ")" << endl;
    }

    // save subgraph attributes
    Iterator<Graph *> *itS = g->getSubGraphs();

    while (itS->hasNext())
      saveAttributes(os, itS->next());

    delete itS;
  }
  //=====================================================
  void saveController(ostream &os, DataSet &data) {
    os << "(controller ";
    DataSet::write(os, data);
    os << ")" << endl;
  }

  bool exportGraph(ostream &os) {

    // change graph parent in hierarchy temporarily to itself as
    // it will be the new root of the exported hierarchy
    Graph *superGraph = graph->getSuperGraph();
    graph->setSuperGraph(graph);

    string format(TLP_FILE_VERSION);

    string name;
    string author;
    string comments = "This file was generated by Tulip.";

    if (dataSet != nullptr) {
      dataSet->get("name", name);
      dataSet->get("author", author);
      dataSet->get("text::comments", comments);
    }

    if (name.length() > 0)
      graph->setAttribute("name", name);

    // get ostime
    time_t ostime = time(nullptr);
    // get local time
    struct tm *currTime = localtime(&ostime);
    // format date
    char currDate[32];
    strftime(currDate, 32, "%m-%d-%Y", currTime);

    // output tlp format version
    os << "(tlp \"" << format.c_str() << '"' << endl;
    // current date
    os << "(date \"" << currDate << "\")" << endl;

    // author
    if (author.length() > 0)
      os << "(author \"" << author << "\")" << endl;

    // comments
    os << "(comments \"" << comments << "\")" << endl;

    saveGraphElements(os, graph);
    saveProperties(os, graph);
    saveAttributes(os, graph);

    // Save views
    if (dataSet != nullptr && dataSet->get<DataSet>("controller", controller))
      saveController(os, controller);

    os << ')' << endl; // end of (tlp ...

    // restore original parent in hierarchy
    graph->setSuperGraph(superGraph);
    return true;
  }
};
PLUGIN(TLPExport)
} // namespace tlp
