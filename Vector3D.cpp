// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This file contains the definition of the class Vector3D

#include <math.h>    // for sqrt

#include "Vector3D.h"
#include "Normal.h"
#include "Point.h"

// ---------------------------------------------------------- default constructor

Vector3D::Vector3D(void)
	 : x(0.0), y(0.0), z(0.0)
{}

// ---------------------------------------------------------- constructor

Vector3D::Vector3D(double a)
	 : x(a), y(a), z(a)
{}

// ---------------------------------------------------------- constructor

Vector3D::Vector3D(double _x, double _y, double _z)
	: x(_x), y(_y), z(_z)
{}

// ---------------------------------------------------------- copy constructor

Vector3D::Vector3D(const Vector3D& vector)
	: x(vector.x), y(vector.y), z(vector.z)
{}


// ---------------------------------------------------------- constructor
// constructs a vector from a normal

Vector3D::Vector3D(const Normal& n)
	: x(n.x), y(n.y), z(n.z)
{}

// ---------------------------------------------------------- constructor
// constructs a vector from a point
// this is used in the ConcaveHemisphere hit functions

Vector3D::Vector3D(const Point& p)
	: x(p.x), y(p.y), z(p.z)
{}


// ---------------------------------------------------------- destructor

Vector3D::~Vector3D (void) {}



// ---------------------------------------------------------- assignment operator

Vector3D&
Vector3D::operator= (const Vector3D& rhs) {
	if (this == &rhs)
		return (*this);

	x = rhs.x; y = rhs.y; z = rhs.z;

	return (*this);
}


// ----------------------------------------------------------- assignment operator
// assign a Normal to a vector

Vector3D&
Vector3D::operator= (const Normal& rhs) {
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}


// ---------------------------------------------------------- assignment operator
// assign a point to a vector

Vector3D&
Vector3D::operator= (const Point& rhs) {
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}


// ----------------------------------------------------------  length
// length of the vector

double
Vector3D::length(void) {
	return (sqrt(x * x + y * y + z * z));
}


// ----------------------------------------------------------  normalize
// converts the vector to a unit vector

void
Vector3D::normalize() {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}


// ----------------------------------------------------------  hat
// converts the vector to a unit vector and returns the vector

Vector3D&
Vector3D::hat(void) {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}


// non-member function

// ----------------------------------------------------------  operator*
// multiplication by a matrix on the left

Vector3D
operator* (const Matrix& mat, const Vector3D& v) {
	return (Point(mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z,
					mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z,
					mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z));
}


Vector3D
Vector3D::operator- (void) const {
	return (Vector3D(-x, -y, -z));
}


// ---------------------------------------------------------------------  len_squared
// the square of the length

 double
Vector3D::len_squared(void) {
	return (x * x + y * y + z * z);
}


// ----------------------------------------------------------------------- operator*
// multiplication by a double on the right

 Vector3D
Vector3D::operator* (const double a) const {
	return (Vector3D(x * a, y * a, z * a));
}

// ----------------------------------------------------------------------- operator/
// division by a double

 Vector3D
Vector3D::operator/ (const double a) const {
	return (Vector3D(x / a, y / a, z / a));
}


// ----------------------------------------------------------------------- operator+
// addition

 Vector3D
Vector3D::operator+ (const Vector3D& v) const {
	return (Vector3D(x + v.x, y + v.y, z + v.z));
}


// ----------------------------------------------------------------------- operator-
// subtraction

 Vector3D
Vector3D::operator- (const Vector3D& v) const {
	return (Vector3D(x - v.x, y - v.y, z - v.z));
}


// ----------------------------------------------------------------------- operator*
// dot product

 double
Vector3D::operator* (const Vector3D& v) const {
	return (x * v.x + y * v.y + z * v.z);
}
 double
Vector3D::operator* (Point v) const {
	return (x * v.x + y * v.y + z * v.z);
}

// ----------------------------------------------------------------------- operator^
// cross product

 Vector3D
Vector3D::operator^ (const Vector3D& v) const {
	return (Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}


// ---------------------------------------------------------------------  operator+=
// compound addition

Vector3D&
Vector3D::operator+= (const Vector3D& v) {
	x += v.x; y += v.y; z += v.z;
	return (*this);
}




// d non-member function

// ----------------------------------------------------------------------- operator*
// multiplication by a double on the left

Vector3D 											// prototype
operator* (const double a, const Vector3D& v);

Vector3D
operator* (const double a, const Vector3D& v) {
	return (Vector3D(a * v.x, a * v.y, a * v.z));
}



// non-d non-member function

// ----------------------------------------------------------------------- operator*
// multiplication by a matrix on the left



