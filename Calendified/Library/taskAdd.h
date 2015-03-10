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
public:
	std::vector<std::string> _taskStorage;

	taskAdd(std::string _task);
	~taskAdd(void);
	bool readingFile(std::string fileName, std::vector<std::string> _taskStorage);
	bool writingFile(std::string fileName, std::vector<std::string> _taskStorage);
	std::string taskAddTask();
	void taskAddRecurrent();
	void taskAddTitle(); //floating task
	void taskAddLocation(); //floating task
	void taskAddDescription(); //floating task
	bool isAdded(int sizeBeforeAdd, int sizeAfterAdd);
};

#endif
