/*
 * World.h
 *
 *  Created on: 29 mars 2015
 *      Author: prisca
 */

#ifndef WORLD_H_
#define WORLD_H_
#include "RGBColor.h"
#include "Object.h"
#include <vector>
#include "Ray.h"
#include "Vector3D.h"
#include "light.h"
using std::vector;

class Object;
class light;

class World {
public:
	World(int width, int height, double ambient);
	int w, h;
	double ambientLight;
	std::vector<Object*> objects;
	std::vector<light*> lights;
	vector<vector<vector<double> > > image;
	RGBColor traceRay(Ray r, int maxRecursive);
	void displayPixel(int r, int c, RGBColor color);
	void savebmp (const char *filename);
	void translate(Vector3D trans, std::vector<Object*> objects);
	void translate(double dx, double dy, double dz, std::vector<Object*> objects);
	void scale(double a, double b, double c, std::vector<Object*> objects);
	void rotate_x(double r, std::vector<Object*> objects);
	void rotate_y(double r, std::vector<Object*> objects);
	void rotate_z(const double r, std::vector<Object*> objects);
};

#endif /* WORLD_H_ */
