/*
 * English.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: s1175919
 */
#include "English.h"

const char *English::getWelcome(){
	return "Welcome! n/Enter 1 for English, or anything else for Binary";
}
const char *English::getOfficeName(){
	return "Please Enter the Office's Name: ";
}
const char *English::getStationName(){
	return "Please Enter the Station's Name: ";
}
const char *English::getHistory(){
	return "Please enter the size of History: ";
}
const char *English::getMenu(){
	return "Please Choose from the Menu:"
			"\n1. Add Station."
			"\n2. Add Weather Report."
			"\n3. Select Station. (NOT WORKING)"
			"\n4. Print Current Report."
			"\n5. Print Summary Report."
			"\n6. Print Daily Report."
			"\n7. QUIT";
}
const char *English::getTemperature(){
	return "Please enter the temperature: ";
}
const char *English::getWindSpeed(){
	return "Please enter the wind speed: ";
}
const char *English::getDirection(){
	return "Please enter the wind direction in degree (between 0 and 359): ";
}
const char *English::getSelector(){
	return "Please enter the number of the station you wish to work on: ";
}
const char *English::getError(){
	return "I Do not recognize the input.";
}
const char *English::getUnitChoice(){
	return "Pick 1 for Imperial."
			"\nPick 2 for Metric.";
}
const char *English::getOfficeCapacityFull(){
	return "History Capacity of This Office is Full.";
}
const char *English::getStationCapacityFull(){
	return "History Capacity of This Station is Full \nPlease Create Another Station.";
}
const char *English::getEnterValidNumberError(){
	return "Please enter a valid number.";
}
const char *English::getCreateStationError(){
	return "Please Create a Station First.";
}
const char *English::getCreateReportError(){
	return "Please Create a Report First.";
}
const char *English::getDailyReport(){
	return "Daily Report of Station: ";
}
const char *English::getPrintSpeed(){
	return "Wind Speed: ";
}
const char *English::getPrintDirection(){
	return "Wind Direction: ";
}
const char *English::getPrintChill(){
	return "Wind Chill: ";
}
const char *English::getPrintSummary(){
	return "Summary of Station ";
}
const char *English::getPrintHigh(){
	return "High 	Temperature in ";
}
const char *English::getPrintLow(){
	return "Low 	Temperature in ";
}
const char *English::getPrintAverage(){
	return "Average Temperature in ";
}
