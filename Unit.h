/*
 * Imperial.h
 *
 *  Created on: Apr 18, 2019
 *      Author: s1175919
 */

#ifndef UNIT_H_
#define UNIT_H_
#include <string>
using namespace std;


class Unit{
	string unit;
	string speed;
	double windChill;
public:
	virtual string getUnit() = 0;
	virtual string getSpeed()=0;
	virtual int getWindChill(int,int)=0; //first is speed, second is temperature
};




#endif /* UNIT_H_ */
