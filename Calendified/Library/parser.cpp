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

std::string parser::getItemsInString(std::string inputString, char itemType){
	unsigned int substringBegin;
	unsigned int substringEnd;
	std::string symbols = "@#$%&";

	if(itemType == '\0'){
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

