/*
 * Material.h
 *
 *  Created on: 30 mars 2015
 *      Author: prisca
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_
#include "hitResult.h"
#include "RGBColor.h"
#include "Ray.h"
#include "World.h"
class World;
class hitResult;
class ray;
class RGBColor;


class Material {
public:
	Material(void);
	virtual ~Material (void);
	virtual RGBColor shade(hitResult* hitInfo, World* w, Ray* ray){
		return RGBColor(0,0,0);
	}
};

#endif /* MATERIAL_H_ */
