/*
 * Specular.cpp
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#include "Specular.h"
#include <math.h>

Specular::Specular(RGBColor* col, double kd, double kr, double e) {
	this->kd = kd;
	this->kr = kr;
	color.r = col->r;
	color.g = col->g;
	color.b = col->b;
	this->e = e;
}

Specular::~Specular() {
}

RGBColor Specular::shade(hitResult* hitInfo, World* w, Ray* r) {
	//phong illumination on the object
	RGBColor L = phong(hitInfo, w, r);
	Vector3D minRay = -r->d;
	double ndotwo = hitInfo->normal * minRay;
	Vector3D reflectedDir = r->d + hitInfo->normal * ndotwo * 2.0;
	Ray reflected_ray = Ray(hitInfo->intersectPoint, reflectedDir);
	reflected_ray.reflexions = r->reflexions + 1;
	RGBColor fr = (color*kr / fabs((hitInfo->normal * reflectedDir)));
	L += fr * w->traceRay(reflected_ray, reflected_ray.reflexions) * (hitInfo->normal * reflectedDir);
	return (L);
}

RGBColor Specular::phong(hitResult* hitInfo, World* w, Ray* r){
	Vector3D viewDirection = -r->d;
	RGBColor L = color*w->ambientLight;
	int num_lights = w->lights.size();
	for (int j = 0; j < num_lights; j++){
		Vector3D lightDirection = w->lights[j]->get_direction(hitInfo->intersectPoint, hitInfo->normal);
		double lightOnSurface = hitInfo->normal * lightDirection;
		if(lightOnSurface > 0.0){
			if(! (w->lights[j]->inShadow(new Ray(hitInfo->intersectPoint, lightDirection), w))){
				Vector3D mirror = Vector3D(-lightDirection + hitInfo->normal * lightOnSurface * 2.0);
				double phongSurface = mirror * viewDirection;
				RGBColor spec;
				if(phongSurface > 0.0){
					spec = RGBColor(1,1,1)* kr * pow(phongSurface, e);
				}
				L +=  (color*kd*0.318309 + spec)*(w->lights[j]->radiance)*lightOnSurface;
			}
		}
	}
	return L;
}
