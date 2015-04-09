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
#include "taskDone.h"

enum commandType {
	ADD, 
	DELETE, 
	SEARCH,
	DISPLAY,
	EDIT, 
	DONE,
	UNDONE,
	UNDO, 
	FLIP, 
	SPECIFY, 
	REDO, 
	TOGGLE,
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
	std::string readCommand(std::string commandLine, int flipCount);
    commandType hashCommandAction(std::string commandAction);

	void setCommand(std::string command);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setDate(std::string date);
	void setTime(std::string time);

	std::vector<std::string> updateUI(std::string logicResult , int toggleIndex, int flipCount);
};

#endif