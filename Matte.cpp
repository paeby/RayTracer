/*
 * Matte.cpp
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#include "Matte.h"
#include "Vector3D.h"
#include "RGBColor.h"

Matte::Matte(RGBColor* col, double k) {
	kd = k;
	color.r = col->r;
	color.g = col->g;
	color.b = col->b;
}

RGBColor
Matte::shade(hitResult* hitInfo, World* w, Ray* r) {
	RGBColor L = color * w->ambientLight;
	int num_lights = w->lights.size();
	for (int j = 0; j < num_lights; j++) {
		Vector3D lightDirection = w->lights[j]->get_direction(hitInfo->intersectPoint, hitInfo->normal);
		double lightOnSurface = hitInfo->normal * lightDirection;
		if (lightOnSurface > 0.0){
			if(! (w->lights[j]->inShadow(new Ray(hitInfo->intersectPoint, lightDirection), w))){
				//inverse PI
				L += (color * 0.3183098*kd) * w->lights[j]->radiance * lightOnSurface;
			}
		}
	}
	return (L);
}
Matte::~Matte(){}
