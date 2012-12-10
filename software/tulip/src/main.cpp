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
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 */

#include <QtCore/QLocale>
#include <QtCore/QProcess>
#include <QtCore/QDir>

#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include <QtGui/QDesktopServices>
#include <QtNetwork/QTcpSocket>

#include <tulip/PluginLister.h>
#include <tulip/PluginLibraryLoader.h>
#include <tulip/TlpTools.h>
#include <tulip/TlpQtTools.h>
#include <tulip/TulipSettings.h>
#include <tulip/PluginManager.h>
#include <tulip/QuaZIPFacade.h>
#include <tulip/TlpQtTools.h>

#include <CrashHandling.h>

#include "TulipMainWindow.h"
#include "PluginLoaderReporter.h"
#include "PluginLoaderDispatcher.h"
#include "TulipSplashScreen.h"
#include "PluginsCenter.h"
#include "FormPost.h"
#include <tulip/SystemDefinition.h>

#if defined(__APPLE__)
#include <sys/types.h>
#include <signal.h>
#endif

#ifdef interface
#undef interface
#endif

void sendUsageStatistics() {
  QNetworkAccessManager* mgr = new QNetworkAccessManager;
  QObject::connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
  mgr->get(QNetworkRequest(QUrl(QString("http://tulip.labri.fr/TulipStats/tulip_stats.php?tulip=") + TULIP_RELEASE + "&os=" + OS_PLATFORM)));
}

bool sendAgentMessage(int port, const QString& message) {
  bool result = true;

  QTcpSocket sck;
  sck.connectToHost(QHostAddress::LocalHost,port);
  sck.waitForConnected(1000);

  if (sck.state() == QAbstractSocket::ConnectedState) {
    sck.write(message.toUtf8());
    sck.flush();
  }
  else {
    result = false;
  }

  sck.close();
  return result;
}

void checkTulipRunning(const QString& perspName, const QString& fileToOpen) {
  QFile lockFile(QDir(QDesktopServices::storageLocation(QDesktopServices::TempLocation)).filePath("tulip.lck"));

  if (lockFile.exists() && lockFile.open(QIODevice::ReadOnly)) {
    QString agentPort = lockFile.readAll();
    bool ok;
    int n_agentPort = agentPort.toInt(&ok);

    if (ok && sendAgentMessage(n_agentPort,"SHOW_AGENT\tPROJECTS")) {
      // if a file was passed as argument, forward it to the running instance
      if (!fileToOpen.isNull()) { // open the file passed as argument
        if (!perspName.isNull()) {
          sendAgentMessage(n_agentPort,"OPEN_PROJECT_WITH\t" + perspName + "\t" + fileToOpen);
        }
        else {
          sendAgentMessage(n_agentPort,"OPEN_PROJECT\t" + fileToOpen);
        }
      }
      else if (!perspName.isNull()) { // open the perspective passed as argument
        sendAgentMessage(n_agentPort,"CREATE_PERSPECTIVE\t" + perspName);
      }

      exit(0);
    }
  }

  lockFile.close();
  lockFile.remove();
}

int main(int argc, char **argv) {
  start_crash_handler();
  QApplication tulip_agent(argc, argv);
  tulip_agent.setApplicationName("tulip");

  // Parse arguments
  QRegExp perspectiveRegexp("^\\-\\-perspective=(.*)");
  QString perspName;
  QString fileToOpen;

  for(int i=1; i<QApplication::arguments().size(); ++i) {
    QString s = QApplication::arguments()[i];

    if (perspectiveRegexp.exactMatch(s)) {
      perspName = perspectiveRegexp.cap(1);
    }
    else {
      fileToOpen = s;
    }
  }

  checkTulipRunning(perspName,fileToOpen);
  sendUsageStatistics();

  PluginLoaderDispatcher *dispatcher = new PluginLoaderDispatcher();
  TulipSplashScreen *splashScreen = new TulipSplashScreen();
  PluginLoaderReporter *errorReport = new PluginLoaderReporter();
  dispatcher->registerLoader(errorReport);
  dispatcher->registerLoader(splashScreen);
  tlp::initTulipSoftware(dispatcher,true);
  delete dispatcher;
  delete splashScreen;

  // Main window
  TulipMainWindow *mainWindow = TulipMainWindow::instance();
  mainWindow->pluginsCenter()->reportPluginErrors(errorReport->errors());
  delete errorReport;

  mainWindow->show();

  // Treat arguments
  if (!fileToOpen.isNull()) { // open the file passed as argument
    if (!perspName.isNull())
      mainWindow->openProjectWith(fileToOpen,perspName);
    else
      mainWindow->openProject(fileToOpen);
  }
  else if (!perspName.isNull()) { // open the perspective passed as argument
    mainWindow->createPerspective(perspName);
  }

  int result = tulip_agent.exec();

#ifdef MEMORYCHECKER_ON
  memory_checker_print_report();
#endif // MEMORYCHECKER_ON

  QFile f(QDir(QDesktopServices::storageLocation(QDesktopServices::TempLocation)).filePath("tulip.lck"));
  f.remove();

  return result;
}
