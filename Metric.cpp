/*
 * Metric.cpp
 *
 *  Created on: Apr 18, 2019
 *      Author: s1175919
 */


#include "Metric.h"
#include "math.h"

Metric :: Metric(){
	unit = "Celsius: ";
	speed= " KPH";
}

string Metric::getUnit(){
	return unit;
}
string Metric::getSpeed(){
	return speed;
}
int Metric::getWindChill(int s, int t){
	return  13.12 + (0.6215*(t)) - (11.37*(pow(s,0.16))) + (0.3965*(t)*(pow(s,0.16)));
}

