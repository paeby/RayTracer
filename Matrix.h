/*
 * Matrix.h
 *
 *  Created on: 29 mars 2015
 *      Author: prisca
 */
#ifndef MATRIX_H_
#define MATRIX_H_

#include "Point.h"
#include "Vector3D.h"
#include "Normal.h"
class Vector3D;
class Point;
class Normal;

class Matrix {

	public:
		double	m[4][4];								// elements
		Matrix(void);									// default constructor
		Matrix(const Matrix& mat);						// copy constructor
		Matrix* operator= (const Matrix* rhs);			// assignment operator
		Matrix* operator* ( Matrix* mat) ;		// multiplication of two matrices
		Matrix operator/ (const double d);				// divsion by a double
		void set_identity(void);						// set to the identity matrix
		Matrix* inverse();
		Point operator* (const Point* p);
		Vector3D operator* (const Vector3D* vec);
		Normal operator* (const Normal* vec);
};

#endif /* MATRIX_H_ */
