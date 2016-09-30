/*
 * Object.cpp
 *
 *  Created on: 31 mars 2015
 *      Author: prisca
 */

#include "Object.h"
#include "Matrix.h"
#include <math.h>

Object::Object() {
	translateMatrix = new Matrix();
	scaleMatrix = new Matrix();
	rotateMatrix = new Matrix();
	transparent = false;
	transparentCoefficient = 0.0;
	material = new Material();
}

void Object::translate(Vector3D trans){
	Matrix* translation = new Matrix();
	translation->m[0][3] = trans.x;
	translation->m[1][3] = trans.y;
	translation->m[2][3] = trans.z;
    translateMatrix = *translation * translateMatrix;
}

void Object::translate(double dx, double dy, double dz){
	Matrix* translation = new Matrix();
	translation->m[0][3] = dx;
	translation->m[1][3] = dy;
	translation->m[2][3] = dz;
	translateMatrix = *translation * translateMatrix;
}

void Object::scale(double a, double b, double c){
	Matrix* scale = new Matrix();
	scale->m[0][0] = a;
	scale->m[1][1] = b;
	scale->m[2][2] = c;
	scaleMatrix = *scale * scaleMatrix;
}
void Object::rotate_x(double r){
	Matrix* rot = new Matrix();
	rot->m[1][1] = cos(r);
	rot->m[1][2] = -sin(r);
	rot->m[2][1] = sin(r);
	rot->m[2][2] = cos(r);
	rotateMatrix = *rot * rotateMatrix;
}
void Object::rotate_y(double r){
	Matrix* rot = new Matrix();
	rot->m[0][0] = cos(r);
	rot->m[0][2] = sin(r);
	rot->m[2][0] = -sin(r);
	rot->m[2][2] = cos(r);
	rotateMatrix = *rot * rotateMatrix;
}

void Object::rotate_z(const double r){
	Matrix* rot = new Matrix();
	rot->m[0][0] = cos(r);
	rot->m[0][1] = -sin(r);
	rot->m[1][0] = sin(r);
	rot->m[1][1] = cos(r);
	rotateMatrix = *rot * rotateMatrix;
}

Object::~Object(){

}
