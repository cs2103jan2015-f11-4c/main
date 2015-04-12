
#ifndef LOGIC_H
#define LOGIC_H
#pragma once

#include <iostream>
#include <set>
#include <algorithm>
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
	std::string FLIP_CONTENT;
	std::string readCommand(std::string commandLine, int toggleCount, int flipCount);
    commandType hashCommandAction(std::string commandAction);
	void setCommand(std::string command);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setDate(std::string date);
	void setTime(std::string time);

	std::vector<std::string> updateUI(std::string logicResult , int toggleIndex, int flipCount);
	int updateUIFlipCount();
};

#endif