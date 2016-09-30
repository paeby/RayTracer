/*
 * Specular.h
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#ifndef SPECULAR_H_
#define SPECULAR_H_

#include "Material.h"
#include "RGBColor.h"
#include "hitResult.h"
#include "World.h"
#include "Ray.h"
class RGBColor;
class World;
class hitResult;
class ray;

class Specular: public Material {
public:
	Specular(RGBColor* col, double kd, double kr, double e);
	virtual ~Specular();
	RGBColor shade(hitResult* hitInfo, World* w, Ray* r);
	RGBColor sample_f(hitResult* hitInfo, Vector3D* wo, Vector3D* wi);
	RGBColor phong(hitResult* hitInfo, World* w, Ray* r);
	RGBColor color;
	double kd;
	double kr; //reflexion coefficient
	double e; //specular exponent
};

#endif /* SPECULAR_H_ */
