#ifndef POINT_H_
#define POINT_H_


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Matrix.h"
#include "Vector3D.h"
class Vector3D;
class Point {
	public:

		double x, y, z;

		Point();													// default constructor
		Point(const double a);									// constructor
		Point(const double a, const double b, const double c);	// constructor
		Point(const Point* p);									// copy constructor
		~Point();													// destructor

		Point& 													// assignment operator
		operator= (const Point* p);

		Point
		operator- (Point p) const ;

		Point 													// unary minus
		operator- (void) const;

		Vector3D 													// vector joining two points
		operator- (const Point* p) const;

		Point 													// addition of a vector
		operator+ (const Vector3D& v) const;

		Point 													// subtraction of a vector
		operator- (const Vector3D& v) const;

		double
		operator* (const Vector3D v) const;

		Point 													// multiplication by a double on the right
		operator* (const double a) const;

		double														// square of distance bertween two points
		d_squared(const Point* p) const;

		double														// distance bewteen two points
		distance(const Point* p) const;

		Point
		operator= (Point* rhs);
};


#endif

