/*
 * Camera.cpp
 *
 *  Created on: 29 mars 2015
 *      Author: prisca
 */

#include "Camera.h"
#include "RGBColor.h"
#include "World.h"
#include "Ray.h"
#include <math.h>
#include <cmath>
#include "Vector3D.h"
#include <iostream>
#include <string>
using namespace std;

Camera::Camera(Point* position, Point* lookAt, Vector3D* up, int widthRes, int heightRes, float fieldOfView){
	eyePos.x = position->x;
	eyePos.y = position->y;
	this->widthRes = widthRes;
	this->heightRes = heightRes;
	planeDistance = position->distance(lookAt);
	//calculation of the coordinates system
	w = eyePos - *lookAt;
	w.normalize();
	u = (*up) ^ w;
	u.normalize();
	v = w ^ u;

	//getting the bottom left point
	halfWidth= std::abs(tan(fieldOfView/2));
	float aspectRatio = heightRes/widthRes;
	halfHeight = aspectRatio*halfWidth;
	pixelWidth = 2*halfWidth*planeDistance/((double)widthRes);
	pixelHeight = 2*halfHeight*planeDistance/((double)heightRes);
	downLeft = *lookAt - v*(halfHeight) - u*(halfWidth);
	cout << halfHeight << endl;
	cout << halfWidth << endl;
}

void Camera::render(World* w){
	Point point;
	Ray ray;
	RGBColor color;
	Vector3D vec;
	double samples = 5.0;
	Vector3D xIncVector = (u*(2*halfWidth))/(widthRes);
	Vector3D xAliasing = xIncVector/samples;
	Vector3D yIncVector = (v*(2*halfHeight))/(heightRes);
	Vector3D yAliasing = yIncVector/samples;
	for (int r = 0; r < heightRes; r++){
		for (int c = 0; c < widthRes; c++) {
			color.r = 0;
			color.g = 0;
			color.b = 0;
			for (int p = 0; p < samples; p++){
				for (int q = 0; q < samples; q++) {
					point = downLeft + xIncVector*c + yIncVector*r + xAliasing*q + yAliasing*p;
					ray.o.x = point.x;
					ray.o.y = point.y;
					ray.o.z = point.z;
					ray.d = point-eyePos;
					ray.d.normalize();
					color = color + w->traceRay(ray, 0);
				}
			}
			color = color/(samples*samples);
			w->displayPixel(r, c, color);
		}
	}
}


