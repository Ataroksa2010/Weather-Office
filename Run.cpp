/*
 * Run.cpp
 *
 *  Created on: May 5, 2019
 *      Author: Hattan Hamoud
 */
#include <iostream>
#include "WeatherReport.h"
#include "WeatherStation.h"
#include "WeatherOffice.h"
#include "Message.h"
#include "Arabic.h"
#include "English.h"
#include "Unit.h"
#include "Imperial.h"
#include "Metric.h"
#include <ctime>


#include <string>
using namespace std;

int main(){
	int choice;
	Message *language;
	cout <<"Welcome!" << endl;
	cout <<"Please Enter 1 for English, or anything else for Binary"<<endl;
	//SINCE ECLIPSE CANT HANDLE ARABIC, I PICKED BINARY AS MY SECOND LANGUAGE :)
	cin >>  choice;
	if(choice == 1)
		language = new English();
	else
		language = new Arabic();

	int unitChoice;
	cout << language->getUnitChoice() << endl;
	cin >> unitChoice;
	Unit *up;
	if(unitChoice == 1)
		up = new Imperial();
	else
		up = new Metric();


	//INITIATE EVERYTHING
	WeatherOffice *office;
	WeatherStation *station;
	WeatherReport *report;

	//START OFFICE
	cout << language->getOfficeName() << endl;
	string officeName;
	cin >> officeName;
	cout << language->getHistory() << endl;
	int stationHistory;
	cin >> stationHistory;
	office = new WeatherOffice(officeName);


	//Control unit for the menu
	bool quit = false;
	bool checkStation= false;
	bool checkReport = false;

	//Report Variables
	string stationName;
	int temperature;
	int windSpeed;
	int windDirection;

	//TimeStamp controllers
	static int timeControl=0;	//Control TimeStamp array inputs
	int stationTimeControl=0; //Control TimeStamp for different stations
	time_t now[stationHistory][12];
	char* dt; //TIMESTAMP array



	do{
		//START MENU
		int menuChoice;
		cout << language->getMenu() << endl;
		cin >> menuChoice;

		switch (menuChoice){

		case 1: //WORKING PERFECTLY!

			//ADD STATION TO OFFICE
			if(office->getLastOffice() != 12){
				cout << language->getStationName()<<endl;
				cin >> stationName;
				station = new WeatherStation(stationName, stationHistory);
				office->addStation(station);
				checkStation = true;
				checkReport = false;
				stationTimeControl++;
				timeControl=0;	//Reset for new array
			}
			else{
				cout << "-----------------------"<<endl;
				cout << language->getOfficeCapacityFull()<<endl;
				cout << "-----------------------"<<endl;
			}

			break;

		case 2: //WORKING PERFECTLY
			if(checkStation==true){
				//ADD REPORT TO STATION
				if(station->getLast()!=station->getHistory()){
					while(true){
						cout << "-----------------------"<<endl;
						cout << language->getTemperature() << endl;
						cin >> temperature;
						if(!cin){			//INPUT IS NOT A NUMBER
							cin.clear(); 	//CLEAR INPUT BITS
							cin.ignore();	//MUST USE TO AVOID INFINITY LOOP
							cout << language->getEnterValidNumberError()<<endl;
							continue;
						}		//ENTER LOOP AGAIN FOR NEW INPUT
						else
							break;

					}
					while(true){
						cout << language->getWindSpeed() << endl;
						cin >> windSpeed;
						if(!cin){			//INPUT IS NOT A NUMBER
							cin.clear(); 	//CLEAR INPUT BITS
							cin.ignore();	//MUST USE TO AVOID INFINITY LOOP
							cout << language->getEnterValidNumberError()<<endl;
							continue;
						}		//ENTER LOOP AGAIN FOR NEW INPUT
						else
							break;
					}
					while(true){
						cout << language->getDirection() << endl;
						cin >> windDirection;
						if(!cin ||windDirection<0 ||windDirection>359){			//INPUT IS NOT A NUMBER
							cin.clear(); 	//CLEAR INPUT BITS
							cin.ignore();	//MUST USE TO AVOID INFINITY LOOP
							cout << language->getEnterValidNumberError()<<endl;
							continue;
						}		//ENTER LOOP AGAIN FOR NEW INPUT
						else{
							break;
						}
					}
					cout << "-----------------------"<<endl;
					int windC = up->getWindChill(windSpeed,temperature);
					report = new WeatherReport(temperature, windSpeed, windDirection, windC);
					now[timeControl][stationTimeControl-1] = time(0);
					timeControl++;

					/*int choiceOfStation;
					cout << language->getSelector()<<endl;
					office->printStationList();							//PRINT AVAILABLE STATION
					cin >> choiceOfStation;								//GET STATION PICKED
					office->stationAddReport(report, choiceOfStation);	//USE PICKED STATION TO ADD A REPORT TO IT
					 */
					station->addReport(report);
					checkReport=true;
				}
				else{
					cout << "-----------------------"<<endl;
					cout<<language->getStationCapacityFull()<<endl;
					cout << "-----------------------"<<endl;
				}
			}
			else{
				cout << "-----------------------"<<endl;
				cout<<language->getCreateStationError()<<endl;
				cout << "-----------------------"<<endl;
			}
			break;
		case 3: //IN PROGRESS
			if(checkStation==true){
				//SELECT STATION
				int choiceOfStation;
				cout << language->getSelector()<<endl;
				office->printStationList();
				cin >> choiceOfStation;
				office->selectStation(choiceOfStation);
			}
			else{
				cout << "-----------------------"<<endl;
				cout<<language->getCreateStationError()<<endl;
				cout << "-----------------------"<<endl;
			}
			break;
		case 4: //WORKING PERFECTLY

			//PRINT LAST REPORT
			if(checkReport==true){
				cout << "-----------------------"<<endl;
				dt= ctime(&now[timeControl-1][stationTimeControl-1]);
				cout<<dt<<endl;
				station->printCurrent(up,station->getCounter()-1,language);
			}
			else{
				cout << "-----------------------"<<endl;
				cout <<language->getCreateReportError()<<endl;
				cout << "-----------------------"<<endl;
			}
			break;
		case 5: //WORKING PERFECTLY

			//PRINT SUMMARY OF STATION
			if(checkReport==true)
				station->printSummary(up,language);
			else{
				cout << "-----------------------"<<endl;
				cout <<language->getCreateReportError()<<endl;
				cout << "-----------------------"<<endl;
			}
			break;
		case 6: //WOKRING PERFECTLY

			//PRINT DAILY REPORT
			if(checkReport==true){
				cout << "-----------------------"<<endl;
				cout << language->getDailyReport()<< station->getName()<< endl;
				cout << "-----------------------"<<endl;
				for(int i=0;i<station->getLast();i++){
					dt= ctime(&now[i][stationTimeControl-1]);
					cout<<dt<<endl;
					station->printCurrent(up,i,language);
					//office->stationPrintFull(up,choiceOfStation,i);
					//TRIED TO PASS A FUNCTION THROUGH ANOTHER TO PICK A SPECIFIC STATION FROM OFFICE, PROGRAM CRASHED
				}
			}
			else{
				cout << "-----------------------"<<endl;
				cout <<language->getCreateReportError()<<endl;
				cout << "-----------------------"<<endl;
			}
			break;
		case 7:
			quit = true;
			break;
		default:
			cout << language->getError() << endl;
		}
	}while(!quit);
}



