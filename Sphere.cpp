/*
 * Sphere.cpp
 *
 *  Created on: 31 mars 2015
 *      Author: prisca
 */

#include "Sphere.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

Sphere::Sphere(Point* p, float r) {
	center.x = p->x;
	center.y = p->y;
	center.z = p->z;
	radius = r;
	translateMatrix = new Matrix();
	scaleMatrix = new Matrix();
	rotateMatrix = new Matrix();
	transparent = false;
	transparentCoefficient = 0.0;
}

hitResult Sphere::hit(Ray ray){
	double t;
	Normal normal;
	Vector3D temp = ray.o - center;
	double a = ray.d*ray.d;
	double b = (temp*2.0)*ray.d;
	double c = temp * temp - radius * radius;
	double disc	= b * b - 4.0 * a * c;
	Point localHit;

	if (disc < 0.0){
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	}
	else {
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;
		if (t > 0.0001) {
			normal = ((temp + ray.d*t) / radius);
			normal.normalize();
			localHit = ray.o + ray.d*t;
			return hitResult(t, &normal, &localHit);
		}

		t = (-b + e) / denom;

		if (t > 0.0001) {
			normal = ((temp + ray.d*t) / radius);
			normal.normalize();
			localHit = ray.o + ray.d*t;
			return hitResult(t, &normal, &localHit);
		}
	}
	return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
}
