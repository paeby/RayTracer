/*
 * World.cpp

 *
 *  Created on: 29 mars 2015
 *      Author: prisca
 */

#include "World.h"
#include "Object.h"
#include "Normal.h"
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "RGBColor.h"
#include <cmath>
#include "hitResult.h"

using namespace std;

World::World(int width, int height, double ambient) {
	w = width;
	h = height;
	ambientLight = ambient;
	image.resize(height);
	for (int i = 0; i < height; ++i) {
		image[i].resize(width);
	    for (int j = 0; j < width; ++j){
	    	image[i][j].resize(3);
	    }
	}
}

RGBColor World::traceRay(Ray r, int depth){
	double tmin = 10000000;
	RGBColor color;
	Ray transformedRay;
	transformedRay.reflexions = depth;
	Matrix* transformedMatrix;
	hitResult hitInfo;
	hitResult hitNearest;
	Object* nearestObject = new Object();

	if (depth == 3){
		return RGBColor(0,0,0);
	}

	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		//if the object has been scaled, translated or rotated we check the intersection
		//with the object and the ray that has to be transformed by the inversed matrices of the
		//translation, rotation and scale.
		transformedMatrix = (*((*(*it)->scaleMatrix->inverse())*((*it)->rotateMatrix->inverse())))*((*it)->translateMatrix->inverse());
		transformedRay.o = *transformedMatrix*(&r.o);
		transformedRay.d = (*((*(*it)->scaleMatrix->inverse())*((*it)->rotateMatrix->inverse())))*(&r.d);
		hitInfo = (*it)->hit(transformedRay);
		if((hitInfo.t != -1) and (hitInfo.t < tmin)){
			tmin = hitInfo.t;
			hitNearest = hitInfo;
			hitNearest.intersectPoint = *((*((*(*it)->translateMatrix)*((*it)->rotateMatrix)))*((*it)->scaleMatrix))*&hitInfo.intersectPoint;
			hitNearest.normal = (*((*(*it)->rotateMatrix)*((*it)->scaleMatrix->inverse())))*(&hitInfo.normal);
		    hitNearest.normal.normalize();
			delete nearestObject;
			nearestObject = *it;
		}
	}
	return nearestObject->material->shade(&hitNearest, this, &r);
}

void World::displayPixel(int r, int c, RGBColor color){
	double max_value = max(color.r, max(color.g, color.b));
	RGBColor adjustedColor;
	if(max_value > 1.0){
		adjustedColor = color/max_value;
	}
	else{
		adjustedColor = color;
	}
	image[r][c][0] = adjustedColor.r;
	image[r][c][1] = adjustedColor.g;
	image[r][c][2] = adjustedColor.b;
}


void World::translate(Vector3D trans, std::vector<Object*> objects){
	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		(*it)->translate(trans);
	}
}

void World::translate(double dx, double dy, double dz, std::vector<Object*> objects){
	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		(*it)->translate(dx, dy, dz);
	}
}

void World::scale(double a, double b, double c, std::vector<Object*> objects){
	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		(*it)->scale(a, b, c);
	}
}

void World::rotate_x(double r, std::vector<Object*> objects){
	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		(*it)->rotate_x(r);
	}
}

void World::rotate_y(double r, std::vector<Object*> objects){
	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		(*it)->rotate_y(r);
	}
}

void World::rotate_z(const double r, std::vector<Object*> objects){
	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		(*it)->rotate_z(r);
	}
}


void World::savebmp (const char *filename) {
	FILE *f;
	int k = w*h;
	int s = 4*k;
	int filesize = 54 + s;

	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = 72*m;

	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

	bmpfileheader[ 2] = (unsigned char)(filesize);
	bmpfileheader[ 3] = (unsigned char)(filesize>>8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);

	bmpinfoheader[ 4] = (unsigned char)(w);
	bmpinfoheader[ 5] = (unsigned char)(w>>8);
	bmpinfoheader[ 6] = (unsigned char)(w>>16);
	bmpinfoheader[ 7] = (unsigned char)(w>>24);

	bmpinfoheader[ 8] = (unsigned char)(h);
	bmpinfoheader[ 9] = (unsigned char)(h>>8);
	bmpinfoheader[10] = (unsigned char)(h>>16);
	bmpinfoheader[11] = (unsigned char)(h>>24);

	bmpinfoheader[21] = (unsigned char)(s);
	bmpinfoheader[22] = (unsigned char)(s>>8);
	bmpinfoheader[23] = (unsigned char)(s>>16);
	bmpinfoheader[24] = (unsigned char)(s>>24);

	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm>>8);
	bmpinfoheader[27] = (unsigned char)(ppm>>16);
	bmpinfoheader[28] = (unsigned char)(ppm>>24);

	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm>>8);
	bmpinfoheader[31] = (unsigned char)(ppm>>16);
	bmpinfoheader[32] = (unsigned char)(ppm>>24);

	f = fopen(filename,"wb");

	fwrite(bmpfileheader,1,14,f);
	fwrite(bmpinfoheader,1,40,f);

	double red, green, blue;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++){
			red = (int)((image[i][j][0])*255);
			green = (int)((image[i][j][1])*255);
			blue = (int)((image[i][j][2])*255);
			unsigned char color[3] = {(int)(blue),(int)(green),(int)(red)};

					fwrite(color,1,3,f);
		}

	}

	fclose(f);
}

