
#ifndef PARSER_H
#define PARSER_H
#pragma once

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include "commandRef.h"
#include "timeAndDate.h"


const std::string DATE_DEADLINE_BY =
	"by";
const std::string DATE_DEADLINE_DUE =
	"due";
const std::string DATE_DEADLINE_BEFORE =
	"before";

const std::string TIMED_TASK = "TimedTask";
const std::string FLOATING_TASK = "FloatingTask";
const std::string DEAD_LINE = "DeadLine";

class parser
{
private:
	std::string _taskCommand;
	commandRef commandReference;

public:
	parser(void);
	parser::parser(std::string commandLine);
	~parser(void);
	int getItemInInteger(std::string inputString);

	//Getters
	std::string getTaskCommand();
	commandRef getCommandRef();
	std::vector<std::string> parser::getCommandlineItem(std::string commandLine);

	std::vector<std::string> detokenizeCommandLine(std::string);
	void checkAndSetTaskType(std::string);
	std::string constructItem(std::vector<std::string> dataContainor,int startPosition, int endPosition);
	bool checkCommand(std::string checkCommandInput);
	int checkDeadlineIndex(std::string commandLine);
};

#endif
