/*
 * hitResult.cpp
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#include "hitResult.h"

hitResult::hitResult(){
	t = 0;
}

hitResult::hitResult(double tInt, Normal* n, Point* p) {
	t = tInt;
	normal.x = n->x;
	normal.y = n->y;
	normal.z = n->z;
	intersectPoint.x = p->x;
	intersectPoint.y = p->y;
	intersectPoint.z = p->z;

}
void hitResult::operator= (hitResult copy){
	t = copy.t;
	normal.x = copy.normal.x;
	normal.y = copy.normal.y;
	normal.z = copy.normal.z;
	intersectPoint.x = copy.intersectPoint.x;
	intersectPoint.y = copy.intersectPoint.y;
	intersectPoint.z = copy.intersectPoint.z;
}
hitResult::~hitResult() {
	// TODO Auto-generated destructor stub
}

