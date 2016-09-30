/*
 * DOFCamera.cpp
 *
 *  Created on: 5 mai 2015
 *      Author: prisca
 */

#include "Matrix.h"
#include <vector>
#include "Point.h"
#include "Vector3D.h"
#include "DOFCamera.h"
#include "Normal.h"
#include "RGBColor.h"
#include "World.h"
#include "Ray.h"
#include <math.h>
#include <cmath>
#include "Vector3D.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
DOFCamera::DOFCamera(Point* pos, Point* lookAt, Vector3D* up, int width, int height, double fieldOfView, double focalLength, double lensRadius){
	eyePos.x = pos->x;
	eyePos.y = pos->y;
	this->focalLength = focalLength;
	this->planeDistance = pos->distance(lookAt);
	this->lensRadius = lensRadius;
	this->widthRes = width;
	this->heightRes = height;
	//calculation of the coordinates system
	w = eyePos - *lookAt;
	w.normalize();
	u = (*up) ^ w;
	u.normalize();
	v = w ^ u;

	//getting the bottom left point
	halfWidth= std::abs(tan(fieldOfView/2));
	double aspectRatio = heightRes/widthRes;
	halfHeight = aspectRatio*halfWidth;
	pixelWidth = 2*halfWidth*planeDistance/((double)widthRes);
	pixelHeight = 2*halfHeight*planeDistance/((double)heightRes);
	downLeft = *lookAt - v*(halfHeight) - u*(halfWidth);
	cout << downLeft.x << endl;
	cout << downLeft.y << endl;
}

void DOFCamera::render(World* w){
	Point point;
	Point lensPoint;
	Ray ray;
	RGBColor color;
	Vector3D vec;
	double samples = 2.0;
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
					//the sample pixel on the viewplane that is taken randomly from the square of one pixel
					point = downLeft + xIncVector*c + yIncVector*r + xAliasing*(rand()%(int)samples) + yAliasing*(rand()%(int)samples);
					// we will take a sample point on the unit square disk and then adapt it to our lens (it is taken randomly around the point of the eye)
					lensPoint = randomLensPoint();
					//the point on the focal plane:
					Point focalPoint = point*(focalLength/planeDistance);
					//the direction is the point on the focal plane minus the point on the lens
					ray.d = focalPoint-lensPoint;
					ray.o = lensPoint;
					color = color + w->traceRay(ray, 0);
				}
			}
			color = color/(samples*samples);
			w->displayPixel(r, c, color);
		}
	}
}

Point DOFCamera::randomLensPoint(){
	double r, phi; // polar coordinates
	Point sp;
	r =  (rand()) / (RAND_MAX/lensRadius);
	phi = (rand()) / (RAND_MAX/(2.0*3.1415926535897932));
	sp.x = eyePos.x +  r * cos(phi);
	sp.y = eyePos.y + r * sin(phi);
	return sp;
}
