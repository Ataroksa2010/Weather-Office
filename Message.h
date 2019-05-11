/*
 * 1stLanguage.h
 *
 *  Created on: Apr 18, 2019
 *      Author: s1175919
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

class Message{
public:
	virtual const char *getWelcome()=0;
	virtual const char *getOfficeName()=0;
	virtual const char *getStationName()=0;
	virtual const char *getHistory() = 0;
	virtual	const char *getMenu() = 0;
	virtual const char *getTemperature()=0;
	virtual const char *getWindSpeed()=0;
	virtual const char *getDirection()=0;
	virtual const char *getSelector()=0;
	virtual const char *getError()=0;
	virtual const char *getUnitChoice()=0;
	virtual const char *getOfficeCapacityFull()=0;
	virtual const char *getStationCapacityFull()=0;
	virtual const char *getEnterValidNumberError()=0;
	virtual const char *getCreateStationError()=0;
	virtual const char *getCreateReportError()=0;
	virtual const char *getDailyReport()=0;
	virtual const char *getPrintSpeed()=0;
	virtual const char *getPrintDirection()=0;
	virtual const char *getPrintChill()=0;
	virtual const char *getPrintSummary()=0;
	virtual const char *getPrintHigh()=0;
	virtual const char *getPrintLow()=0;
	virtual const char *getPrintAverage()=0;
};



#endif /* 1STMESSAGE_H_ */
