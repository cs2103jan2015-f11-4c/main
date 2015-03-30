#pragma once
#include <iostream>

class timeAndDate
{
private:
	int _mday;
	int _month;
	int _year;
	int _hour;
	int _min;

public:
	timeAndDate();
	time_t getTaskDateInTimeT(std::string dateString, tm* Date);
	std::string getTaskDateInString(std::string dateString);
	time_t getTaskTimeInTimeT(std::string timeString, tm* Time);
	std::string getTaskTimeInString(std::string timeString);
	std::string dateAndTimeInString(std::string dateString, std::string timeString);

	~timeAndDate(void);
};