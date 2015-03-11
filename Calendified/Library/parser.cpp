#include "parser.h"
#include <iostream>
#include <ctype.h>
#include <time.h>
#include <string>
#include "taskRef.h"

#include <sstream>

parser::parser(void){
}

parser::parser(std::string commandLine){
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';
	char symbolDate = '%';
	char symbolTime = '$';

	_taskCommand = getItemsInString(commandLine, NULL);
	taskReference.setTaskTitle(getItemsInString(commandLine, symbolTitle));
	taskReference.setTaskLocation(getItemsInString(commandLine, symbolLocation));
	taskReference.setTaskDescription(getItemsInString(commandLine, symbolDescription));
	taskReference.setTaskDate(getItemsInString(commandLine, symbolDate));
	taskReference.setTaskTime(getItemsInString(commandLine, symbolTime));
}

parser::~parser(void){
}

std::string parser::getItemsInString(std::string inputString, char itemType){
	unsigned int substringBegin;
	unsigned int substringEnd;
	std::string symbols = "&@#%$";

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
	while(inputString[substringEnd] == ' '){
		substringEnd = substringEnd - 1;
	}
	return inputString.substr(substringBegin,substringEnd - substringBegin);
}
<<<<<<< HEAD
=======

time_t parser::convertDate(std::string _taskDate){
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

time_t parser::convertTime(std::string _taskTime){
	struct tm Time;
	int outNum;
	std::istringstream in(_taskDate);
	
	in >> outNum;
	Time.tm_mday = outNum;

	char ignore;
	in >> ignore;

	in >> outNum;
	Time.tm_mon = outNum;

	time_t t1 = mktime(&Time);

	return t1;
}


>>>>>>> 985ba5fb54effb148456d540fb573ad404fa2d74
std::string parser::getTaskCommand(){
	return _taskCommand;
}
taskRef parser::getTaskRef(){
	return taskReference;
}
//time_t parser::convertDate(std::string _taskDate){
//	struct tm Date;
//	strftime((char*)_taskDate.c_str(),_taskDate.size(), "%d/%m/%y", &Date);
//	time_t t = mktime(&Date);
//
//	return t;
//}
//
//time_t parser::convertTime(std::string _taskTime){
//	struct tm Time;
//	strftime((char*)_taskTime.c_str(),_taskTime.size(), "%H:%M", &Time);
//	time_t t1 = mktime(&Time);
//
//	return t1;
//}



//
//std::string parser::getTaskTitle(){
//	return _taskTitle;
//}
//
//std::string parser::getTaskLocation(){
//	return _taskLocation;
//}
//
//std::string parser::getTaskDescription(){
//	return _taskDescription;
//}
//
//time_t parser::getTaskDate(){
//	return convertDate(_taskDate);
//}
//
//time_t parser::getTaskTime(){
//	return convertTime(_taskTime);
//}
