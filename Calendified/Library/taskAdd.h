//@author A0116027R

#ifndef TASKADD_H
#define TASKADD_H
#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include "logic.h"
#include "storage.h"
#include "taskUndo.h"

const std::string MESSAGE_SUCCESS_ADD = 
	"Added!";

const std::string MESSAGE_FAILURE_ADD = 
	"Fail to add.";

const std::string MESSAGE_WARNING_ADD_CLASH = 
	"Warning: Clash!";

class taskAdd
{
private:
	task _task;
public:
	taskAdd();
	~taskAdd(void);
	taskAdd(std::string taskString);
	bool notValidTitle();
	std::string executeAdd();
	void undoAdd(taskUndo* taskToBeUndone, std::string results);
	bool isClash(std::vector<task> &storageVector);
	//Setter
	void setTask(task taskString);
	//Getter
	task getTask();
};

#endif