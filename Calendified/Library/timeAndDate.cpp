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
	_endDay = taskEndDay;
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

bool timeAndDate::isValidDate(std::string dateString, int* taskStartMDay, int* taskStartMonth, int* taskStartYear, int* taskEndMDay, int* taskEndMonth, int* taskEndYear){
	assert(dateString != "");
	std::regex dateFormat1("^(([0]?[1-9])|([12][0-9])|([3][01]))(/|-)(([0]?[1-9])|([1][0-2]))(/|-)([0-9][0-9][0-9][0-9])$"); //3/4/2015 or 03/04/2015 or 3-4-2015
	std::regex dateFormat2("^(([0]?[1-9])|([12][0-9])|([3][01]))(/|-)(([0]?[1-9])|([1][0-2]))(/|-)([0-9][0-9][0-9][0-9])-(([0]?[1-9])|([12][0-9])|([3][01]))(/|-)(([0]?[1-9])|([1][0-2]))(/|-)([0-9][0-9][0-9][0-9])$"); //3/4/2015-4/4/2015
	std::regex dateFormat3("^(([0]?[1-9])|([12][0-9])|([3][01]))(/|-)(([0]?[1-9])|([1][0-2]))(/|-)([0-9][0-9])$"); //3/4/15
	std::regex dateFormat4("^(([0]?[1-9])|([12][0-9])|([3][01]))(/|-)(([0]?[1-9])|([1][0-2]))(/|-)([0-9][0-9])-(([0]?[1-9])|([12][0-9])|([3][01]))(/|-)(([0]?[1-9])|([1][0-2]))(/|-)([0-9][0-9])$"); //3/4/15-4/4/15
	//std::regex dateFormat5("^((31(?!\ (Feb(ruary)?|Apr(il)?|June?|(Sep(?=\b|t)t?|Nov)(ember)?)))|((30|29)(?!\ Feb(ruary)?))|(29(?=\ Feb(ruary)?\ (((1[6-9]|[2-9]\d)(0[48]|[2468][048]|[13579][26])|((16|[2468][048]|[3579][26])00)))))|(0?[1-9])|1\d|2[0-8])\ (Jan(uary)?|Feb(ruary)?|Ma(r(ch)?|y)|Apr(il)?|Ju((ly?)|(ne?))|Aug(ust)?|Oct(ober)?|(Sep(?=\b|t)t?|Nov|Dec)(ember)?)\ ((1[6-9]|[2-9]\d)\d{2})$"); //10 Feb 2015
	//std::regex dateFormat6("^((31(?!\ (Feb(ruary)?|Apr(il)?|June?|(Sep(?=\b|t)t?|Nov)(ember)?)))|((30|29)(?!\ Feb(ruary)?))|(29(?=\ Feb(ruary)?\ (((1[6-9]|[2-9]\d)(0[48]|[2468][048]|[13579][26])|((16|[2468][048]|[3579][26])00)))))|(0?[1-9])|1\d|2[0-8])\ (Jan(uary)?|Feb(ruary)?|Ma(r(ch)?|y)|Apr(il)?|Ju((ly?)|(ne?))|Aug(ust)?|Oct(ober)?|(Sep(?=\b|t)t?|Nov|Dec)(ember)?)\ ((1[6-9]|[2-9]\d)\d{2})-((31(?!\ (Feb(ruary)?|Apr(il)?|June?|(Sep(?=\b|t)t?|Nov)(ember)?)))|((30|29)(?!\ Feb(ruary)?))|(29(?=\ Feb(ruary)?\ (((1[6-9]|[2-9]\d)(0[48]|[2468][048]|[13579][26])|((16|[2468][048]|[3579][26])00)))))|(0?[1-9])|1\d|2[0-8])\ (Jan(uary)?|Feb(ruary)?|Ma(r(ch)?|y)|Apr(il)?|Ju((ly?)|(ne?))|Aug(ust)?|Oct(ober)?|(Sep(?=\b|t)t?|Nov|Dec)(ember)?)\ ((1[6-9]|[2-9]\d)\d{2})$"); //10 Feb 2015-11 Feb 2015
	
	char ignore;
	int outNum;
	int mday;
	int month;
	int year;
	
	std::istringstream in(dateString);
	if(std::regex_match(dateString, dateFormat1)){
		in >> outNum;
		mday = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		month = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		year = outNum;
		
		if(year>=1900 && year<=10000){ //check year
			if(isLeapYear(year) == false && isValid29(mday) == false
				&& isValid28(mday, month) == false
				&& isValid30(mday, month) == false
				&& isValid31(mday, month) == false){
					return false;
			} else {
			*taskStartMDay = mday;
			*taskStartMonth = month;
			*taskStartYear = year;
			*taskEndMDay = *taskStartMDay;
			*taskEndMonth = *taskStartMonth;
			*taskEndYear = *taskStartYear;
			return true;
			}
		} 
		return false;
	}else if(std::regex_match(dateString, dateFormat2)){
		in >> outNum;
		mday = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		month = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		year = outNum;
	//mday>=1 && mday<=31 && month>=1 && month<=12 && 
		if(year>=1900 && year<=10000){ //check year
			if(isLeapYear(year) == false && isValid29(mday) == false
				&& isValid28(mday, month) == false
				&& isValid30(mday, month) == false
				&& isValid31(mday, month) == false){
					return false;
			} else {
				*taskStartMDay = mday;
				*taskStartMonth = month;
				*taskStartYear = year;
			}
		} else {
			return false;
		}
		in >> ignore; // '-'
		in >> outNum;
		mday = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		month = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		year = outNum;
	
		if(year>=1900 && year<=10000){ //check year
			if(isLeapYear(year) == false && isValid29(mday) == false
				&& isValid28(mday, month) == false
				&& isValid30(mday, month) == false
				&& isValid31(mday, month) == false){
					return false;
			} else {
			*taskEndMDay = mday;
			*taskEndMonth = month;
			*taskEndYear = year;
			return true;
			}
		} else {
			return false;
		}
	} else if(std::regex_match(dateString, dateFormat3)){
		in >> outNum;
		mday = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		month = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		year = outNum;
		
		if(year>=0 && year<=99){ //check year
			if(isLeapYear(year) == false && isValid29(mday) == false
				&& isValid28(mday, month) == false
				&& isValid30(mday, month) == false
				&& isValid31(mday, month) == false){
					return false;
			} else {
			*taskStartMDay = mday;
			*taskStartMonth = month;
			if(year>=0 && year<=50){
			*taskStartYear = year + 2000;
			} else if(year>50 && year<=99){
				*taskStartYear = year + 1900;
			}
			*taskEndMDay = *taskStartMDay;
			*taskEndMonth = *taskStartMonth;
			*taskEndYear = *taskStartYear;
			return true;
			}
		} 
		return false;
	} else if(std::regex_match(dateString, dateFormat4)){
		in >> outNum;
		mday = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		month = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		year = outNum;
	//mday>=1 && mday<=31 && month>=1 && month<=12 && 
		if(year>=0 && year<=99){ //check year
			if(isLeapYear(year) == false && isValid29(mday) == false
				&& isValid28(mday, month) == false
				&& isValid30(mday, month) == false
				&& isValid31(mday, month) == false){
					return false;
			} else {
				*taskStartMDay = mday;
				*taskStartMonth = month;
				if(year>=0 && year<=50){
					*taskStartYear = year + 2000;
				} else if(year>50 && year<=99){
					*taskStartYear = year + 1900;
				}
			}
		} else {
			return false;
		}
		in >> ignore; // '-'
		in >> outNum;
		mday = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		month = outNum;
		in >> ignore; //'/' or '-'
		in >> outNum;
		year = outNum;
	
		if(year>=0 && year<=99){ //check year
			if(isLeapYear(year) == false && isValid29(mday) == false
				&& isValid28(mday, month) == false
				&& isValid30(mday, month) == false
				&& isValid31(mday, month) == false){
					return false;
			} else {
			*taskEndMDay = mday;
			*taskEndMonth = month;
			if(year>=0 && year<=50){
				*taskStartYear = year + 2000;
			} else if(year>50 && year<=99){
				*taskStartYear = year + 1900;
			}
			return true;
			}
		} else {
			return false;
		}
	}
	return false;
		
/*
	if(mday>=1 && mday<=31 && month>=1 && month<=12 && year>=1900 && year<=10000){
		if(isLeapYear(year) && isValid29(mday)){ //checks leap year and valid date
			*taskStartMDay = mday;
			*taskStartMonth = month;
			*taskStartYear = year;
			return true;
		} else if(isValid28(mday, month)){ //check if it's february and date
			*taskStartMDay = mday;
			*taskStartMonth = month;
			*taskStartYear = year;
			return true;
		} else if(isValid30(mday, month)){ //check month and date
			*taskStartMDay = mday;
			*taskStartMonth = month;
			*taskStartYear = year;
			return true;
		} else if(isValid31(mday, month)){ //check month and date
			*taskStartMDay = mday;
			*taskStartMonth = month;
			*taskStartYear = year;
			return true;
		} else {
			return false;
		}
	} else { 
		return false;
	}
	*/
	
}

