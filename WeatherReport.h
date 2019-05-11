/*
 * WeatherReport.h
 *
 *  Created on: Apr 23, 2019
 *      Author: s1175919
 */

#ifndef WEATHERREPORT_H_
#define WEATHERREPORT_H_
#include <string>
#include "Unit.h"
#include <ctime>
using namespace std;

class WeatherReport{
	int temperature;
	int windSpeed;
	int windDirection;
	string windDirectionName;
	int windChill;



public:
	WeatherReport();
	WeatherReport(int,int,int, int);
	//GETS
	int getTemperature();
	int getWindSpeed();
	int getDirectionD();
	string getDirectionName(int); //Return name of Degree
	int getChill();


	//SETS
	void setTemperature(int);
	void setWindSpeed(int);
	void setDirectionD(int);
	void setDirectionN(string);
	void setChill(int);
;
};





#endif /* WEATHERREPORT_H_ */
