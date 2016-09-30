/*
 * light.h
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#ifndef LIGHT_H_
#define LIGHT_H_
#include "hitResult.h"
#include "Vector3D.h"
#include "RGBColor.h"
#include "Point.h"
#include "Ray.h"
#include "World.h"
#include "hitResult.h"
#include "World.h"
class World;
class light {
public:
	light(Vector3D* dir, Point* position, double rad, bool direction);
	bool inShadow(Ray* shadowRay, World* w);
	Vector3D get_direction(Point p, Normal normal);
	Vector3D direction;
	double radiance;
	double radianceTemp;
	bool dir;
	Point position;
};

#endif /* LIGHT_H_ */
