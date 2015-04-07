//@author shijia
#include "commandRef.h"

commandRef::commandRef(void){
	_taskType = '\0';
	_time = '\0';
	_date = '\0';
	_commandAction = '\0';
	_taskTitle = '\0';
	_taskLocation = '\0';
	_searchItem = '\0';
	_indexToBeActOn = NULL;
	_isDone = false;
}

commandRef::~commandRef(void){
}

commandRef commandRef::copyTo(){
	commandRef newRef;
	newRef.setTaskType(_taskType);
	newRef.setTime(_time);
	newRef.setDate(_date);
	newRef.setTaskLocation(_taskLocation);
	newRef.setTaskTitle(_taskTitle);
	newRef.setIndexToBeActOn(_indexToBeActOn);
	newRef.setIsDone(false);
	return newRef;
}


//@author A0114411B
// getters
std::string commandRef::getTaskType(){
	return _taskType;
}

std::string commandRef::getTaskTitle(){
	return _taskTitle;
}

std::string commandRef::getCommandAction(){
	return _commandAction;
}

std::string commandRef::getTime(){
	return _time;
}

std::string commandRef::getDate(){
	return _date;
}

std::string commandRef::getTaskLocation(){
	return _taskLocation;
}

int commandRef::getIndexToBeActOn(){
	return _indexToBeActOn;
}

std::string commandRef::getSearchItem(){
	return _searchItem;
}

bool commandRef::getIsDone(){
	return _isDone;
}


//@author A0114411B
// setters
void commandRef::setTaskType(std::string taskType){
	_taskType = taskType;
}

void commandRef::setCommandAction(std::string commandAction){
	_commandAction = commandAction;
}

void commandRef::setTime(std::string time){
	_time = time;
}

void commandRef::setDate(std::string date){
	_date = date;
}

void commandRef::setTaskTitle(std::string taskTitle){
	_taskTitle = taskTitle;
}

void commandRef::setTaskLocation(std::string taskLocation){
	_taskLocation = taskLocation;
}

void commandRef::setIndexToBeActOn(int indexToBeActOn){
	_indexToBeActOn = indexToBeActOn;
}

void commandRef::setSearchItem(std::string searchItem){
	_searchItem = searchItem;
}

void commandRef::setIsDone(bool isDone){
	_isDone = isDone;
}

//@author A0116027R
std::string commandRef::dataToString(){
	std::string taskTitle = "";
	std::string taskLocation = "";

	if(_taskTitle != ""){
		taskTitle = _taskTitle + " ";
	}

	if(_taskLocation != ""){
		taskLocation = "@" + _taskLocation;
	}

	return taskTitle +
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

	_taskLocation = dataInString.substr(cutBeginIndex);
}

commandRef commandRef::compareAndSetTaskData(commandRef oldTaskData){
	std::string temp;

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