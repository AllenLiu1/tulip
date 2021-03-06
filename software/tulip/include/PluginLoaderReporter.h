/**
 *
 * This file is part of Tulip (http://tulip.labri.fr)
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
#ifndef PLUGINLOADERREPORTER_H
#define PLUGINLOADERREPORTER_H

#include <tulip/PluginLoader.h>
#include <QMap>
#include <QString>

class PluginLoaderReporter : public tlp::PluginLoader {
public:
  PluginLoaderReporter();

  void start(const std::string &) override {}
  void numberOfFiles(int) override {}
  void loading(const std::string &) override {}
  void loaded(const tlp::Plugin *, const std::list<tlp::Dependency> &) override {}
  void aborted(const std::string &, const std::string &) override;
  void finished(bool, const std::string &) override {}

  QMap<QString, QString> errors() {
    return _errors;
  }

private:
  QMap<QString, QString> _errors;
};

#endif // PLUGINLOADERREPORTER_H
