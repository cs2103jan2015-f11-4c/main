//@author shijia
#include "taskRef.h"

taskRef::taskRef(void){
	_taskTitle = "";
	_taskLocation = "";
	_taskDescription = "";
	_taskDate = "01/01/00";
	_taskTime = "00:00";
}

taskRef::~taskRef(void){
}

std::string taskRef::getTaskTitle(){
	return _taskTitle;
}

taskRef taskRef::copyTo(){
	taskRef newRef;
	newRef.setTaskDate(_taskDate);
	newRef.setTaskDescription(_taskDescription);
	newRef.setTaskLocation(_taskLocation);
	newRef.setTaskTime(_taskTime);
	newRef.setTaskTitle(_taskTitle);
	newRef.setIndexToBeDeleted(_indexToBeDeleted);
	return newRef;
}

std::string taskRef::getTaskLocation(){
	return _taskLocation;
}

std::string taskRef::getTaskDescription(){
	return _taskDescription;
}
time_t taskRef::getTaskDate(){
	struct tm Date;

	int outNum;
	std::istringstream in(_taskDate);
	
	in >> outNum;
	Date.tm_mday = outNum;

	char ignore;

	in >> ignore;

	in >> outNum;
	Date.tm_mon = outNum;

	in >> ignore;

	in >> outNum;
	Date.tm_year = outNum;

	time_t t = mktime(&Date);

	return t;
}

std::string taskRef::getTaskDateInString(){
	return _taskDate;
}

time_t taskRef::getTaskTime(){
	struct tm Time;
	int outNum;
	std::istringstream in(_taskDate);
	
	in >> outNum;
	Time.tm_hour = outNum;

	char ignore;
	in >> ignore;

	in >> outNum;
	Time.tm_min = outNum;

	time_t t1 = mktime(&Time);

	return t1;
}

std::string taskRef::getTaskTimeInString(){
	return _taskTime;
}

time_t taskRef::getTaskTimeAndDate(){
	std::string _timeAndDate = _taskTime + _taskDate;

	struct tm timeAndDate;

	char ignore;
	int outNum;
	std::istringstream in(_timeAndDate);
	
	in >> outNum;
	timeAndDate.tm_hour = outNum;

	in >> ignore;

	in >> outNum;
	timeAndDate.tm_min = outNum;

	in >> outNum;
	timeAndDate.tm_mday = outNum;
	
	in >> ignore;

	in >> outNum;
	timeAndDate.tm_mon = outNum;

	in >> ignore;

	in >> outNum;
	timeAndDate.tm_year = outNum;


	time_t t = mktime(&timeAndDate);

	return t;
}

std::string taskRef::getTaskTimeAndDateInString(){
	return _taskTime + " " + _taskDate;
}

int taskRef::getIndexToBeDeleted(){
	return _indexToBeDeleted;
}

void taskRef::setTaskTitle(std::string taskTitle){
	_taskTitle = taskTitle;
}

void taskRef::setTaskLocation(std::string taskLocation){
	_taskLocation = taskLocation;
}

void taskRef::setTaskDescription(std::string taskDescription){
	_taskDescription = taskDescription;
}

void taskRef::setTaskDate(std::string taskDate){
	_taskDate = taskDate;
}

void taskRef::setTaskTime(std::string taskTime){
	_taskTime = taskTime;
}

void taskRef::setIndexToBeDeleted(int indexToBeDeleted){
	_indexToBeDeleted = indexToBeDeleted;
}

std::string taskRef::dataToString(){

	return _taskDate + "/" +
		   _taskTime + "/" + 
		   _taskTitle + "/" + 
		   _taskDescription + "/" +
		   _taskLocation + "\n";
}

std::string taskRef::getSearchItem(){
	return _searchItem;
}

void taskRef::setSearchItem(std::string searchItem){
	_searchItem = searchItem;
}






