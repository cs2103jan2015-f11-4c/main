#include "timeAndDate.h"
#include <sstream>
#include <ctime>
#include <iostream>

timeAndDate::timeAndDate(){
}

bool isValid31(int mday){
	if(mday>=1 && mday<=31){
		return true;
	} else {
		return false;
	}
}

bool isValid30(int mday){
	if(mday>=1 && mday<=30){
		return true;
	} else {
		return false;
	}
}

bool isValid29(int mday){
	if(mday>=1 && mday<=29){
		return true;
	} else {
		return false;
	}
}

bool isValid28(int mday){
	if(mday>=1 && mday<=28){
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

time_t timeAndDate::getTaskDateInTimeT(std::string dateString, tm* Date){
	time_t dateInTimeT;
	char ignore;
	int outNum;

	if (dateString != ""){
	std::istringstream in(dateString);
	
	in >> outNum;
	int mday = outNum;
	
	in >> ignore;
	
	in >> outNum;
	int month = outNum;

	in >> ignore;

	in >> outNum;
	int year = outNum;

	if(mday>=1 && mday>=31 && month>=1 && month<=12 && year>=1900 && year<=10000){ //check year
		if(isLeapYear(year) && isValid29(mday)){ //check leap year and valid date
			Date->tm_mday = mday;
			Date->tm_mon = month - 1;
			Date->tm_year = year - 1900;
		} else if(month==2 && isValid28(mday)){ //check if it's february and date
			Date->tm_mday = mday;
			Date->tm_mon = month - 1;
			Date->tm_year = year - 1900;
		} else if(month<=7 && month%2==1 && isValid31(mday)){ //check month and date
			Date->tm_mday = mday;
			Date->tm_mon = month - 1;
			Date->tm_year = year - 1900;
		} else if(month<=7 && month%2==0 && isValid30(mday)){ //check month and date
			Date->tm_mday = mday;
			Date->tm_mon = month - 1;
			Date->tm_year = year - 1900;
		} else if(month>=7 && month%2==1 && isValid30(mday)){ //check month and date
			Date->tm_mday = mday;
			Date->tm_mon = month - 1;
			Date->tm_year = year - 1900;
		} else if(month>=7 && month%2==0 && isValid31(mday)){ //check month and date
			Date->tm_mday = mday;
			Date->tm_mon = month - 1;
			Date->tm_year = year - 1900;
		} else {
			return -1;
		}
	} else { 
			return -1;
		}
	dateInTimeT = mktime(Date);
	}
	return dateInTimeT;
}

std::string timeAndDate::getTaskDateInString(std::string dateString){
	struct tm Date = {0};
	char storeDate [20] = {0};

	if(getTaskDateInTimeT(dateString, &Date) != -1){
	strftime(storeDate, 20, "%d/%m/%Y", &Date);
	return storeDate;
	} else if(dateString == "") {
		return "";
	} else {
		return "Error in date.";
	} 
}

time_t timeAndDate::getTaskTimeInTimeT(std::string timeString, tm* Time){
	time_t timeInT;
	char ignore;
	int outNum;

	if(timeString != ""){
	std::istringstream in(timeString);
	
	in >> outNum;
	int hour = outNum;

	in >> ignore;

	in >> outNum;
	int min = outNum;

	if(hour>=0 && hour<=12 && min>=0 && min<=59){
		Time->tm_hour = hour;
		Time->tm_min = min;
		timeInT = mktime(Time);
		return timeInT;
	} else {
		return -1;
	}
	} else {
		return -1;
	}
}

std::string timeAndDate::getTaskTimeInString(std::string timeString){
	struct tm Time = {0};
	char storeTime [20] = {0};

	if(getTaskTimeInTimeT(timeString, &Time) != -1){
		strftime(storeTime, 20, "%H:%M", &Time);
		return storeTime;
	} else if(timeString == "") {
		return "";
	} else {
		return "Error in time.";
	}
}

std::string timeAndDate::dateAndTimeInString(std::string dateString, std::string timeString){
	std::string dateAndTime = "";
	std::string date = getTaskDateInString(dateString);
	std::string time = getTaskTimeInString(timeString);

	return dateAndTime;
}

timeAndDate::~timeAndDate(void)
{
}