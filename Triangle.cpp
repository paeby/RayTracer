/*
 * Triangle.cpp
 *
 *  Created on: 30 mars 2015
 *      Author: prisca
 */

#include "Triangle.h"
#include "Vector3D.h"
#include <iostream>
#include <string>
using namespace std;

Triangle::Triangle(Point* a, Point* b, Point* c, bool smoothTriangle) {
	interpolated = smoothTriangle;
	p1 = a;
	p2 = b;
	p3 = c;
	n1 = Vector3D(1,0,0);
	n2 = Vector3D(0,1,0);
	n3 = Vector3D(0,0,1);
	n = (Vector3D(*p2-*p1))^(Vector3D(*p3-*p1));
	n.normalize();
	translateMatrix = new Matrix();
	scaleMatrix = new Matrix();
	rotateMatrix = new Matrix();
	transparent = false;
	transparentCoefficient = 0.0;
}

hitResult Triangle::hit(Ray ray){
	Point localHit;
	double a = p1->x - p2->x;
	double b = p1->x - p3->x;
	double c = ray.d.x;
	double d = p1->x - ray.o.x;
	double e = p1->y - p2->y;
	double f = p1->y - p3->y;
	double g = ray.d.y;
	double h = p1->y - ray.o.y;
	double i = p1->z - p2->z;
	double j = p1->z - p3->z;
	double k = ray.d.z;
	double l = p1->z - ray.o.z;
	double m = f * k - g * j;
	double nd = h * k - g * l;
	double p = f * l - h * j;
	double q = g * i - e * k;
	double s = e * j - f * i;

	double inv_denom  = 1.0 / (a * m + b * q + c * s);

	double e1 = d * m - b * nd - c * p;
	double beta = e1 * inv_denom;

	if (beta < 0.0){
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	}
	double r = e * l - h * i;
	double e2 = a * nd + d * q + c * r;
	double gamma = e2 * inv_denom;

	if (gamma < 0.0 ){
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	}

	if (beta + gamma > 1.0){
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	}

	double e3 = a * p - b * r + d * s;
	double t = e3 * inv_denom;

	if (t < 0.0001){
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	}

	if(interpolated){
		localHit = ray.o + ray.d*t;
		Normal newNormal = interpolate_normal(beta, gamma);
		return hitResult(t, &newNormal, &localHit);
	}
	else{
		localHit = ray.o + ray.d*t;
		return hitResult(t, new Normal(n.x, n.y, n.z), &localHit);
	}
}

Normal Triangle::interpolate_normal(float beta, float gamma) {
	Normal normal(n1*(1 - beta - gamma) + n2*beta + n3*gamma);
	normal.normalize();
	return normal;
}
