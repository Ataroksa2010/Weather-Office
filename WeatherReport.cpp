/*
 * WeatherReport.cpp
 *
 *  Created on: Apr 18, 2019
 *      Author: s1175919
 */
#include "WeatherReport.h"
#include <ctime>
WeatherReport :: WeatherReport(){

}

WeatherReport :: WeatherReport(int t, int s, int d, int u){
	temperature= t;
	windSpeed=s;
	windDirection=d;
	windChill = u;
}

	//GET FUNCTIONS

int WeatherReport::getTemperature(){
	return this->temperature;
}
int WeatherReport::getWindSpeed(){
	return this->windSpeed;
}
int WeatherReport::getDirectionD(){
	return this->windDirection;
}
int WeatherReport::getChill(){
	return this->windChill;
}
	//SET FUNCTIONS:
void WeatherReport::setTemperature(int t){
	this->temperature = t;
}
void WeatherReport::setWindSpeed(int s){
	this->windSpeed = s;
}
void WeatherReport::setDirectionD(int d){
	this->windDirection = d;
}
void WeatherReport::setDirectionN(string d){
	this->windDirectionName = d;
}
void WeatherReport::setChill(int u){
	this->windChill = u;
}
string WeatherReport :: getDirectionName(int d){
string direction;
	if(d >= 0 && d < 45)
		direction = "north";
	else if(d >= 45 && d <90)
		direction = "north east";
	else if(d >= 90 && d <135)
		direction = "east";
	else if(d >= 135&& d < 180)
		direction = "south east";
	else if(d >= 180&& d < 225)
		direction = "south";
	else if(d >= 225&& d < 270)
		direction = "south west";
	else if(d >= 270&& d < 315)
		direction = "west";
	else if(d >= 315&& d < 360)
		direction = "north west";
	else
		direction = "Invalid Direction";
	return direction;
}
