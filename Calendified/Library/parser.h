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
	std::string _taskDateAndTime;// use time_t type for easily sort the tasks in scheduled order

public:
	parser(void);
	parser::parser(std::string commandLine);
	~parser(void);
	std::string getItemsInString(std::string inputString, char itemType);

	//put in logic

	time_t convertDateAndTime(std::string _taskDateAndTime);
	std::string getTaskCommand();
	std::string getTaskTitle();
	std::string getTaskLocation();
	std::string getTaskDescription();
	time_t getTaskTimeAndDate();
};

#endif
