#ifndef RGBCOLOR_H_
#define RGBCOLOR_H_


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


//------------------------------------------------------------ class RGBColor

class RGBColor {

	public:

		float	r, g, b;

	public:

		RGBColor(void);										// default constructor
		RGBColor(float c);									// constructor
		RGBColor(float _r, float _g, float _b);				// constructor
		RGBColor(const RGBColor& c); 						// copy constructor

		~RGBColor(void);									// destructor

		RGBColor& 											// assignment operator
		operator= (const RGBColor& rhs);

		RGBColor 											// addition
		operator+ (const RGBColor& c) const;

		RGBColor& 											// compound addition
		operator+= (const RGBColor& c);

		RGBColor 											// multiplication by a float on the right
		operator* (const float a) const;

		RGBColor& 											// compound multiplication by a float on the right
		operator*= (const float a);

		RGBColor 											// division by a float
		operator/ (const float a) const;

		RGBColor& 											// compound division by a float
		operator/= (const float a);

		RGBColor 											// component-wise multiplication
		operator* (const RGBColor& c) const;

		bool												// are two RGBColours the same?
		operator== (const RGBColor& c) const;

		RGBColor											// raise components to a power
		powc(float p) const;

		float												// the average of the components
		average(void) const;



};

#endif

