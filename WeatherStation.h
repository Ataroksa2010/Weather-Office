/*
 * station.h
 *
 *  Created on: Apr 9, 2019
 *      Author: s1175919
 */

#ifndef WEATHERSTATION_H_
#define WEATHERSTATION_H_
#include <string>
#include "WeatherReport.h"
#include "./Unit.h"
#include "./Message.h"
using namespace std;

class WeatherStation{
	string stationName;
	int history;
	WeatherReport *reportList;
	int counter = 0;
	int last =0;

public:
	WeatherStation();
	WeatherStation(string,int);
	void addReport(WeatherReport*);
	void printCurrent(Unit*,int,Message*);
	void printSummary(Unit*,Message*);
	//GETS
	int getLast();
	int getCounter();
	int getHistory();
	string getName();
	//SETS
	void setLast(int);
	void setCounter(int);
	void setHistory(int);
	void setName(string);
};


#endif /* WEATHERSTATION_H_ */
