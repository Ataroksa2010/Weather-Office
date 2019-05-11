/*
 * Imperial.h
 *
 *  Created on: Apr 23, 2019
 *      Author: s1175919
 */

#ifndef IMPERIAL_H_
#define IMPERIAL_H_
#include "./Unit.h"

class Imperial : public Unit{
	string unit;
	string speed;
public:
	Imperial();
	int getWindChill(int,int);
	string getUnit();
	string getSpeed();
};




#endif /* IMPERIAL_H_ */
