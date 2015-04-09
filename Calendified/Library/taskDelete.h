//@author A0114411B
#pragma once
#ifndef TASKDELETE_H
#define TASKDELETE_H
#include <string>
#include <string>
#include <iostream>
#include <vector>
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