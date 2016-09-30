/*
 * DOFCamera.h
 *
 *  Created on: 5 mai 2015
 *      Author: prisca
 */

#ifndef DOFCAMERA_H_
#define DOFCAMERA_H_
#include "Matrix.h"
#include <vector>
#include "Point.h"
#include "Vector3D.h"
#include "World.h"

class DOFCamera {
public:
	//w and h represent the resolution
	DOFCamera(Point* pos, Point* lookAt, Vector3D* up, int w, int h, double fieldOfView, double focalLength, double lensRadius);
	//u v and w is the system of coordinates of the camera and up is the vector of the world that is in the direction of the top
	Vector3D up;
	Vector3D u;
	Vector3D v;
	Vector3D w;
	Point eyePos;
	int widthRes, heightRes, halfWidth, halfHeight;
	double focalLength;
	double lensRadius;
	double planeDistance;
	//Point that we have to increment by width and height to get the image
	Point downLeft;
	//Width and height incrementation for the view plane
	double pixelWidth, pixelHeight;
	//Method creating the primary rays
	void render(World* world);
	void getDirection(Point* pixelPoint, Point* lensPoint);
	Point randomLensPoint();
};

#endif /* DOFCAMERA_H_ */
