#ifndef RAY_H_
#define RAY_H_


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Point.h"
#include "Vector3D.h"

class Ray {
	public:

		Point o;  	// origin
		Vector3D d; 		// direction

		Ray(void);

		Ray(Point origin, Vector3D dir);

		Ray(const Ray& ray);

		Ray&
		operator= (const Ray& rhs);

		~Ray(void);

		int reflexions;
};

#endif

