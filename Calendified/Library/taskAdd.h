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
	std::string toString(); //put in logic?
	bool readingFile(std::string fileName, std::vector<std::string> _taskStorage);
	bool writingFile(std::string fileName, std::vector<std::string> _taskStorage);
	void taskAddTask(std::string, std::vector<std::string> _taskStorage);
	void taskAddRecurrent(std::string);
	void taskAddTitle(std::string); //floating task
	void taskAddLocation(std::string); //floating task
	void taskAddDescription(std::string); //floating task
	bool isAdded(int sizeBeforeAdd, int sizeAfterAdd);

	~taskAdd(void);
};

#endif
