/*
 * Normal.h
 *
 *  Created on: 29 mars 2015
 *      Author: prisca
 */

#ifndef NORMAL_H_
#define NORMAL_H_

#include "Matrix.h"
#include "Point.h"
#include "Vector3D.h"

class Normal {
	public:
		double	x, y, z;

		Normal(void);										// default constructor
		Normal(double a);									// constructor
		Normal(double _x, double _y, double _z);			// constructor
		Normal(const Normal& n); 							// copy constructor
		Normal(const Vector3D& v);							// constructs a normal from a vector

		Normal& 											// assignment operator
		operator= (const Normal& rhs);

		Normal& 											// assignment of a vector to a normal
		operator= (const Vector3D& rhs);

		Normal& 											// assignment of a point to a normal
		operator= (const Point& rhs);

		Normal 												// unary minus
		operator- (void) const;

		Normal 												// addition
		operator+ (const Normal& n) const;

		Normal& 											// compound addition
		operator+= (const Normal& n);

		double
		operator* (const Vector3D& v) const;				// dot product with a vector on the right

		Normal 												// multiplication by a double on the right
		operator* (const double a) const;

		void 												// convert normal to a unit normal
		normalize(void);




};




#endif