void taskTimeToStruct(int startTimeHour, int startTimeMin, tm* Time){
	Time->tm_hour = startTimeHour;
	Time->tm_min = startTimeMin;
}

bool isAmOrPm(int hour, int* timeHour, char day, char m){
	if((day=='a' || day=='A') && (m=='m' || m=='M')){
		if(hour == 12){
			*timeHour = 0;
		} else {
			*timeHour = hour;
		}
	} else if((day=='p' || day=='P') && (m=='m' || m=='M')){
		if(hour == 12){
			*timeHour = 12;
		} else {
			*timeHour = hour + 12;
		}
	} else {
		return false;
	}
	return true;
}

bool timeAndDate::isValidTime(std::string timeString, int* taskStartTimeHour, int* taskStartTimeMin, int* taskEndTimeHour, int* taskEndTimeMin){
	std::regex timeFormat1("^(([0-1]?[0-9])|([2][0-3])):([0-5]?[0-9])$"); //HH:MM or H:M
	std::regex timeFormat2("^(([0-1]?[0-9])|([2][0-3])):([0-5]?[0-9])-(([0-1]?[0-9])|([2][0-3])):([0-5]?[0-9])$"); //HH:MM-HH:MM
	std::regex timeFormat3("^([1-9]|([1][0-2]))(am|pm|AM|PM)$"); //12pm, 9am
	std::regex timeFormat4("^([1-9]|([1][0-2]))(am|pm|AM|PM)-([1-9]|([1][0-2]))(am|pm|AM|PM)$"); //12am-2pm
	std::regex timeFormat5("^([1-9]|([1][0-2]))(.|:)([0-5][0-9])(am|pm|AM|PM)$"); //12.30pm or 12:30pm
	std::regex timeFormat6("^([1-9]|([1][0-2]))(.|:)([0-5][0-9])(am|pm|AM|PM)-([1-9]|([1][0-2]))(.|:)([0-5][0-9])(am|pm|AM|PM)$"); //12.30pm-2.00pm

	char ignore;
	char t1;
	char m;
	std::string day;
	int outNum;
	int hour;
	int min;

	std::istringstream in(timeString);

	if(std::regex_match(timeString, timeFormat1)){ //assumes timed tasks with only start time is 1 hour long
		in >> outNum;
		*taskStartTimeHour = outNum;
		in >> ignore; //:
		in >> outNum;
		*taskStartTimeMin = outNum;
		*taskEndTimeHour = (*taskStartTimeHour) + 1;
		*taskEndTimeMin = *taskStartTimeMin;
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
		/*if((*taskEndTimeHour)/24>0){
			*taskEndTimeHour = (*taskEndTimeHour)%12;
			++_endMDay;
		}*/
		*taskEndTimeMin = *taskStartTimeMin;
	} else if(std::regex_match(timeString, timeFormat4)){
		in >> outNum;
		hour = outNum;
		in >> t1; //a or p
		in >> m; //m
		if(isAmOrPm(hour, taskStartTimeHour, t1, m) == false){
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
		} else if((t1=='p' || t1=='P') && (m=='m' || m=='M')){
			if(hour == 12){
				*taskEndTimeHour = 12;
			} else {
				*taskEndTimeHour = hour + 12;
			}
			/*if(*taskEndTimeHour < *taskStartTimeHour){
				++_endMDay;
			}*/
		} else {
			return false;
		}
		*taskEndTimeMin = *taskStartTimeMin;
	} else if(std::regex_match(timeString, timeFormat5)){
		in >> outNum;
		hour = outNum;
		in >> ignore; //. or :
		in >> outNum;
		min = outNum;
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
		*taskStartTimeMin = min;
		*taskEndTimeHour = (*taskStartTimeHour) + 1;
		*taskEndTimeMin = *taskStartTimeMin;
	} else if(std::regex_match(timeString, timeFormat6)){
		in >> outNum;
		hour = outNum;
		in >> ignore; //. or :
		in >> outNum;
		min = outNum;
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
		*taskStartTimeMin = min;
		in >> ignore; //-
		in >> outNum;
		hour = outNum;
		in >> ignore; //. or :
		in >> min;
		in >> t1; //a or p
		in >> m; //m
		if((t1=='a' || t1=='A') && (m=='m' || m=='M')){
			if(hour == 12){
				*taskEndTimeHour = 0;
			} else {
				*taskEndTimeHour = hour;
			}
			/*if(*taskEndTimeHour < *taskStartTimeHour){
				++_endMDay;
			}*/
		} else if((t1=='p' || t1=='P') && (m=='m' || m=='M')){
			if(hour == 12){
				*taskEndTimeHour = 12;
			} else {
				*taskEndTimeHour = hour + 12;
			}
			/*if(*taskEndTimeHour < *taskStartTimeHour){
				++_endMDay;
			}*/
		} else {
			return false;
		}
		*taskEndTimeMin = min;
		return true;
	} else {
		return false;
	}
	if((_startMDay == _endMDay)
		&& (_startMonth == _endMonth)
		&& (_startYear == _endYear)
		&& (*taskEndTimeHour < *taskStartTimeHour)){
			++_endMDay;
	}
	return true;
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
	_endDay = "";
}

