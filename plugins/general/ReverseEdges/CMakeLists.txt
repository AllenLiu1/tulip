CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(PLUGIN_NAME ReverseEdges)

INCLUDE_DIRECTORIES(${TulipCoreBuildInclude} ${TulipCoreInclude} ${TulipGUIInclude})

SET(PLUGIN_SRCS
 ReverseEdges.cpp
)

ADD_LIBRARY(${PLUGIN_NAME}-${TulipVersion} SHARED ${PLUGIN_SRCS})
TARGET_LINK_LIBRARIES(${PLUGIN_NAME}-${TulipVersion} ${LibTulipCoreName})

TULIP_INSTALL_PLUGIN(${PLUGIN_NAME}-${TulipVersion} ${TulipPluginsInstallDir})

