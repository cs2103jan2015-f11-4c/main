//author @a0114411b

#include "task.h"

task::task()
{
	_taskType = "";
	_commandAction = "";
	_title = "";
	_location = "";
	_isDone = false;
	//_indexToBeActOn = NULL;
}


task::~task(void)
{
}

//setters
void task::setTaskType(std::string taskType){
	_taskType = taskType;
}

void task::setCommandAction(std::string commandAction){
	_commandAction = commandAction;
}

void task::setTimeAndDate(timeAndDate timeAndDate){
	_timeAndDate = timeAndDate;
}

void task::setTitle(std::string title){
	_title = title;
}

void task::setLocation(std::string location){
	_location = location;
}

void task::setIsDone(bool isDone){
	_isDone = isDone;
}

//void task::setIndexToBeActOn(int indexToBeActOn){
	//_indexToBeActOn = indexToBeActOn;
//}


//getters
std::string task::getTaskType(){
	return _taskType;
}

std::string task::getCommandAction(){
	return _commandAction;
}

timeAndDate task::getTimeAndDate(){
	return _timeAndDate;
}

std::string task::getTitle(){
	return _title;
}

std::string task::getLocation(){
	return _location;
}

bool task::getIsDone(){
	return _isDone;
}

//int task::getIndexToBeActOn(){
	//return _indexToBeActOn;
//}
