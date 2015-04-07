//@author A0116027R
#include "timeAndDate.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <assert.h>
#include <regex>

void timeAndDate::setStartMDay(int taskMday){
	_startMDay = taskMday;
}

void timeAndDate::setStartMonth(int taskMonth){
	_startMonth = taskMonth;
}

void timeAndDate::setStartYear(int taskYear){
	_startYear = taskYear;
}

void timeAndDate::setEndMDay(int taskMday){
	_endMDay = taskMday;
}

void timeAndDate::setEndMonth(int taskMonth){
	_endMonth = taskMonth;
}

void timeAndDate::setEndYear(int taskYear){
	_endYear = taskYear;
}

void timeAndDate::setStartTimeHour(int taskStartTimeHour){
	_startTimeHour = taskStartTimeHour;
}

void timeAndDate::setStartTimeMin(int taskStartTimeMin){
	_startTimeMin = taskStartTimeMin;
}

void timeAndDate::setEndTimeHour(int taskEndTimeHour){
	_endTimeHour = taskEndTimeHour;
}

void timeAndDate::setEndTimeMin(int taskEndTimeMin){
	_endTimeMin = taskEndTimeMin;
}

void timeAndDate::setStartDay(std::string taskStartDay){
	_startDay = taskStartDay;
}

void timeAndDate::setEndDay(std::string taskEndDay){

}

int timeAndDate::getStartMDay(){
	return _startMDay;
}

int timeAndDate::getStartMonth(){
	return _startMonth;
}

int timeAndDate::getStartYear(){
	return _startYear;
}

int timeAndDate::getEndMDay(){
	return _endMDay;
}

int timeAndDate::getEndMonth(){
	return _endMonth;
}

int timeAndDate::getEndYear(){
	return _endYear;
}

int timeAndDate::getStartTimeHour(){
	return _startTimeHour;
}

int timeAndDate::getStartTimeMin(){
	return _startTimeMin;
}

int timeAndDate::getEndTimeHour(){
	return _endTimeHour;
}

int timeAndDate::getEndTimeMin(){
	return _endTimeMin;
}

std::string timeAndDate::getStartDay(){
	return _startDay;
}

std::string timeAndDate::getEndDay(){
	return _endDay;
}


//checks if it's a valid date for months with 31 days
bool isValid31(int mday, int month){
	assert(mday>=1 && mday<= 31);
	assert(month>=1 && month<=12);
	if(month<=7 && month%2==1){
		return true;
	} else if(month>7 && month%2==0){
		return true;
	} else {
		return false;
	}
}

//checks if it's a valid date for months with 30 days
bool isValid30(int mday, int month){
	assert(mday>=1 && mday<=31);
	assert(month>=1 && month<=12);
	if(mday<=30 && month!=2 && month<=7 && month%2==0){
		return true;
	} else if (mday<=30 && month>7 && month%2==1){
		return true;
	} else {
		return false;
	}
}

//checks if date is a less than or equal to 29
bool isValid29(int mday){
	assert(mday>=1 && mday<=31);
	if(mday<=29){
		return true;
	} else {
		return false;
	}
}

//checks if it's a valid date for February (not leap year)
bool isValid28(int mday, int month){
	assert(mday>=1 && mday<= 31);
	assert(month>=1 && month<=12);
	if(month==2 && mday<=28){
		return true;
	} else {
		return false;
	}
}

bool isLeapYear(int year){
	if(year%4==0 || year%400==0 || year%100==0){
		return true;
	} else {
		return false;
	}
}

void taskDateToStruct(int mday, int month, int year, tm* Date){
	const int MONTH = 1;
	const int YEAR = 1900;

	Date->tm_mday = mday;
	Date->tm_mon = month - MONTH;
	Date->tm_year = year - YEAR;
}

bool isValidDate(std::string dateString, int* taskMDay, int* taskMonth, int* taskYear){
	assert(dateString != "");
	char ignore;
	int outNum;

	std::istringstream in(dateString);
	
	in >> outNum;
	int mday = outNum;
	
	in >> ignore; //'/'
	
	in >> outNum;
	int month = outNum;

	in >> ignore; //'/'

	in >> outNum;
	int year= outNum;

	if(mday>=1 && mday<=31 && month>=1 && month<=12 && year>=1900 && year<=10000){ //check year
		if(isLeapYear(year) && isValid29(mday)){ //checks leap year and valid date
			*taskMDay = mday;
			*taskMonth = month;
			*taskYear = year;
			return true;
		} else if(isValid28(mday, month)){ //check if it's february and date
			*taskMDay = mday;
			*taskMonth = month;
			*taskYear = year;
			return true;
		} else if(isValid30(mday, month)){ //check month and date
			*taskMDay = mday;
			*taskMonth = month;
			*taskYear = year;
			return true;
		} else if(isValid31(mday, month)){ //check month and date
			*taskMDay = mday;
			*taskMonth = month;
			*taskYear = year;
			return true;
		} else {
			return false;
		}
	} else { 
		return false;
	}
}

