/*
 * Triangle.h
 *
 *  Created on: 30 mars 2015
 *      Author: prisca
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "Object.h"
#include <utility>
#include "Point.h"
#include "Normal.h"
#include "Ray.h"
#include "hitResult.h"

class Triangle : public Object {
public:
	Triangle(Point* a, Point* b, Point* c, bool smoothTriangle);
	bool interpolated;
	Normal interpolate_normal(float beta, float gamma);
	Point* p1;
	Point* p2;
	Point* p3;
	Normal n;
	Normal n1;
	Normal n2;
	Normal n3;
	hitResult hit(Ray ray);
};

#endif /* TRIANGLE_H_ */
