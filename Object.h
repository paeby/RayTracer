/*
 * Object.h
 *
 *  Created on: 30 mars 2015
 *      Author: prisca
 */

#ifndef OBJECT_H_
#define OBJECT_H_
#include "RGBColor.h"
#include "Material.h"
#include "Ray.h"
#include <utility>
#include "Normal.h"
#include "Vector3D.h"
#include <utility>
#include "Normal.h"
#include "hitResult.h"
#include "Material.h"
class Material;

class Object {

public:
	Object();
	virtual ~Object();
	RGBColor color;
	Material* material;
	//it returns the distance to the plane
	virtual hitResult hit(Ray ray){
		return hitResult(-1, new Normal(0,0,0), new Point(0,0,0));
	};
	Matrix* translateMatrix;
	Matrix* scaleMatrix;
	Matrix* rotateMatrix;
	void translate(Vector3D trans);
	void translate(double dx, double dy, double dz);
	void scale(double a, double b, double c);
	void rotate_x(double r);
	void rotate_y(double r);
	void rotate_z(const double r);
	bool transparent;
	double transparentCoefficient;
};
#endif /* OBJECT_H_ */
