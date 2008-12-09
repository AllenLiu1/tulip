/*
 * GlPolyQuad.h
 *
 *  Created on: 30 oct. 2008
 *      Author: antoine
 */

#ifndef GLPOLYQUAD_H_
#define GLPOLYQUAD_H_

#include <tulip/tulipconf.h>
#include <tulip/Coord.h>
#include <tulip/Color.h>
#include <tulip/Size.h>
#include <tulip/GlSimpleEntity.h>

#include <vector>
#include <string>

using namespace std;

namespace tlp {

  /** \brief General class used to render a connected group of quadrilaterals (textured or not) that shares edges as GlEntity
   *
   * This generic class is used  to render a connected group of quadrilaterals (textured or not) that shares edges as GlEntity
   */
  class TLP_GL_SCOPE GlPolyQuad : public GlSimpleEntity {

  public :

	  /**
	   * Default Constructor for initializing an empty polyquad
	   * Use the addQuadEdge method to set the quads edges
	   *
	   * \param textureName The absolute path of the texture image file to use
	   *
	   *
	   */
	  GlPolyQuad(const string &textureName = "");

	  /**
	   * Constructor for building a polyquad with spefific colors for each edges
	   *
	   * Pay attention to the order of the edges point in the polyQuadEdges vector. Indeed, to draw the following polyquad
	   *
	   *                    v2
	   *          v0+--------+--------+ v4
	   *            |        |        |
	   *            |        |        |
	   *            |        |        |
	   *          v1+--------+--------+ v5
	   *                    v3
	   *
	   * The content of the polyQuadEdges vector should be {v0, v1, v2, v3, v4, v5} or {v1, v0, v3, v2, v5, v4}
	   *
	   * \param polyQuadEdges A vector containing the coordinates of the quad edges, its size must be  a multiple of 2 because an edge is defined by 2 points
	   * \param polyQuadEdgesColor A vector containing the edges's colors, its size must be equal to the number of edges defined by the polyQuadEdges vector
	   * \param  textureName The absolute path of the texture image file to use
	   */
	  GlPolyQuad(const vector<Coord> &polyQuadEdges, const vector<Color> &polyQuadEdgesColor, const string &textureName = "");

	  /**
	   * Constructor for building a polyquad with a single color
	   *
	   * \param polyQuadEdges A vector containing the coordinates of the quad edges, its size must be  a multiple of 2 because an edge is defined by 2 points
	   * \param polyQuadColor The polyquad color
	   * \param  textureName The absolute path of the texture image file to use
	   */
	  GlPolyQuad(const vector<Coord> &polyQuadEdges, const Color &polyQuadColor, const string &textureName = "");

	  /**
	   * Method to add a polyquad edge
	   *
	   * \param edgeStart The first end of the edge
	   * \param edgeEnd The other end of the edge
	   * \param edgeColor The edge's color
	   *
	   */
	  void addQuadEdge(const Coord &edgeStart, const Coord &edgeEnd, const Color &edgeColor);

	  /**
	   * Virtual function used to draw the polyquad.
	   */
	  void draw(float lod,Camera *camera);

	  /**
	   * Method to set the polyquad color (all edges share the same color)
	   */
	  void setColor(const Color &color);

	  /**
	   *  Method to translate entity
	   */
	  void translate(const Coord &move);

	  /**
	   * Function to export data in XML
	   */
	  void getXML(xmlNodePtr rootNode);

	  /**
	   * Function to set data with XML
	   */
	  void setWithXML(xmlNodePtr rootNode);

  private :

	  vector<Coord> polyQuadEdges; // vector which contains polyquad edges, an edge being defined by a pair of Coord
	  vector<Color> polyQuadEdgesColors; // vector which contains polyquad edges colors
	  string textureName;

  };

}
#endif /* GLPOLYQUAD_H_ */
