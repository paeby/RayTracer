/*
 * light.cpp
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#include "light.h"
#include "Matrix.h"
#include "Ray.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
light::light(Vector3D* dir, Point* point, double rad, bool p) {
	direction.x = dir->x;
	direction.y = dir->y;
	direction.z = dir->z;
	direction.normalize();
	radiance = rad;
	position.x = point->x;
	position.y = point->y;
	position.z = point->z;
	this->dir = p;
	radianceTemp = rad;
}

Vector3D light::get_direction(Point p, Normal normal){
	if(dir){
		double distance = (Point(normal.x, normal.y, normal.z).distance(new Point(direction.x, direction.y, direction.z)));
		radiance = radianceTemp/(p.d_squared(&position)*(distance*distance+0.1)*0.5*distance);
		return (Vector3D(position-p)).hat();
	}
	else{return (Vector3D(position-p)).hat();}
}

bool light::inShadow(Ray* shadowRay, World* w){
	double d = position.distance(&shadowRay->o);
	Matrix* transformedMatrix;
	Ray transformedRay;
	hitResult hitInfo;
	for (std::vector<Object*>::iterator it = w->objects.begin(); it != w->objects.end(); ++it){
		transformedMatrix = (*((*(*it)->scaleMatrix->inverse())*((*it)->rotateMatrix->inverse())))*((*it)->translateMatrix->inverse());
		transformedRay.o = *transformedMatrix*(&shadowRay->o);
		transformedRay.d = (*((*(*it)->scaleMatrix->inverse())*((*it)->rotateMatrix->inverse())))*(&shadowRay->d);
		hitInfo = (*it)->hit(transformedRay);
		if(hitInfo.t > 0.0001 and (hitInfo.t < d)){
			return true;
		}
	}
	return false;
}
