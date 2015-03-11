#include "parser.h"
#include "taskRef.h"
#include <iostream>
#include <ctype.h>
#include <time.h>
#include <string>
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

	const std::string commandDelete = "delete";

	if(_taskCommand.compare(commandDelete)==0){
		taskReference.setIndexToBeDeleted(getItemInInteger(commandLine));
	}
}

parser::~parser(void){
}

int parser::getItemInInteger(std::string inputString){
	std::string dummy="";
	int indexToBeDeleted=NULL;
	std::istringstream in(inputString);
	in >> dummy;
	in >> indexToBeDeleted;
	return indexToBeDeleted;
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

std::string parser::getTaskCommand(){
	return _taskCommand;
}
taskRef parser::getTaskRef(){
	return taskReference;
}
