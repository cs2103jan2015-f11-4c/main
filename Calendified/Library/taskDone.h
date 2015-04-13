//@author A0114411B

#ifndef TASKDONE_H
#define TASKDONE_H
#pragma once

#include <iostream>
#include <vector>
#include "task.h"
#include "assert.h"
#include "storage.h"
#include "taskUndo.h"

std::string const MESSAGE_SUCCESS_DONE =
	"Marked as done!";

std::string const MESSAGE_SUCCESS_UNDONE =
	"Marked as undone!";

std::string const MESSAGE_ERROR_NO_TASK_DONE =
	"Error: No task done.";

std::string const MESSAGE_ERROR_NO_TASK_UNDONE =
	"Error: No task undone.";

std::string const MESSAGE_ERROR_ALREADY_DONE =
	"Error: Task already done!";

std::string const MESSAGE_ERROR_ALREADY_UNDONE =
	"Error: Task already undone!";

class taskDone
{
public:
	taskDone(void);
	~taskDone(void);

	//Getters
	std::vector<task> getListDone();
	std::vector<task> getListUndone();

	std::string markDone(int indexToBeActOn);
	std::string markUndone(int indexToBeActOn);
	bool isEmpty(std::vector<task> storageVector);
	bool isInvalidIndex(int indexToBeActOn, int size);
	void undoDone(taskUndo* taskToBeUndone, std::string results);
	void undoUndone(taskUndo* taskToBeUndone, std::string results);
};

#endif