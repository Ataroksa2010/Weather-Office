/*
 * Metric.h
 *
 *  Created on: Apr 23, 2019
 *      Author: s1175919
 */

#ifndef METRIC_H_
#define METRIC_H_
#include "./Unit.h"

class Metric: public Unit{
	string unit;
	string speed;
public:
	Metric();
	int getWindChill(int,int);
	string getUnit();
	string getSpeed();
};



#endif /* METRIC_H_ */
