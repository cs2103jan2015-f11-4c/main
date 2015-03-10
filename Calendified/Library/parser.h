#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include "logic.h"

class parser
{
private:
	std::string _taskCommand;
	std::string _taskTitle;
	std::string _taskLocation;
	std::string _taskDescription;
	std::string _taskDate;
	std::string _taskTime;

public:
	parser(void);
	parser::parser(std::string commandLine);
	~parser(void);
	std::string getItemsInString(std::string inputString, char itemType);
	time_t convertDate(std::string _taskDate);
	time_t convertTime(std::string _taskTime);
	std::string getTaskCommand();
	std::string getTaskTitle();
	std::string getTaskLocation();
	std::string getTaskDescription();
	time_t getTaskDate();
	time_t getTaskTime();

};

#endif
