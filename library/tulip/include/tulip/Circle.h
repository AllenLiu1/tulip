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
#ifndef TLP_GEO_CIRCLE_H
#define TLP_GEO_CIRCLE_H

#include <vector>
#include <tulip/Vector.h>
namespace tlp {
/**
 * \addtogroup basic
 */
/*@{*/
/**
 * \brief class for circle
 *
 * Enables to both create and manipulate a circle
 *
 * \author David Auber auber@tulip-software.org
 * \version 0.0.1 24/01/2003
 */
template<typename Obj>
struct Circle : public Vector<Obj,2> {
  Circle() {}
  Circle(const Vector<Obj,2> &pos, Obj radius):Vector<Obj,2>(pos),radius(radius) {}
  Circle(const Circle &c):Vector<Obj,2>(c),radius(c.radius) {}
  Circle(Obj x,Obj y,Obj radius):radius(radius) {
    (*this)[0]=x;
    (*this)[1]=y;
  }
  /**
   * Translate "this" by vector v
   */
  void translate(const Vector<Obj,2> &v) {
    (*this)+=v;
  }
  /**
   * Merges this circle with another circle; merging operation
   * consists in computing the smallest enclosing circle of the
   * two circle and to store the result in "this".
   */
  Circle<Obj>& merge(const Circle<Obj> &c);
  /**
   * Radius of the circle
   */
  Obj radius;
  /**
   * Returns true if the circle is include in an other circle, false otherwise.
   */
  bool isIncludeIn(const Circle<Obj> & circle) const;
};

/**
 * Give the instersction of two circles, return false if no intersection exist else put the two points in p1 & p2,
 * if there is only one solution p1 == p2;
 */
template<typename Obj>
bool intersection(const Circle<Obj> &c1, const Circle<Obj> &c2,  Vector<Obj,2> &p1,  Vector<Obj,2> &p2) {
  double d2 =  (c2[0]-c1[0]) * (c2[0]-c1[0]) + (c2[1]-c1[1]) * (c2[1]-c1[1]);

  if (sqrt(d2) > c1.radius + c2.radius) return false;

  if (c1.isIncludeIn(c2)) return false;

  if (c2.isIncludeIn(c1)) return false;

  double K = (1./4.) * sqrt(((c1.radius+c2.radius)*(c1.radius+c2.radius)- d2)*(d2 - (c1.radius-c2.radius)*(c1.radius-c2.radius)));
  p1[0] = (1./2.)*(c2[0] + c1[0]) + (1./2.)*(c2[0]-c1[0])*(c1.radius*c1.radius - c2.radius*c2.radius)/d2 +  2.*(c2[1]-c1[1]) * K/d2;
  p1[1] = (1./2.)*(c2[1] + c1[1]) + (1./2.)*(c2[1]-c1[1])*(c1.radius*c1.radius - c2.radius*c2.radius)/d2 +  2.*(c2[0]-c1[0]) * K/d2;
  p2[0] = (1./2.)*(c2[0] + c1[0]) + (1./2.)*(c2[0]-c1[0])*(c1.radius*c1.radius - c2.radius*c2.radius)/d2 -  2.*(c2[1]-c1[1]) * K/d2;
  p2[1] = (1./2.)*(c2[1] + c1[1]) + (1./2.)*(c2[1]-c1[1])*(c1.radius*c1.radius - c2.radius*c2.radius)/d2 -  2.*(c2[0]-c1[0]) * K/d2;
  return true;
}

/**
 * Compute the optimum enclosing circle of 2 circles.
 */
template<typename Obj>
Circle<Obj> enclosingCircle(const Circle<Obj> &,const Circle<Obj> &);

/**
 * Compute the optimum enclosing circle of a set of circles.
 */
template<typename Obj>
Circle<Obj> enclosingCircle(const std::vector< Circle<Obj> > & circles);
/**
 * Compute an enclosing circle of a set of circles,
 * this algorithm is an aproximation of the smallest
 * enclosing circle.
 */
template<typename Obj>
Circle<Obj> lazyEnclosingCircle(const std::vector< Circle<Obj> > & circles);
/**
 * Write circle in a stream
 */
template<typename Obj>
std::ostream& operator<<(std::ostream &os,const Circle<Obj> &);
/*@}*/
}

#include "cxx/Circle.cxx"
#endif
