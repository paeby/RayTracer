/*
 * Camera.h
 *
 *  Created on: 29 mars 2015
 *      Author: prisca
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "Matrix.h"
#include <vector>
#include "Point.h"
#include "Vector3D.h"
#include "World.h"

class Camera {
public:
	//w and h represent the resolution
	Camera(Point* pos, Point* lookAt, Vector3D* up, int w, int h, float fieldOfView);
	//u v and w is the system of coordinates of the camera and up is the vector of the world that is in the direction of the top
	Vector3D up;
	Vector3D u;
	Vector3D v;
	Vector3D w;
	Point eyePos;
	int widthRes, heightRes, halfWidth, halfHeight;
	//Point that we have to increment by width and height to get the image
	Point downLeft;
	//Width and height incrementation for the view plane
	double pixelWidth, pixelHeight;
	double planeDistance;
	//Method creating the primary rays
	void render(World* world);
};

#endif /* CAMERA_H_ */
