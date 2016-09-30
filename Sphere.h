/*
 * Sphere.h
 *
 *  Created on: 31 mars 2015
 *      Author: prisca
 */

#ifndef SPHERE_H_
#define SPHERE_H_
#include <utility>
#include "Point.h"
#include "Normal.h"
#include "Ray.h"
#include "Object.h"
#include "Vector3D.h"
#include "hitResult.h"

class Sphere : public Object {
public:
	Sphere(Point* c, float r);
	Point center;
	float radius;
	virtual hitResult hit(Ray ray);
};

#endif /* SPHERE_H_ */
