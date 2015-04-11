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
	taskAdd(std::string taskString);
	~taskAdd(void);
	std::string executeAdd();
	void undoAdd(taskUndo* taskToBeUndone, std::string results);
	void taskAddRecurrent();
	void setTask(task taskString);
	bool isClash(std::vector<task> &storageVector);
};

#endif