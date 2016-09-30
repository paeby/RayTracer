/*
 * Plane.h
 *
 *  Created on: 30 mars 2015
 *      Author: prisca
 */

#ifndef PLANE_H_
#define PLANE_H_
#include <utility>
#include "Object.h"
#include "Normal.h"
#include "Point.h"
#include "Ray.h"
#include "hitResult.h"

class Plane : public Object {
public:
	Plane(Point* p, Normal* n);
	Point p;
	Normal n;
	hitResult hit(Ray ray);
};

#endif /* PLANE_H_ */
