#pragma once
#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include "taskDelete.h"
#include "parser.h"

enum commandType {
	ADD, 
	DELETE, 
	VIEW,
	DISPLAY, 
	EDIT, 
	UNDO, 
	REPEAT, 
	SPECIFY, 
	REDO, 
	TOGGLE 
};

class logic
{
private:
	std::set <std::string> allTasks;
public:
	logic(void);
	~logic(void);
	std::string readCommand(std::string commandLine);
	std::string toString();

	void setCommand(std::string command);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setDescription(std::string description);
	void setDate(std::string date);
	void setTime(std::string time);

	/*
	std::string getCommand();
	std::string getTitle();
	std::string getLocation();
	std::string getDescription();
	std::string getDate();
	std::string getTime();
	*/

	/*
	void toParser(std::string command);
	*/
	
	bool displayTasks();
};

#endif