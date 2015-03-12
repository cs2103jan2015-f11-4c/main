#pragma once
#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "taskDelete.h"
#include "parser.h"
#include "taskRef.h"
#include "taskAdd.h"
#include "storage.h"
#include "taskEdit.h"

enum commandType {
	ADD, 
	DELETE, 
	VIEW,
	DISPLAY,
	CLEAR,
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
	taskRef currentTaskReference;
	
public:
	logic(void);
	~logic(void);
	std::string readCommand(std::string commandLine);
    commandType hashCommandAction(std::string commandAction);
	void setCommand(std::string command);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setDescription(std::string description);
	void setDate(std::string date);
	void setTime(std::string time);
	
	bool displayTasks();
};

#endif