/*
 * office.h
 *
 *  Created on: Apr 9, 2019
 *      Author: s1175919
 */

#ifndef WEATHEROFFICE_H_
#define WEATHEROFFICE_H_
#include <string>
#include "Message.h"
#include "WeatherStation.h"
#include "WeatherReport.h"
#include "./Unit.h"

using namespace std;

class WeatherOffice{
	string officeName;
	int selector;
	int officeLast = 0;
	WeatherStation *stationList;
	int stationTotal=0;
public:
	WeatherOffice(string);
	void addStation(WeatherStation*);
	void selectStation(int); //change the station currently working
	void printStationList();
	int getLastOffice();
	void stationAddReport(WeatherReport*,int);
	void stationPrintFull(Unit*,int,int);
};

#endif

