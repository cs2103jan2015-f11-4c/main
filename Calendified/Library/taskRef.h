#pragma once
#ifndef TASKREF_H
#define TASKREF_H
#include <iostream>

class taskRef
{
private:

	std::string _taskTitle;
	std::string _taskLocation;
	std::string _taskDescription;
	std::string _taskDate;
	std::string _taskTime;
	int _indexToBeDeleted;

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
	time_t getTaskTime();
	std::string getTaskTimeInString();
	time_t getTaskDate();
	std::string getTaskDateInString();
	time_t getTaskTimeAndDate();
	std::string getTaskTimeAndDateInString();
	int getIndexToBeDeleted();

	//set method: use this to assign value to data;
	void setTaskTitle(std::string taskTitle);
	void setTaskLocation(std::string taskTitle);	
	void setTaskDescription(std::string taskDescription);
	void setTaskDate(std::string taskDate);
	void setTaskTime(std::string taskTime);
	void setIndexToBeDeleted(int indexToBeDeleted);

	//toString: format the data in string to store in the file (the format can be changed if wish);
	std::string dataTostring();
};

#endif
