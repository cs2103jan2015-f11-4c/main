#include "logic.h"
#include "taskDelete.h"
#include <iostream>
#include <string>

logic::logic(void){
}

logic::~logic(void){
}

logic::logic(std::string command, std::string title, std::string time, std::string date, 
	  std::string location, std::string description){
		  _command = command;
		  _title = title;
		  _time = time;
		  _date = date;
		  _location = location;
		  _description = description;
}
commandType hashCommandAction(std::string commandAction);
void logic::readCommand(std::string commandLine){
	parser temp;
	std::string commandAction = temp.getItemsInString(commandLine, '\0');
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';

	std::string title,location,description;
	taskDelete deleteItem;
	std::string stringToBeDeleted ="";

	switch(hashCommandAction(commandAction)){
	case ADD:
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		location = temp.getItemsInString(commandLine, symbolLocation);
		setLocation(location);
		description = temp.getItemsInString(commandLine, symbolDescription);
		setDescription(description);
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case DELETE:
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		//_location = temp.getItemsInString(commandLine, symbolLocation);
		//_description = temp.getItemsInString(commandLine, symbolDescription);
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		location = temp.getItemsInString(commandLine, symbolLocation);
		setLocation(location);
		description = temp.getItemsInString(commandLine, symbolDescription);
		setDescription(description);

		stringToBeDeleted = title + location + description;
		deleteItem.executeDelete(stringToBeDeleted);

		break;
	case VIEW:
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case DISPLAY:
		//Shijia: what should I put here?
		break;
	case EDIT:
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		//_location = temp.getItemsInString(commandLine, symbolLocation);
		//_description = temp.getItemsInString(commandLine, symbolDescription);
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		location = temp.getItemsInString(commandLine, symbolLocation);
		setLocation(location);
		description = temp.getItemsInString(commandLine, symbolDescription);
		setDescription(description);
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

void logic::setCommand(std::string command){
	_command = command;
}

void logic::setTitle(std::string title){
	_title = title;
}

void logic::setTime(std::string time){
	_time = time;
}

void logic::setDate(std::string date){
	_date = date;
}

void logic::setLocation(std::string location){
	_location = location;
}

void logic::setDescription(std::string description){
	_description = description;
}

std::string logic::getCommand(){
	return _command;
}

std::string logic::getTitle(){
	return _title;
}

std::string logic::getTime(){
	return _time;
}
std::string logic::getDate(){
	return _date;
}
std::string logic::getLocation(){
	return _location;
}
std::string logic::getDescription(){
	return _description;
}
void logic::toParser(std::string command){
	//parser newParser;
	//newParser.readCommand(command);

	return;
}
