/*
 * main.cpp
 *
 *  Created on: 31 mars 2015
 *      Author: prisca
 */
#include "Camera.h"
#include "World.h"
#include "Point.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Vector3D.h"
#include "RGBColor.h"
#include "Plane.h"
#include "Normal.h"
#include "light.h"
#include "Matte.h"
#include "Specular.h"
#include <iostream>
#include <string>
#include "DOFCamera.h"
using namespace std;

int main( int argc, const char* argv[] )
{
	Camera* cam = new Camera(new Point(0,0,0), new Point(0,0,20), new Vector3D(0,1,0), 100, 100, 3.0);
	//DOFCamera* cam = new DOFCamera(new Point(0,0,0), new Point(0,0,20), new Vector3D(0,1,0), 300, 300, 3.0, 80.0, 2.0);
	World* w = new World(100,100, 0.2);
	light* l1 = new light(new Vector3D(1,0,0), new Point(-99999,0,0), 5, false);
	light* l2 = new light(new Vector3D(0,0,1), new Point(0,0,0), 5000.0, true);
	light* l3 = new light(new Vector3D(0,0,0), new Point(-20,-30,30), 2.0, false);
	w->lights.push_back(l1);
	w->lights.push_back(l2);
	w->lights.push_back(l3);
	Object* sphere = new Sphere(new Point(0,0,80), 10);
	Object* sphere2 = new Sphere(new Point(-30,0,80), 10);
	Object* sphere4 = new Sphere(new Point(30,0,80), 10);
	Object* sphere3 = new Sphere(new Point(20,0,50), 10);
	Object* triangle = new Triangle(new Point(-50, -50, 30), new Point(50,-50,30), new Point(0,-50,350), true);
	sphere->material = new Specular(new RGBColor(0,1,0), 0.6, 0.4, 4.0);
	sphere2->material = new Specular(new RGBColor(1,0,0), 0.6, 0.4, 4.0);
	sphere4->material = new Specular(new RGBColor(0,1,1), 0.6, 0.4, 4.0);
	//sphere->material = new Matte(new RGBColor(0,1,0), 0.8);
	//sphere2->material = new Matte(new RGBColor(0,1,1), 0.7);
	//sphere3->material = new Matte(new RGBColor(1,0,0.5), 0.7);
	//sphere4->material = new Matte(new RGBColor(1,1,0), 0.9);
	triangle->material = new Matte(new RGBColor(1,0,0), 0.5);
	sphere3->material = new Specular(new RGBColor(1,0,0.5), 0.8, 0.3, 10.0);
	//sphere2->rotate_z(0.2);
	//sphere2->scale(1.0,2.0,1.0);
	//sphere2->translate(-10.0,20.0,0.0);
	w->objects.push_back(sphere);
	w->objects.push_back(sphere2);
	w->objects.push_back(sphere4);
	//w->objects.push_back(sphere4);
	w->objects.push_back(triangle);
	cam->render(w);
	w->savebmp("image.ppm");
}





