/*
 * Plane.cpp
 *
 *  Created on: 30 mars 2015
 *      Author: prisca
 */

#include "Plane.h"
#include "Vector3D.h"
#include <utility>
#include "Normal.h"
#include "hitResult.h"

Plane::Plane(Point* point, Normal* nor) {
	this->p.x = point->x;
	this->p.y = point->y;
	this->p.z = point->z;
	n.x = nor->x;
	n.y = nor->y;
	n.z = nor->z;
	n.normalize();
	translateMatrix = new Matrix();
	scaleMatrix = new Matrix();
	rotateMatrix = new Matrix();
	transparent = false;
	transparentCoefficient = 0.0;
}

hitResult Plane::hit(Ray ray){
	double d = n*p;

	if (d == 0) {
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	}

	double t = (d - (Vector3D(n.x,n.y,n.z)*ray.o)) / (Vector3D(n.x,n.y,n.z)*ray.d);

	Vector3D newRay = ray.d*t;

	Point contact = ray.o + newRay;

	if (t >= 0.0 && t <= 1.0) {
		t = Vector3D(n.x,n.y,n.z)*(ray.o-p);
		return hitResult(t, new Normal(n.x,n.y,n.z), &contact);
	}
	else{
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	}
}

