/*
 * station.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: s1175919
 */
#include "WeatherStation.h"
#include "WeatherReport.h"
#include "./Unit.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

WeatherStation::WeatherStation(){

}

WeatherStation::WeatherStation(string n, int h){
	stationName = n;
	history = h;
	reportList = new WeatherReport[h];
}

void WeatherStation :: addReport(WeatherReport* w){
	reportList[counter].setTemperature(w->getTemperature());
	reportList[counter].setWindSpeed(w->getWindSpeed());;
	reportList[counter].setDirectionD(w->getDirectionD());
	reportList[counter].setDirectionN(w->getDirectionName(w->getDirectionD()));
	reportList[counter].setChill(w->getChill());
	counter++;
	last++;
}

void WeatherStation :: printCurrent(Unit *u,int i,Message*m){
	cout << u->getUnit()<<reportList[i].getTemperature() << endl;
	cout << m->getPrintSpeed()<<reportList[i].getWindSpeed() << u->getSpeed()<< endl;
	cout << m->getPrintDirection()<<reportList[i].getDirectionName(reportList[i].getDirectionD()) << endl;
	cout << m->getPrintChill()<<reportList[i].getChill() <<endl;
	cout << "-----------------------"<<endl;
}

void WeatherStation :: printSummary(Unit *u,Message*m){
	int average =0;
	for(int i =0; i <last; i++){
		average =  average + reportList[i].getTemperature();
	}

	int high,low=reportList[0].getTemperature();
	for(int j=0; j<last; j++){
		if(high<reportList[j].getTemperature())
			high=reportList[j].getTemperature();
		if(low>reportList[j].getTemperature())
			low=reportList[j].getTemperature();
	}
	cout << "-----------------------"<<endl;
	cout << m->getPrintSummary() <<this->stationName<<endl;
	cout << m->getPrintAverage() <<u->getUnit() << average/this->last <<endl;
	cout << m->getPrintHigh() <<u->getUnit() << high<<endl;
	cout << m->getPrintLow() <<u->getUnit() << low<<endl;
	cout << "-----------------------" <<endl;

}



int WeatherStation ::getCounter(){
	return counter;
}
int WeatherStation ::getLast(){
	return last;
}

int WeatherStation ::getHistory(){
	return history;
}
string WeatherStation ::getName(){
	return stationName;
}
void WeatherStation ::setName(string n){
	this->stationName = n;
}
void WeatherStation ::setLast(int l){
	this->last=l;
}
void WeatherStation :: setCounter(int c){
	this->counter = c;
}
void WeatherStation :: setHistory(int h){
	this->history = h;
}
