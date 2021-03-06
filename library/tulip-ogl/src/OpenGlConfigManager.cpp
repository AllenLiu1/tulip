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

#include <GL/glew.h>

#include <tulip/OpenGlConfigManager.h>
#include <tulip/ParallelTools.h>

#include <iostream>
#include <sstream>

//====================================================
tlp::OpenGlConfigManager *tlp::OpenGlConfigManager::inst = nullptr;

using namespace std;

namespace tlp {

OpenGlConfigManager &OpenGlConfigManager::getInst() {
  TLP_LOCK_SECTION(OpenglConfigManagerInited) {
    if (!inst)
      inst = new OpenGlConfigManager();
  }
  TLP_UNLOCK_SECTION(OpenglConfigManagerInited);
  return *inst;
}

OpenGlConfigManager::OpenGlConfigManager() : glewIsInit(false), antialiased(true) {}

void OpenGlConfigManager::initExtensions() {
  if (!glewIsInit) {
    glewExperimental = true;
    glewIsInit = (glewInit() == GLEW_OK);
  }
}

string OpenGlConfigManager::getOpenGLVersionString() const {
  return reinterpret_cast<const char *>(glGetString(GL_VERSION));
}

double OpenGlConfigManager::getOpenGLVersion() const {
  double ret = 0;
  std::istringstream iss(getOpenGLVersionString()); //.substr(0,3));
  iss >> ret;
  return ret;
}

string OpenGlConfigManager::getOpenGLVendor() const {
  return string(reinterpret_cast<const char *>(glGetString(GL_VENDOR)));
}

bool OpenGlConfigManager::isExtensionSupported(const string &extensionName) {
  if (!glewIsInit)
    return false;

  bool supported = false;
  TLP_LOCK_SECTION(OpenGlConfigManagerExtensionSupported) {
    auto it = checkedExtensions.find(extensionName);
    if (it == checkedExtensions.end()) {
      supported = checkedExtensions[extensionName] =
          (glewIsSupported(extensionName.c_str()) == GL_TRUE);
    } else
      supported = it->second;
  }
  TLP_UNLOCK_SECTION(OpenGlConfigManagerExtensionSupported);
  return supported;
}

bool OpenGlConfigManager::hasVertexBufferObject() {
  return isExtensionSupported("GL_ARB_vertex_buffer_object");
}

void OpenGlConfigManager::activateAntiAliasing() {
  if (antialiased) {
    glEnable(GL_MULTISAMPLE);
  }
}

void OpenGlConfigManager::desactivateAntiAliasing() {
  glDisable(GL_MULTISAMPLE);
}

void OpenGlConfigManager::activateLineAndPointAntiAliasing() {
  if (antialiased) {
    glDisable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  }
}

void OpenGlConfigManager::desactivateLineAndPointAntiAliasing() {
  if (antialiased) {
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_POINT_SMOOTH);
  }
}

void OpenGlConfigManager::activatePolygonAntiAliasing() {
  if (antialiased) {
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_MULTISAMPLE);
  }
}

void OpenGlConfigManager::desactivatePolygonAntiAliasing() {
  if (antialiased) {
    glDisable(GL_MULTISAMPLE);
  }
}

int OpenGlConfigManager::maxNumberOfSamples() const {
  static int maxSamples = -1;

  if (maxSamples < 0)
    glGetIntegerv(GL_MAX_SAMPLES, &maxSamples);

  return maxSamples / 4;
}
} // namespace tlp
