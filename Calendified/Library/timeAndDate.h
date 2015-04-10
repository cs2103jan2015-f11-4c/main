//@author A0116027R

#ifndef TIMEANDDATE_H
#define TIMEANDDATE_H
#pragma once

#include <iostream>

class timeAndDate
{
private:
	int _startMDay;
	int _startMonth;
	int _startYear;
	int _endMDay;
	int _endMonth;
	int _endYear;
	int _startTimeHour;
	int _startTimeMin;
	int _endTimeHour;
	int _endTimeMin;
	std::string _startDay;
	std::string _endDay;

public:
	timeAndDate();
	timeAndDate(std::string dateString, std::string timeString);

	bool isValid();

	//setters
	void setStartMDay(int taskMday);
	void setStartMonth(int taskMonth);
	void setStartYear(int taskYear);
	void setEndMDay(int taskMday);
	void setEndMonth(int taskMonth);
	void setEndYear(int taskYear);
	void setStartTimeHour(int taskStartTimeHour);
	void setStartTimeMin(int taskStartTimeMin);
	void setEndTimeHour(int taskEndTimeHour);
	void setEndTimeMin(int taskEndTimeMin);
	void setStartDay(std::string taskStartDay);
	void setEndDay(std::string taskEndDay);

	//getters
	int getStartMDay();
	int getStartMonth();
	int getStartYear();
	int getEndMDay();
	int getEndMonth();
	int getEndYear();
	int getStartTimeHour();
	int getStartTimeMin();
	int getEndTimeHour();
	int getEndTimeMin();
	std::string getStartDay();
	std::string getEndDay();
	time_t getStartDateInTimeT();
	time_t getEndDateInTimeT();
	time_t getStartTimeInTimeT();
	time_t getEndTimeInTimeT();
	std::string getStartDateInString();
	std::string getEndDateInString();
	std::string getTimeInString(std::string timeString);
	std::string getStartTimeInString();
	std::string getEndTimeInString();
	std::string dateAndTimeInString();
	bool isValidTime(std::string timeString, int* taskStartTimeHour, int* taskStartTimeMin, int* taskEndTimeHour, int* taskEndTimeMin);

	~timeAndDate(void);
};

#endif