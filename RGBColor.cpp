/*
 * RGBColor.cpp
 *
 *  Created on: 30 mars 2015
 *      Author: prisca
 */

#include "RGBColor.h"
#include <math.h>
// -------------------------------------------------------- default constructor

RGBColor::RGBColor(void)
	: r(0.0), g(0.0), b(0.0)
{}


// -------------------------------------------------------- constructor

RGBColor::RGBColor(float c)
	: r(c), g(c), b(c)
{}


// -------------------------------------------------------- constructor

RGBColor::RGBColor(float _r, float _g, float _b)
	: r(_r), g(_g), b(_b)
{}


// -------------------------------------------------------- copy constructor

RGBColor::RGBColor(const RGBColor& c)
	: r(c.r), g(c.g), b(c.b)
{}


// -------------------------------------------------------- destructor

RGBColor::~RGBColor(void)
{}


// --------------------------------------------------------assignment operator

RGBColor&
RGBColor::operator= (const RGBColor& rhs) {
	if (this == &rhs)
		return (*this);

	r = rhs.r; g = rhs.g; b = rhs.b;

	return (*this);
}


// -------------------------------------------------------- powc
// raise each component to the specified power
// used for color filtering in Chapter 28

RGBColor
RGBColor::powc(float p) const {
	return (RGBColor(pow(r, p), pow(g, p), pow(b, p)));
}

RGBColor
operator* (const float a, const RGBColor& c) {
	return (RGBColor (a * c.r, a * c.g, a * c.b));
}


RGBColor
RGBColor::operator+ (const RGBColor& c) const {
	return (RGBColor(r + c.r, g + c.g, b + c.b));
}


// ----------------------------------------------------------------------- operator+=
// compound addition of two colors

RGBColor&
RGBColor::operator+= (const RGBColor& c) {
	r += c.r; g += c.g; b += c.b;
    return (*this);
}


// ----------------------------------------------------------------------- operator*
// multiplication by a float on the right

RGBColor
RGBColor::operator* (const float a) const {
	return (RGBColor (r * a, g * a, b * a));
}


// ----------------------------------------------------------------------- operator*=
// compound multiplication by a float on the right

RGBColor&
RGBColor::operator*= (const float a) {
	r *= a; g *= a; b *= a;
	return (*this);
}


// ----------------------------------------------------------------------- operator/
// division by float

RGBColor
RGBColor::operator/ (const float a) const {
	return (RGBColor (r / a, g / a, b / a));
}


// ----------------------------------------------------------------------- operator/=
// compound division by float

RGBColor&
RGBColor::operator/= (const float a) {
	r /= a; g /= a; b /= a;
	return (*this);
}



// ----------------------------------------------------------------------- operator*
// component-wise multiplication of two colors

RGBColor
RGBColor::operator* (const RGBColor& c) const {
	return (RGBColor (r * c.r, g * c.g, b * c.b));
}


// ----------------------------------------------------------------------- operator==
// are two RGBColors the same?

bool
RGBColor::operator== (const RGBColor& c) const {
	return (r == c.r && g == c.g && b == c.b);
}


// ----------------------------------------------------------------------- average
// the average of the three components

float
RGBColor::average(void) const {
	return (0.333333333333 * (r + g + b));
}
