//author @a0114411b

#ifndef TASK_H
#define TASK_H
#pragma once

#include "timeAndDate.h"
#include <ctime>
#include <iostream>


class task
{
private:
	std::string _taskType; //FloatingTask, DeadLine, TimedTask
	std::string _commandAction;
	timeAndDate _timeAndDate;
	std::string _title;
	std::string _location;
	bool _isDone;
	//int _indexToBeActOn;


public:
	task();
	~task(void);

	//setters
	void setTaskType(std::string taskType);
	void setCommandAction(std::string commandAction);
	void setTimeAndDate(timeAndDate timeAndDate);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setIsDone(bool isDone);
	//void setIndexToBeActOn(int indexToBeActOn);


	//getters
	std::string getTaskType();
	std::string getCommandAction();
	timeAndDate getTimeAndDate();
	std::string getTitle();
	std::string getLocation();
	bool getIsDone();
	//int getIndexToBeActOn();	
};

#endif
