//author A0125489U
#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H

#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include "logic.h"
#include "storage.h"

class taskDisplay
{
private:
	storage currentStorage;

public:
	taskDisplay();
	taskDisplay(storage currentStorage);
	~taskDisplay(void);
	std::string taskAddTask();
	void taskAddRecurrent();
	void setTask(std::string taskString);
	void setTaskType(std::string taskType);
	std::string getTodayDate();
	std::string getTodayDateMonth();
	std::string getTodayDateYear();
	std::string getTodayDateDMY();
	std::string getNextDayDate();
	std::string getNextDayDateMonth();
	std::string getNextDayDateYear();
	std::string getNextDayDateDMY();
	std::string displayToday();
	std::string displayNextDay();
	std::string displayFloatDay();
	int configureCalendifedView(std::string logicResult);
	std::string configureListView(std::string logicResult);
	std::string formatDisplayResults(std::vector<task> taskList, std::string formatType);
	std::vector<task> sortTaskList(std::string sortType);
	std::string viewSearchList(std::string searchItem);
};

#endif