void taskTimeToStruct(int startTimeHour, int startTimeMin, tm* Time){
	Time->tm_hour = startTimeHour;
	Time->tm_min = startTimeMin;
}

bool timeAndDate::isValidTime(std::string timeString, int* taskStartTimeHour, int* taskStartTimeMin, int* taskEndTimeHour, int* taskEndTimeMin){
	std::regex timeFormat1("^(([0-1]?[0-9])|([2][0-3])):([0-5]?[0-9])$"); //HH:MM
	std::regex timeFormat2("^(([0-1]?[0-9])|([2][0-3])):([0-5]?[0-9])-(([0-1]?[0-9])|([2][0-3])):([0-5]?[0-9])$"); //HH:MM-HH:MM
	std::regex timeFormat3("^([1-9]|([1][0-2]))(am|pm|AM|PM)$"); //12pm, 9am
	std::regex timeFormat4("^([1-9]|([1][0-2]))(am|pm|AM|PM)-([1-9]|([1][0-2]))(am|pm|AM|PM)$"); //12am-2pm

	char ignore;
	char t1;
	char m;
	std::string day;
	int outNum;
	int hour;

	std::istringstream in(timeString);

	if(std::regex_match(timeString, timeFormat1)){ //assumes timed tasks with only start time is 1 hour long
		in >> outNum;
		*taskStartTimeHour = outNum;
		in >> ignore; //:
		in >> outNum;
		*taskStartTimeMin = outNum;
		*taskEndTimeHour = (*taskStartTimeHour) + 1;
		*taskEndTimeMin = *taskStartTimeMin;
		return true;
	} else if(std::regex_match(timeString, timeFormat2)){
		in >> outNum;
		*taskStartTimeHour = outNum;
		in >> ignore; //:
		in >> outNum;
		*taskStartTimeMin = outNum;
		in >> ignore; //-
		in >> outNum;
		*taskEndTimeHour = outNum;
		in >> ignore; //:
		in >> outNum;
		*taskEndTimeMin = outNum;
		return true;
	} else if(std::regex_match(timeString, timeFormat3)){
		in >> outNum;
		hour = outNum;
		in >> day; //am or pm
		if(day=="am" || day=="AM"){
			if(hour == 12){
				*taskStartTimeHour = 0;
			} else {
				*taskStartTimeHour = hour;
			}
		} else if(day=="pm" || day=="PM"){
			if(hour == 12){
				*taskStartTimeHour = 12;
			} else {
				*taskStartTimeHour = hour + 12;
			}
		} else {
			return false;
		}
		*taskStartTimeMin = 0;
		*taskEndTimeHour = (*taskStartTimeHour) + 1; //1h activity
		if((*taskEndTimeHour)/24>0){
			*taskEndTimeHour = (*taskEndTimeHour)%12;
			++_endMDay;
		}
		*taskEndTimeMin = *taskStartTimeMin;
		return true;
	} else if(std::regex_match(timeString, timeFormat4)){
		in >> outNum;
		hour = outNum;
		in >> t1; //a or p
		in >> m; //m
		if((t1=='a' || t1=='A') && (m=='m' || m=='M')){
			if(hour == 12){
				*taskStartTimeHour = 0;
			} else {
				*taskStartTimeHour = hour;
			}
		} else if((t1=='p' || t1=='P') && (m=='m' || m=='M')){
			if(hour == 12){
				*taskStartTimeHour = 12;
			} else {
				*taskStartTimeHour = hour + 12;
			}
		} else {
			return false;
		}
		*taskStartTimeMin = 0;
		in >> ignore; //-
		in >> outNum;
		hour = outNum;
		in >> t1; //a or p
		in >> m; //m
		if((t1=='a' || t1=='A') && (m=='m' || m=='M')){
			if(hour == 12){
				*taskEndTimeHour = 0;
			} else {
				*taskEndTimeHour = hour;
			}
			if(*taskEndTimeHour < *taskStartTimeHour){
				++_endMDay;
			}
		} else if((t1=='p' || t1=='P') && (m=='m' || m=='M')){
			if(hour == 12){
				*taskEndTimeHour = 12;
			} else {
				*taskEndTimeHour = hour + 12;
			}
			if(*taskEndTimeHour < *taskStartTimeHour){
				++_endMDay;
			}
		} else {
			return false;
		}
		*taskEndTimeMin = *taskStartTimeMin;
		return true;
	} else {
		return false;
	}
	
	/*if(hour>=0 && hour<=12 && min>=0 && min<=59){
		Time->tm_hour = hour;
		Time->tm_min = min;
		timeInT = mktime(Time);
		return timeInT;
	} else {
		return -1;
	}
	*/
}

