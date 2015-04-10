//@author A0114411B

#ifndef TASKDELETE_H
#define TASKDELETE_H
#pragma once

#include <vector>
#include "easylogging++.h"
#include "storage.h"
#include "taskUndo.h"

const std::string MESSAGE_SUCCESS_DELETED =
	"Deleted!";

const std::string MESSAGE_FAILURE_DELETE = 
	"Fail to delete.";

class taskDelete
{
	
public:
	taskDelete(void);
	~taskDelete(void);
	
	std::string executeDelete(int indexToBeDeleted);
	bool isEmpty(std::vector<task> file);
	bool isNotValidIndex(int indexToBeDeleted);
	std::vector<task> taskDelete::performDeleteTask(std::vector<task> file, int indexToBeDeleted);
	void undoDelete(taskUndo* taskToBeUndone);
};

#endif