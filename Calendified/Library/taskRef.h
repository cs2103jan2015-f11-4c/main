//@author shijia
#pragma once
#ifndef TASKREF_H
#define TASKREF_H

#include <iostream>
#include <string>
#include <ctype.h>
#include <ctime>
#include <sstream>
#include <assert.h>

class taskRef
{
private:

	std::string _taskTitle;
	std::string _taskLocation;
	std::string _taskDescription;
	std::string _taskDate;
	std::string _taskTime;
	std::string _searchItem;
	int _indexToBeDeleted;
	int _indexToBeEdited;
	int _indexToBeActOn;

public:
	//constructor
	taskRef(void);
	//destructor
	~taskRef(void);
	//copy: copy all data into new same type object;
	taskRef copyTo();
	//get method: use this to retrive data;
	std::string getTaskTitle();
	std::string getTaskLocation();
	std::string getTaskDescription();
	std::string getTaskTimeInString();
	std::string getTaskDateInString();
	std::string getTaskTimeAndDateInString();
	int getIndexToBeDeleted();
	int getIndexToBeEdited();
	std::string getSearchItem();

	//set method: use this to assign value to data;
	void setTaskTitle(std::string taskTitle);
	void setTaskLocation(std::string taskTitle);	
	void setTaskDescription(std::string taskDescription);
	void setTaskDate(std::string taskDate);
	void setTaskTime(std::string taskTime);
	void setIndexToBeDeleted(int indexToBeDeleted);
	void setIndexToBeEdited(int indexTobeEdited);
	void setSearchItem(std::string searchItem);

	//toString: format the data in string to store in the file (the format can be changed if wish);
	std::string dataToString();
	void stringTodata(std::string dataInString);
	taskRef compareAndSetTaskData(taskRef oldTaskData);
};

#endif
