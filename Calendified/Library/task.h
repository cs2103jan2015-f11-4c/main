/*
#ifndef TASK_H
#define TASK_H
#pragma once

#include "time.h"
#include <ctime>
#include <iostream>

enum taskType{
	TIME_TASK,
	FLOAT_TASK
};


class task
{
private:
	taskType _taskType;
	time_t startTime;
	time_t endTime;
	std::string _date;
	std::string _title;
	std::string _location;
	std::string _descripion;
	int _indexToBeAction;


public:
	task(std::string timeString, std::string dateString, std::string title, std::string location, std::string descripion, int indexToBeAction);
	~task(void);

	void setTaskType(taskType taskType);

	bool isOverlap(time t);
};

#endif
*/