INCLUDE_DIRECTORIES(${TulipCoreBuildInclude} ${TulipCoreInclude} ${TulipOGLInclude} ${GLEW_INCLUDE_DIR} ${FTGLInclude} ${FREETYPE_INCLUDE_DIRS})

MACRO(GLYPH name source)
  ADD_LIBRARY(${name}-${TulipVersion} SHARED ${source})
  TARGET_LINK_LIBRARIES(${name}-${TulipVersion} ${LibTulipCoreName} ${LibTulipOGLName})
  TULIP_INSTALL_PLUGIN(${name}-${TulipVersion} ${TulipGlyphPluginsInstallDir})
ENDMACRO(GLYPH)

MACRO(FONTGLYPH name source)
  ADD_LIBRARY(${name}-${TulipVersion} SHARED ${source})
  TARGET_LINK_LIBRARIES(${name}-${TulipVersion} ${LibTulipCoreName} ${LibTulipOGLName} ${FTGLLibrary})
  TULIP_INSTALL_PLUGIN(${name}-${TulipVersion} ${TulipGlyphPluginsInstallDir})
ENDMACRO(FONTGLYPH)

GLYPH(Cone cone.cpp)

GLYPH(Circle circle.cpp)
GLYPH(Sphere sphere.cpp)

GLYPH(Square square.cpp)
GLYPH(RoundedBox roundedbox.cpp)
GLYPH(Cube cube.cpp)

GLYPH(Window window.cpp)
GLYPH(Hexagone hexagone.cpp)
GLYPH(Triangle triangle.cpp)
GLYPH(Pentagone pentagone.cpp)
GLYPH(CubeOutlinedTransparent cubeoutlinedtransparent.cpp)
GLYPH(Ring ring.cpp)
GLYPH(Billboard billboard.cpp)
GLYPH(Cylinder cylinder.cpp)
GLYPH(ChristmasTree christmastree.cpp)
GLYPH(Diamond diamond.cpp)
GLYPH(Cross cross.cpp)
GLYPH(GlowSphere glowsphere.cpp)
GLYPH(ShadowedSphere shadowedsphere.cpp)
GLYPH(Star star.cpp)
FONTGLYPH(FontIcon fonticon.cpp)

INSTALL(FILES radialGradientTexture.png bottomShadowTexture.png leftBottomShadowTexture.png rightBottomShadowTexture.png
        DESTINATION ${TulipBitmapInstallDir}
        COMPONENT tulip_plugins)

IF(TULIP_ACTIVATE_PYTHON_WHEELS_TARGETS)
  ADD_CUSTOM_TARGET(copyGlyphTextures ALL
    ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/radialGradientTexture.png ${TULIPGUI_PYTHON_FOLDER}/share/bitmaps/radialGradientTexture.png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/bottomShadowTexture.png ${TULIPGUI_PYTHON_FOLDER}/share/bitmaps/bottomShadowTexture.png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/leftBottomShadowTexture.png ${TULIPGUI_PYTHON_FOLDER}/share/bitmaps/leftBottomShadowTexture.png
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/rightBottomShadowTexture.png ${TULIPGUI_PYTHON_FOLDER}/share/bitmaps/rightBottomShadowTexture.png    )
  ADD_DEPENDENCIES(tulip-gui-wheel copyGlyphTextures)
ENDIF(TULIP_ACTIVATE_PYTHON_WHEELS_TARGETS)