timeAndDate::timeAndDate(std::string dateString, std::string timeString){
	int taskStartMDay;
	int taskStartMonth;
	int taskStartYear;
	int taskEndMDay;
	int taskEndMonth;
	int taskEndYear;
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
		_endMDay = 0;
		_endMonth = 0;
		_endYear = 0;
	} else if(isValidDate(date, &taskStartMDay, &taskStartMonth, &taskStartYear, &taskEndMDay, &taskEndMonth, &taskEndYear)){
		_startMDay = taskStartMDay;
		_startMonth = taskStartMonth;
		_startYear = taskStartYear;
		_endMDay = taskEndMDay;
		_endMonth = taskEndMonth;
		_endYear = taskEndYear;
	} else {
		_startMDay = -1;
		_startMonth = -1;
		_startYear = -1;
		_endMDay = -1;
		_endMonth = -1;
		_endYear = -1;
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
		_endMDay==-1 || _endMonth==-1 || _endYear==-1 ||
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

time_t timeAndDate::getEndDateInTimeT(){
	time_t dateInTimeT;
	struct tm Date = {0};

	if(_endMDay>0 && _endMonth>0 && _endYear>0){
		taskDateToStruct (_endMDay, _endMonth, _endYear, &Date);
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

std::string timeAndDate::getEndDateInString(){
	struct tm *Date;
	char storeDate [20] = {0};

	if(getEndDateInTimeT() != -1){
		const time_t constDate = getEndDateInTimeT();
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

void timeAndDate::deadlineTaskDateAndTimeConversion(std::string taskType){
	std::string deadLineTaskType = "DeadLine";

	if(taskType == deadLineTaskType){
		_endMDay = _startMDay;
		_endMonth = _startMonth;
		_endYear = _startYear;
		_endTimeHour = _startTimeHour;
		_endTimeMin = _startTimeMin;
	}
}