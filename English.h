/*
 * English.h
 *
 *  Created on: Apr 23, 2019
 *      Author: s1175919
 */

#ifndef ENGLISH_H_
#define ENGLISH_H_
#include "./Message.h"

class English : public Message{
public:
	const char *getWelcome();
	const char *getOfficeName();
	const char *getStationName();
	const char *getHistory();
	const char *getMenu();
	const char *getTemperature();
	const char *getWindSpeed();
	const char *getDirection();
	const char *getSelector();
	const char *getError();
	const char *getUnitChoice();
	const char *getOfficeCapacityFull();
	const char *getStationCapacityFull();
	const char *getEnterValidNumberError();
	const char *getCreateStationError();
	const char *getCreateReportError();
	const char *getDailyReport();
	const char *getPrintSpeed();
	const char *getPrintDirection();
	const char *getPrintChill();
	const char *getPrintSummary();
	const char *getPrintHigh();
	const char *getPrintLow();
	const char *getPrintAverage();
};




#endif /* ENGLISH_H_ */
