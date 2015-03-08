#include "parser.h"
#include <iostream>
#include <ctype.h>
#include <ctime>
#include <string>

parser::parser(void){
	_taskCommand = "";
	_taskTitle = "";
	_taskLocation = "";
	_taskDescription = "";
	_taskDateAndTime = "";
}

parser::parser(std::string commandLine){
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';
	char symbolTimeAndDate = '$';

	_taskCommand = getItemsInString(commandLine, NULL);
	_taskTitle = getItemsInString(commandLine, symbolTitle);
	_taskLocation = getItemsInString(commandLine, symbolLocation);
	_taskDescription = getItemsInString(commandLine, symbolDescription);
	_taskDateAndTime = getItemsInString(commandLine, symbolTimeAndDate);
}

parser::~parser(void){
}

std::string getItemsInString(std::string inputString, char itemType){
	unsigned int substringBegin;
	unsigned int substringEnd;
	std::string symbols = "@#$%&";

	if(itemType == NULL){
		substringBegin = 0;
		substringEnd = inputString.find_first_of(symbols);
	} else{
		substringBegin = inputString.find_first_of(itemType) + 1;
		substringEnd = inputString.find_first_of(symbols, substringBegin);
		if(substringEnd == std::string::npos){ //print last token
			return inputString.substr(substringBegin);
		}
	}
	return inputString.substr(substringBegin,substringEnd - substringBegin);
}

time_t parser::convertDateAndTime(std::string _taskDateAndTime){
	struct tm DateAndTime;
	strftime((char*)_taskDateAndTime.c_str(),_taskDateAndTime.size(), "%d%m%y %H:%M", &DateAndTime);
	time_t t = mktime(&DateAndTime);

	return t;
}

//put in logic
commandType hashCommandAction(std::string commandAction){
	std::string commandAdd = "add";
	std::string commandDelete = "delete";
	std::string commandView = "view";
	std::string commandDisplay = "display" ;
	std::string commandEdit = "edit";
	std::string commandUndo = "undo";
	std::string commandRepeat = "repeat";
	std::string commandSpecify = "specify";
	std::string commandRedo = "redo";
	std::string commandToggle = "toggle";
	if(commandAction.compare(commandAdd) == 0){ 
		return ADD;
	}
	if(commandAction.compare(commandDelete) == 0){ 
		return DELETE;
	}
	if(commandAction.compare(commandView) == 0){ 
		return VIEW;
	}
	if(commandAction.compare(commandDisplay) == 0){ 
		return DISPLAY;
	}
	if(commandAction.compare(commandEdit) == 0){ 
		return EDIT;
	}
	if(commandAction.compare(commandUndo) == 0){ 
		return UNDO;
	}
	if(commandAction.compare(commandRepeat) == 0){ 
		return REPEAT;
	}
	if(commandAction.compare(commandSpecify) == 0){ 
		return SPECIFY;
	}
	if(commandAction.compare(commandRedo) == 0){ 
		return REDO;
	}
	if(commandAction.compare(commandToggle) == 0){ 
		return TOGGLE;
	}
}

	std::string parser::getTaskCommand(){
		return _taskCommand;
	}

	std::string parser::getTaskTitle(){
		return _taskTitle;
	}

	std::string parser::getTaskLocation(){
		return _taskLocation;
	}

	std::string parser::getTaskDescription(){
		return _taskDescription;
	}

	time_t parser::getTaskTimeAndDate(){
		return convertDateAndTime(_taskDateAndTime);
	}

//put in logic
void parser::readCommand(std::string commandLine){
	std::string commandAction = getItemsInString(commandLine, NULL);
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';

	switch(hashCommandAction(commandAction)){
	case ADD:
		parser::_taskTitle = getItemsInString(commandLine, symbolTitle);
		parser::_taskLocation = getItemsInString(commandLine, symbolLocation);
		parser::_taskDescription = getItemsInString(commandLine, symbolDescription);
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case DELETE:
		parser::_taskTitle = getItemsInString(commandLine, symbolTitle);
		parser::_taskLocation = getItemsInString(commandLine, symbolLocation);
		parser::_taskDescription = getItemsInString(commandLine, symbolDescription);
		break;
	case VIEW:
		parser::_taskTitle = getItemsInString(commandLine, symbolTitle);
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case DISPLAY:
		//Shijia: what should I put here?
		break;
	case EDIT:
		parser::_taskTitle = getItemsInString(commandLine, symbolTitle);
		parser::_taskLocation = getItemsInString(commandLine, symbolLocation);
		parser::_taskDescription = getItemsInString(commandLine, symbolDescription);
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case UNDO:
		//Shijia: what should I put here?
		break;
	case REPEAT:
		//Shijia: what should I put here?
		break;
	case SPECIFY:
		//Shijia: what should I put here?
		break;
	case REDO:
		//Shijia: what should I put here?
		break;
	case TOGGLE:
		//Shijia: what should I put here?
		break;
	default:
		break;
	}
}