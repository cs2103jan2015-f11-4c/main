//@author A0114411B

#ifndef TASKDONE_H
#define TASKDONE_H
#pragma once

#include "task.h"
#include "assert.h"
#include <vector>
#include <iostream>

std::string const MESSAGE_SUCCESS_DONE =
	"Marked as done!";
std::string const MESSAGE_SUCCESS_UNDONE =
	"Marked as undone!";
std::string const MESSAGE_ERROR_FILE_EMPTY =
	"Error: File is empty!";
std::string const MESSAGE_ERROR_INVALID_INDEX =
	"Error: Invalid index!";
std::string const MESSAGE_ERROR_NO_TASK_DONE =
	"Error: No task done!";
std::string const MESSAGE_ERROR_NO_TASK_UNDONE =
	"Error: No task undone!";


class taskDone
{
public:
	taskDone(void);
	~taskDone(void);

	std::string markDone(int indexToBeActOn);
	std::string markUndone(int indexToBeActOn);
	std::vector<task> getListDone();
	std::vector<task> getListUndone();

};

#endif