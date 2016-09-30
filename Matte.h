/*
 * Matte.h
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#ifndef MATTE_H_
#define MATTE_H_
#include "Material.h"
#include "RGBColor.h"
#include "hitResult.h"
#include "World.h"
#include "Ray.h"

class Matte: public Material{

public:
	Matte(RGBColor* col, double kd);
	virtual ~Matte();
	RGBColor shade(hitResult* hitInfo, World* w, Ray* r);
	RGBColor color;
	double kd;

};

#endif /* MATTE_H_ */
