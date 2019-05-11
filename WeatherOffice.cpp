/*
 * office.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: s1175919
 */
#include "WeatherOffice.h"
#include "WeatherStation.h"
#include "WeatherReport.h"

#include <iostream>


WeatherOffice :: WeatherOffice(string n){
	officeName = n;
	stationList = new WeatherStation[12];
	selector = 0;
	stationTotal++;
}
void WeatherOffice :: addStation(WeatherStation* s){
	stationList[officeLast].setName(s->getName());
	stationList[officeLast].setCounter(s->getCounter());
	stationList[officeLast].setHistory(s->getHistory());
	stationList[officeLast].setLast(s->getLast());
	officeLast++;
}
int WeatherOffice :: getLastOffice(){
	return officeLast;
}
void WeatherOffice :: printStationList(){
	for(int i = 0; i<officeLast;i++){
		cout<<i<<". "<<stationList[i].getName()<<endl;
	}
}
void WeatherOffice :: selectStation(int s){
	selector = s-1;
}
void WeatherOffice :: stationAddReport(WeatherReport* r,int i){//The Program Crash when this is executed..
	stationList[i].addReport(r);
}
void WeatherOffice ::stationPrintFull(Unit* u, int station, int i){//The Program Crash when this is executed..
	//stationList[station].printCurrent(u,i);
}


