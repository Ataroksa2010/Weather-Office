/*
 * Imperial.cpp
 *
 *  Created on: Apr 18, 2019
 *      Author: s1175919
 */


#include "Imperial.h"
#include "math.h"

Imperial :: Imperial(){
	unit = "Fahrenheit: ";
	speed = " MPH";
}

string Imperial::getUnit(){
	return unit;
}
string Imperial::getSpeed(){
	return speed;
}
int Imperial::getWindChill(int s, int t){
	return 35.74 + (0.6215*(t)) - (35.75*(pow(s,0.16))) + (0.4275*(t)*(pow(s,0.16)));
}


