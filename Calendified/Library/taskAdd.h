//A0116027R

#ifndef TASKADD_H
#define TASKADD_H

#pragma once
#include <iostream>
#include <vector>

class taskAdd
{
private:
	std::string _task;
	std::vector<std::string> _taskStorage;
public:
	taskAdd(std::string taskString);
	~taskAdd(void);
	std::string taskAddTask();
	void taskAddRecurrent();
	void taskAddTitle(); //floating task
	void taskAddLocation(); //floating task
	void taskAddDescription(); //floating task
};

#endif
