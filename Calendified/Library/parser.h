
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
#include "commandRef.h"


const std::string DATE_DEADLINE_BY =
	"by";
const std::string DATE_DEADLINE_DUE =
	"due";
const std::string DATE_DEADLINE_BEFORE =
	"before";

const std::string TimedTask = "TimedTask";
const std::string FloatingTask = "FloatingTask";
const std::string DeadLine = "DeadLine";

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
	std::string getItemsInString(std::string inputString, char itemType);
	std::string getTaskCommand();
	commandRef getCommandRef();
	std::vector<std::string> detokenizeCommandLine(std::string);
	void checkAndSetTaskType(std::string);

};

#endif
