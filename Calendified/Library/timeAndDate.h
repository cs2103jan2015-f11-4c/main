#pragma once
#include <iostream>

class timeAndDate
{
private:
	int _mday;
	int _month;
	int _year;
	int _startTimeHour;
	int _startTimeMin;
	int _endTimeHour;
	int _endTimeMin;
	std::string _day;

public:
	timeAndDate();
	timeAndDate(std::string dateString, std::string timeString);

	bool isValid();

	//setters
	void setMDay(int taskMday);
	void setMonth(int taskMonth);
	void setYear(int taskYear);
	void setStartTimeHour(int taskStartTimeHour);
	void setStartTimeMin(int taskStartTimeMin);
	void setEndTimeHour(int taskEndTimeHour);
	void setEndTimeMin(int taskEndTimeMin);

	//getters
	int getMDay();
	int getMonth();
	int getYear();
	int getStartTimeHour();
	int getStartTimeMin();
	int getEndTimeHour();
	int getEndTimeMin();
	std::string getDay();


	time_t getTaskDateInTimeT();
	std::string getTaskDateInString();
	time_t getTaskStartTimeInTimeT();
	time_t getTaskEndTimeInTimeT();
	std::string getTaskTimeInString(std::string timeString);
	std::string getTaskStartTimeInString();
	std::string getTaskEndTimeInString();
	std::string dateAndTimeInString();
	bool isValidTime(std::string timeString, int* taskStartTimeHour, int* taskStartTimeMin, int* taskEndTimeHour, int* taskEndTimeMin);

	~timeAndDate(void);
};