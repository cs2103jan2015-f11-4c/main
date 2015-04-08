//@author A0114411B

#pragma once
#ifndef TASK_H
#define TASK_H


#include "timeAndDate.h"
#include <ctime>
#include <string>
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
	bool _isClash;
	//int _indexToBeActOn;


public:
	task();
	task(std::string taskType, std::string commandAction,timeAndDate timeAndDate, std::string title, std::string location, bool isDone, bool isClash);
	~task(void);

	//setters
	void setTaskType(std::string taskType);
	void setCommandAction(std::string commandAction);
	void setTimeAndDate(timeAndDate timeAndDate);
	void setTitle(std::string title);
	void setLocation(std::string location);
	void setIsDone(bool isDone);
	void setIsClash(bool isClash);
	//void setIndexToBeActOn(int indexToBeActOn);


	//getters
	std::string getTaskType();
	std::string getCommandAction();
	timeAndDate getTimeAndDate();
	std::string getTitle();
	std::string getLocation();
	bool getIsDone();
	bool getIsClash();
	//int getIndexToBeActOn();	
};

#endif
