//@author shijia
#include "commandRef.h"

commandRef::commandRef(void){
	_taskTitle = "";
	_taskLocation = "";
	_taskDescription = "";
	_searchItem = '\0';
	_indexToBeDeleted = 0;
	_indexToBeEdited = 0;
	_indexToBeActOn = 0;
	_isDone = false;
}

commandRef::~commandRef(void){
}

std::string commandRef::getTaskTitle(){
	return _taskTitle;
}

commandRef commandRef::copyTo(){
	commandRef newRef;
	newRef.setTimeAndDate(_timeAndDate);
	newRef.setTaskDescription(_taskDescription);
	newRef.setTaskLocation(_taskLocation);
	newRef.setTaskTitle(_taskTitle);
	newRef.setIndexToBeDeleted(_indexToBeDeleted);
	newRef.setIndexToBeEdited(_indexToBeEdited);
	newRef.setIsDone(false);
	return newRef;
}

timeAndDate commandRef::getTimeAndDate(){
	return _timeAndDate;
}

std::string commandRef::getTaskLocation(){
	return _taskLocation;
}

std::string commandRef::getTaskDescription(){
	return _taskDescription;
}


int commandRef::getIndexToBeDeleted(){
	return _indexToBeDeleted;
}
int commandRef::getIndexToBeEdited(){
	return _indexToBeEdited;
}

bool commandRef::getIsDone(){
	return _isDone;
}

void commandRef::setTimeAndDate(timeAndDate timeAndDate){
	_timeAndDate = timeAndDate;
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

void commandRef::setIndexToBeDeleted(int indexToBeDeleted){
	_indexToBeDeleted = indexToBeDeleted;
}

void commandRef::setIndexToBeEdited(int indexToBeEdited){
	_indexToBeEdited = indexToBeEdited;
}

void commandRef::setIsDone(bool isDone){
	_isDone = isDone;
}

//@author A0116027R
std::string commandRef::dataToString(){
	std::string taskTitle = "";
	std::string taskDescription = "";
	std::string taskLocation = "";

	if(_taskTitle != ""){
		taskTitle = _taskTitle + " ";
	}

	if(_taskDescription != ""){
		taskDescription = "(" + _taskDescription + ") ";
	}

	if(_taskLocation != ""){
		taskLocation = "@" + _taskLocation;
	}

	return taskTitle +
		   taskDescription +
		   taskLocation;
}

void commandRef::stringTodata(std::string dataInString){
	int cutBeginIndex = 0;
	int cutEndIndex;
	char cutSymbol = ' ';
	cutEndIndex = dataInString.find_first_of(cutSymbol);
	//_taskDate = dataInString.substr(cutBeginIndex, cutEndIndex -cutBeginIndex);
	cutBeginIndex = cutEndIndex + 1;

	cutEndIndex = dataInString.find_first_of(cutSymbol,cutBeginIndex);
	//_taskTime = dataInString.substr(cutBeginIndex, cutEndIndex -cutBeginIndex);
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

	temp = _taskDescription;
	if( temp != ""){
		oldTaskData.setTaskDescription(temp);
	}

	temp = _taskLocation;
	if(temp != ""){
		oldTaskData.setTaskLocation(temp);
	}

	temp = _taskTitle;
	if( temp != ""){
		oldTaskData.setTaskTitle(temp);
	}
	return oldTaskData;
}