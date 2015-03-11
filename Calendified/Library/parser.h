#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <ctype.h>
#include <time.h>
#include <string>
#include <sstream>
#include "logic.h"
#include "taskRef.h"

class parser
{
private:
	std::string _taskCommand;
	taskRef taskReference;

public:
	parser(void);
	parser::parser(std::string commandLine);
	~parser(void);
	int getItemInInteger(std::string inputString);
	std::string getItemsInString(std::string inputString, char itemType);
	std::string getTaskCommand();
	taskRef getTaskRef();

};

#endif
