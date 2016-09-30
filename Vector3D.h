#ifndef VECTOR3D_H_
#define VECTOR3D_H_

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Matrix.h"

class Normal;
class Point;

//----------------------------------------- class Vector3D

class Vector3D {
	public:

		double	x, y, z;

	public:

		Vector3D(void);											// default constructor
		Vector3D(double a);										// constructor
		Vector3D(double _x, double _y, double _z);				// constructor
		Vector3D(const Vector3D& v);							// copy constructor
		Vector3D(const Normal& n);								// constructs a vector from a Normal
		Vector3D(const Point& p);								// constructs a vector from a point

		~Vector3D (void);										// destructor

		Vector3D& 												// assignment operator
		operator= (const Vector3D& rhs);

		Vector3D& 												// assign a Normal to a vector
		operator= (const Normal& rhs);

		Vector3D& 												// assign a Point to a vector
		operator= (const Point& rhs);

		Vector3D												// unary minus
		operator- (void) const;

		double													// length
		length(void);

		double													// square of the length
		len_squared(void);

		Vector3D												// multiplication by a double on the right
		operator* (const double a) const;

		Vector3D												// division by a double
		operator/ (const double a) const;

		Vector3D												// addition
		operator+ (const Vector3D& v) const;

		Vector3D& 												// compound addition
		operator+= (const Vector3D& v);

		Vector3D												// subtraction
		operator- (const Vector3D& v) const;

		double 													// dot product
		operator* (const Vector3D& b) const;

		Vector3D 												// cross product
		operator^ (const Vector3D& v) const;

		void 													// convert vector to a unit vector
		normalize(void);

		Vector3D& 												// return a unit vector, and normalize the vector
		hat(void);

		double
		operator* (Point v) const;

};

#endif



