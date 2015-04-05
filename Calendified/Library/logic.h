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
#include "commandRef.h"
#include "task.h"
#include "taskAdd.h"
#include "storage.h"
#include "taskEdit.h"
#include "taskUndo.h"
#include "taskDisplay.h"

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
	TOGGLE,
	CHECKDONE
};

class logic
{
private:
	std::set <std::string> allTasks;
	commandRef currentCommandReference;
	
	
public:
	logic(void);
	~logic(void);
	storage newStorage;
	std::string readCommand(std::string commandLine);
    commandType hashCommandAction(std::string commandAction);

	void setCommand(std::string command);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setDate(std::string date);
	void setTime(std::string time);

	std::vector<std::string> updateUI(std::string logicResult , int toggleIndex);
};

#endif