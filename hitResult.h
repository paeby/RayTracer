/*
 * hitResult.h
 *
 *  Created on: 2 mai 2015
 *      Author: prisca
 */

#ifndef HITRESULT_H_
#define HITRESULT_H_
#include "Point.h"
#include "Normal.h"

class hitResult {
public:
	hitResult();
	hitResult(double tInt, Normal* n, Point* p);
	void operator= (hitResult copy);
	virtual ~hitResult();
	double t;
	Normal normal;
	Point intersectPoint;
};

#endif /* HITRESULT_H_ */
