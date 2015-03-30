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
	timeAndDate _timeAndDate;
	std::string _taskTitle;
	std::string _taskLocation;
	std::string _taskDescription;
	std::string _searchItem;
	int _indexToBeDeleted;
	int _indexToBeEdited;
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
	timeAndDate getTimeAndDate();
	std::string getTaskTitle();
	std::string getTaskLocation();
	std::string getTaskDescription();
	int getIndexToBeDeleted();
	int getIndexToBeEdited();
	std::string getSearchItem();
	bool getIsDone();

	//set method: use this to assign value to data;
	void setTimeAndDate(timeAndDate timeAndDate);
	void setTaskTitle(std::string taskTitle);
	void setTaskLocation(std::string taskLocation);	
	void setTaskDescription(std::string taskDescription);
	void setIndexToBeDeleted(int indexToBeDeleted);
	void setIndexToBeEdited(int indexTobeEdited);
	void setSearchItem(std::string searchItem);
	void setIsDone(bool isDone);

	//toString: format the data in string to store in the file (the format can be changed if wish);
	std::string dataToString();
	void stringTodata(std::string dataInString);
	commandRef compareAndSetTaskData(commandRef oldTaskData);
};

#endif
