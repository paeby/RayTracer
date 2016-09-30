// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// this file contains the definition of the class Point

#include <math.h>
#include "Point.h"


// --------------------------------------------- default constructor

Point::Point()
	:x(0), y(0), z(0)
{}


// --------------------------------------------- constructor

Point::Point(const double a)
	:x(a), y(a), z(a)
{}

// --------------------------------------------- constructor

Point::Point(const double a, const double b, const double c)
	:x(a), y(b), z(c)
{}


// --------------------------------------------- copy constructor

Point::Point(const Point* p)

{x=p->x; y=p->y; z=p->z;}


// --------------------------------------------- destructor

Point::~Point()
{}


// --------------------------------------------- assignment operator

Point&
Point::operator= (const Point* rhs) {


	x = rhs->x; y = rhs->y; z = rhs->z;

	return (*this);
}



// --------------------------------------------- distance
// distance between two points

double
Point::distance(const Point* p) const {
	return (sqrt(		(x - p->x) * (x - p->x)
					+ 	(y - p->y) * (y - p->y)
					+	(z - p->z) * (z - p->z) ));
}


// non-member function

// --------------------------------------------- operator*
// multiplication by a matrix on the left

Point
operator* (const Matrix* mat, const Point p) {
	return (Point(mat->m[0][0] * p.x + mat->m[0][1] * p.y + mat->m[0][2] * p.z + mat->m[0][3],
					mat->m[1][0] * p.x + mat->m[1][1] * p.y + mat->m[1][2] * p.z + mat->m[1][3],
					mat->m[2][0] * p.x + mat->m[2][1] * p.y + mat->m[2][2] * p.z + mat->m[2][3]));
}

Point
operator* (double a, const Point p) {
	return (Point(a * p.x, a * p.y, a * p.z));
}

// -------------------------------------------------------------- operator-
// unary minus

Point
Point::operator- (void) const {
	return (Point(-x, -y, -z));
}

Point
Point::operator- (Point p) const {
	return (Point(this->x-p.x, this->y-p.y, this->z-p.z));
}

// -------------------------------------------------------------- operator-
// the vector that joins two points

Vector3D
Point::operator- (const Point* p) const {
	return (Vector3D(x - p->x,y - p->y,z - p->z));
}

double
Point::operator* (const Vector3D v) const {
	return v.x*this->x + v.y*this->y + v.z*this->z;
}

// -------------------------------------------------------------- operator+
// addition of a vector to a point that returns a new point

Point
Point::operator+ (const Vector3D& v) const {
	return (Point(x + v.x, y + v.y, z + v.z));
}


// -------------------------------------------------------------- operator-
// subtraction of a vector from a point that returns a new point

Point
Point::operator- (const Vector3D& v) const {
	return (Point(x - v.x, y - v.y, z - v.z));
}


// -------------------------------------------------------------- operator*
// mutliplication by a double on the right

Point
Point::operator* (const double a) const {
	return (Point(x * a,y * a,z * a));
}


// -------------------------------------------------------------- d_squared
// the square of the distance between the two points as a member function

double
Point::d_squared(const Point* p) const {
	return (	(x - p->x) * (x - p->x)
			+ 	(y - p->y) * (y - p->y)
			+	(z - p->z) * (z - p->z) );
}

Point
Point::operator= (Point* rhs) {
	x = rhs->x;
	y = rhs->y;

	return (*this);
}