timeAndDate::timeAndDate(){
	_startMDay = 0;
	_startMonth = 0;
	_startYear = 0;
	_startTimeHour = 0;
	_startTimeMin = 0;
	_endTimeHour = 0;
	_endTimeMin = 0;
	_startDay = "";
}

timeAndDate::timeAndDate(std::string dateString, std::string timeString){
	int taskMDay;
	int taskMonth;
	int taskYear;
	int taskStartTimeHour;
	int taskStartTimeMin;
	int taskEndTimeHour;
	int taskEndTimeMin;

	std::string date = dateString;
	std::string time = timeString;

	if(date == ""){
		_startMDay = 0;
		_startMonth = 0;
		_startYear = 0;
	} else if(isValidDate(date, &taskMDay, &taskMonth, &taskYear)){
		_startMDay = taskMDay;
		_startMonth = taskMonth;
		_startYear = taskYear;
	} else {
		_startMDay = -1;
		_startMonth = -1;
		_startYear = -1;
	}
		
	if(time == ""){
		_startTimeHour = 0;
		_startTimeMin = 0;
		_endTimeHour = 0;
		_endTimeMin = 0;
	} else if (isValidTime(time, &taskStartTimeHour, &taskStartTimeMin, &taskEndTimeHour, &taskEndTimeMin)){
		_startTimeHour = taskStartTimeHour;
		_startTimeMin = taskStartTimeMin;
		_endTimeHour = taskEndTimeHour;
		_endTimeMin = taskEndTimeMin;
	} else {
		_startTimeHour = -1;
		_startTimeMin = -1;
		_endTimeHour = -1;
		_endTimeMin = -1;
	}
}

bool timeAndDate::isValid(){
	if(_startMDay==-1 || _startMonth==-1 || _startYear==-1 || 
		_startTimeHour==-1 || _startTimeMin==-1 ||
		_endTimeHour==-1 || _endTimeHour==-1){
		return false;
	} else {
		return true;
	}
}

time_t timeAndDate::getStartDateInTimeT(){
	time_t dateInTimeT;
	struct tm Date = {0};

	if(_startMDay>0 && _startMonth>0 && _startYear>0){
		taskDateToStruct (_startMDay, _startMonth, _startYear, &Date);
		dateInTimeT = mktime(&Date);
		return dateInTimeT;
	} else {
		return -1;
	}
}

std::string timeAndDate::getStartDateInString(){
	struct tm *Date;
	char storeDate [20] = {0};

	if(getStartDateInTimeT() != -1){
		const time_t constDate = getStartDateInTimeT();
		Date = localtime(&constDate);
		
	strftime(storeDate, 20, "%d/%m/%Y", Date);
	return storeDate;
	} else {
		return "";
	} 
}

time_t timeAndDate::getStartTimeInTimeT(){
	time_t timeInTimeT;
	struct tm Time = {0};

	if(_startTimeHour>=0 && _startTimeMin>=0){
		taskTimeToStruct (_startTimeHour, _startTimeMin, &Time);
		timeInTimeT = mktime(&Time);
		return timeInTimeT;
	} else {
		return -1;
	}
}

time_t timeAndDate::getEndTimeInTimeT(){
	time_t timeInTimeT;
	struct tm Time = {0};

	if(_endTimeHour>=0 && _endTimeMin>=0){
		taskTimeToStruct (_endTimeHour, _endTimeMin, &Time);
		timeInTimeT = mktime(&Time);
		return timeInTimeT;
	} else {
		return -1;
	}
}

std::string timeAndDate::getStartTimeInString(){
	struct tm *Time;
	char storeTime [20] = {0};

	if(getStartTimeInTimeT() != -1){
		const time_t constTime = getStartTimeInTimeT();
		Time = localtime(&constTime);
		strftime(storeTime, 20, "%H:%M", Time);
		return storeTime;
	} else {
		return "";
	}
}

std::string timeAndDate::getEndTimeInString(){
	struct tm *Time;
	char storeTime [20] = {0};

	if(getEndTimeInTimeT() != -1){
		const time_t constTime = getEndTimeInTimeT();
		Time = localtime(&constTime);
		strftime(storeTime, 20, "%H:%M", Time);
		return storeTime;
	} else {
		return "";
	}
}

std::string timeAndDate::dateAndTimeInString(){
	std::string dateAndTime = "";
	std::string date = getStartDateInString();
	std::string startTime = getStartTimeInString();
	std::string endTime = getEndTimeInString();

	dateAndTime = date + startTime + '-' + endTime;
	return dateAndTime;
}

timeAndDate::~timeAndDate(void)
{
}