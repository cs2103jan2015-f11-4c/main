
#ifndef LOGIC_H
#define LOGIC_H
#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include "easylogging++.h"
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
#include "taskRedo.h"

const std::string TYPE_DONE =
	"done";

const std::string TYPE_TASK_DONE =
	"taskdone";

const std::string TYPE_UNDONE =
	"undone";

const std::string TYPE_TASK_UNDONE =
	"taskundone";

const std::string TYPE_QUOTE =
	"\"";

const std::string TYPE_AFTER =
	"after ";

const std::string TYPE_BEFORE =
	"before";

enum commandType {
	COMMAND_ADD, 
	COMMAND_DELETE, 
	COMMAND_SEARCH,
	COMMAND_DISPLAY,
	COMMAND_EDIT, 
	COMMAND_DONE,
	COMMAND_UNDONE,
	COMMAND_UNDO, 
	COMMAND_FLIP, 
	COMMAND_SPECIFY, 
	COMMAND_REDO, 
	COMMAND_TOGGLE,
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
	std::string FLIP_CONTENT;
	
	//Setters
	void setCommand(std::string command);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setDate(std::string date);
	void setTime(std::string time);

	std::string readCommand(std::string commandLine, int toggleCount, int flipCount);
    commandType hashCommandAction(std::string commandAction);
	std::vector<std::string> updateUI(std::string logicResult , int toggleIndex, int flipCount);
	int updateUIFlipCount();
};

#endif