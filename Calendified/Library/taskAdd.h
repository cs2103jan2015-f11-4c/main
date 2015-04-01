//@author A0116027R

#ifndef TASKADD_H
#define TASKADD_H

#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include "logic.h"
#include "storage.h"

class taskAdd
{
private:
	task _task;
	//std::vector<task> _taskStorage;
public:
	taskAdd();
	taskAdd(std::string taskString);
	~taskAdd(void);
	std::string taskAddTask();
	void taskAddRecurrent();
	void setTask(task taskString);
};

#endif