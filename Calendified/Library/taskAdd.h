//@author A0116027R

#ifndef TASKADD_H
#define TASKADD_H

#pragma once
#include <iostream>
#include <vector>
#include "logic.h"
#include "storage.h"

class taskAdd
{
private:
	std::string _task;
	std::vector<std::string> _taskStorage;
public:
	taskAdd();
	taskAdd(std::string taskString);
	~taskAdd(void);
	std::string taskAddTask();
	void taskAddRecurrent();
	void taskAddTitle(); //floating task
	void taskAddLocation(); //floating task
	void taskAddDescription(); //floating task
	void set_task(std::string taskString);
};

#endif
