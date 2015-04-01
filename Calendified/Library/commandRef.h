//@author shijia
#pragma once
#ifndef commandRef_H
#define commandRef_H

#include <iostream>
#include <string>
#include <ctype.h>
#include <ctime>
#include <sstream>
#include <assert.h>
#include "timeAndDate.h"

class commandRef
{
private:
	std::string _taskType; //  FloatingTask, TimedTask, DeadLine
	std::string _time;
	std::string _date;
	std::string _taskTitle;
	std::string _taskLocation;
	std::string _searchItem;
	int _indexToBeActOn;
	std::string _commandAction;
	bool _isDone;

public:
	//constructor
	commandRef(void);
	//destructor
	~commandRef(void);
	//copy: copy all data into new same type object;
	commandRef copyTo();
	//get method: use this to retrive data;
	std::string getTaskType();
	std::string getTime();
	std::string getDate();
	std::string getTaskTitle();
	std::string getTaskLocation();
	int getIndexToBeActOn();
	std::string getSearchItem();
	std::string getCommandAction();
	bool getIsDone();

	//set method: use this to assign value to data;
	void setTaskType(std::string taskType);
	void setTime(std::string time);
	void setDate(std::string date);
	void setTaskTitle(std::string taskTitle);
	void setTaskLocation(std::string taskLocation);	
	void setIndexToBeActOn(int indexToBeActOn);
	void setSearchItem(std::string searchItem);
	void setCommandAction(std::string commandAction);
	void setIsDone(bool isDone);

	//toString: format the data in string to store in the file (the format can be changed if wish);
	std::string dataToString();
	void stringTodata(std::string dataInString);
	commandRef compareAndSetTaskData(commandRef oldTaskData);
};

#endif
