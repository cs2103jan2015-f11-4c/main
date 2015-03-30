//@author shijia
#include "commandRef.h"

commandRef::commandRef(void){
	_taskTitle = "";
	_taskLocation = "";
	_taskDescription = "";
	_taskDate = "01/01/00";
	_taskTime = "00:00";
}

commandRef::~commandRef(void){
}

std::string commandRef::getTaskTitle(){
	return _taskTitle;
}

commandRef commandRef::copyTo(){
	commandRef newRef;
	newRef.setTaskDate(_taskDate);
	newRef.setTaskDescription(_taskDescription);
	newRef.setTaskLocation(_taskLocation);
	newRef.setTaskTime(_taskTime);
	newRef.setTaskTitle(_taskTitle);
	newRef.setIndexToBeDeleted(_indexToBeDeleted);
	newRef.setIndexToBeEdited(_indexToBeEdited);
	return newRef;
}

std::string commandRef::getTaskLocation(){
	return _taskLocation;
}

std::string commandRef::getTaskDescription(){
	return _taskDescription;
}

//@author A0116027R
std::string commandRef::getTaskDateInString(){
	struct tm Date = {0};
	char storeDate [20] = {0};
	char ignore;
	int outNum;

	if (_taskDate != ""){
	std::istringstream in(_taskDate);
	
	in >> outNum;
	Date.tm_mday = outNum;

	in >> ignore;

	in >> outNum;
	Date.tm_mon = outNum-1; //months since January

	in >> ignore;

	in >> outNum;
	Date.tm_year = outNum - 1900; //years since 1900

	mktime(&Date);

	int mday = Date.tm_mday;
	int mon = Date.tm_mon + 1;
	int year = Date.tm_year + 1900;

	strftime(storeDate, 20, "%d/%m/%Y", &Date);

	return storeDate;
	} else
		return "";
	}

//@author A0116027R
std::string commandRef::getTaskTimeInString(){
	struct tm Time = {0};
	char storeTime [20] = {0};
	char ignore;
	int outNum;

	if(_taskTime != ""){
	std::istringstream in(_taskTime);
	
	in >> outNum;
	Time.tm_hour = outNum;

	in >> ignore;

	in >> outNum;
	Time.tm_min = outNum;

	mktime(&Time);

	int hour = Time.tm_hour;
	int min = Time.tm_min;

	strftime(storeTime, 20, "%H:%M", &Time);

	return storeTime;
	} else {
		return "";
	}
}

std::string commandRef::getTaskTimeAndDateInString(){
	return getTaskDateInString() + " " + getTaskTimeInString();
}

int commandRef::getIndexToBeDeleted(){
	return _indexToBeDeleted;
}
int commandRef::getIndexToBeEdited(){
	return _indexToBeEdited;
}

void commandRef::setTaskTitle(std::string taskTitle){
	_taskTitle = taskTitle;
}

void commandRef::setTaskLocation(std::string taskLocation){
	_taskLocation = taskLocation;
}

void commandRef::setTaskDescription(std::string taskDescription){
	_taskDescription = taskDescription;
}

void commandRef::setTaskDate(std::string taskDate){
	_taskDate = taskDate;
}

void commandRef::setTaskTime(std::string taskTime){
	_taskTime = taskTime;
}

void commandRef::setIndexToBeDeleted(int indexToBeDeleted){
	_indexToBeDeleted = indexToBeDeleted;
}

void commandRef::setIndexToBeEdited(int indexToBeEdited){
	_indexToBeEdited = indexToBeEdited;
}

//@author A0116027R
std::string commandRef::dataToString(){
	std::string taskDate = "";
	std::string taskTime = "";
	std::string taskTitle = "";
	std::string taskDescription = "";
	std::string taskLocation = "";

	if(_taskDate != ""){
		taskDate = getTaskDateInString() + " ";
	}

	if(_taskTime != ""){
		taskTime = getTaskTimeInString() + " ";
	}

	if(_taskTitle != ""){
		taskTitle = _taskTitle + " ";
	}

	if(_taskDescription != ""){
		taskDescription = "(" + _taskDescription + ") ";
	}

	if(_taskLocation != ""){
		taskLocation = "@" + _taskLocation;
	}

	return taskDate +
		   taskTime +
		   taskTitle +
		   taskDescription +
		   taskLocation;
}

void commandRef::stringTodata(std::string dataInString){
	int cutBeginIndex = 0;
	int cutEndIndex;
	char cutSymbol = ' ';
	cutEndIndex = dataInString.find_first_of(cutSymbol);
	_taskDate = dataInString.substr(cutBeginIndex, cutEndIndex -cutBeginIndex);
	cutBeginIndex = cutEndIndex + 1;

	cutEndIndex = dataInString.find_first_of(cutSymbol,cutBeginIndex);
	_taskTime = dataInString.substr(cutBeginIndex, cutEndIndex -cutBeginIndex);
	cutBeginIndex = cutEndIndex + 1;

	cutSymbol = '-';
	cutEndIndex = dataInString.find_first_of(cutSymbol,cutBeginIndex);
	_taskTitle = dataInString.substr(cutBeginIndex, cutEndIndex -cutBeginIndex);
	cutBeginIndex = cutEndIndex + 1;

	cutSymbol = '@';
	cutEndIndex = dataInString.find_first_of(cutSymbol,cutBeginIndex);
	_taskDescription = dataInString.substr(cutBeginIndex, cutEndIndex -cutBeginIndex);
	cutBeginIndex = cutEndIndex + 1;

	_taskLocation = dataInString.substr(cutBeginIndex);
}

std::string commandRef::getSearchItem(){
	return _searchItem;
}

void commandRef::setSearchItem(std::string searchItem){
	_searchItem = searchItem;
}

commandRef commandRef::compareAndSetTaskData(commandRef oldTaskData){
	std::string temp;

	temp = _taskDate;
	if( temp != ""){
		oldTaskData.setTaskDate(temp);
	}

	temp = _taskDescription;
	if( temp != ""){
		oldTaskData.setTaskDescription(temp);
	}

	temp = _taskLocation;
	if(temp != ""){
		oldTaskData.setTaskLocation(temp);
	}

	temp = _taskTime;
	if( temp != ""){
		oldTaskData.setTaskTime(temp);
	}

	temp = _taskTitle;
	if( temp != ""){
		oldTaskData.setTaskTitle(temp);
	}
	return oldTaskData;
}