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

const std::string MESSAGE_SUCCESS_ADD = "Added succesfully!";
const std::string MESSAGE_FAILURE_ADD = "Task not added. Please try again.";
const std::string MESSAGE_CLASH_ADD = "Warning: Clash! Added accordingly.";

class taskAdd
{
private:
	task _task;
public:
	taskAdd();
	taskAdd(std::string taskString);
	~taskAdd(void);
	std::string executeAdd();
	void undoAdd(taskUndo* taskToBeUndone);
	void taskAddRecurrent();
	void setTask(task taskString);
	bool isClash(std::vector<task> &storageVector);
};

#endif