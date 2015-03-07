#include "parser.h"
#include <iostream>
#include <ctype.h>
#include <ctime>

enum commandType { // this class should put in another file included by all cpp file
	ADD, 
	DELETE, 
	VIEW,
	DISPLAY, 
	EDIT, 
	UNDO, 
	REPEAT, 
	SPECIFY, 
	REDO, 
	TOGGLE 
};
class parser{
private:
	commandType commandAction;
	std::string taskTitle;
	std::string taskLocation;
	std::string taskDescription;
	std::time_t taskTimeAndDate;// use time_t type for easily sort the tasks in scheduled order
	std::string getItemsInString(std::string inputString, char itemType);
	commandType hashCommandAction(std::string commandAction);
	time_t stringToTimeAndDate(std::string timeAndDate);// not finished yet, use the links in the resource doc in google drive
	parser();
	~parser();
	void readCommand(std::string commandLine);
	std::string getTaskTitle();
	std::string getTaskLocation();
	std::string getTaskDescription();
	time_t getTaskTimeAndDate();
};
parser::parser(void)
{
	taskDescription = "";
	taskLocation = "";
	taskTitle = "";
	taskTimeAndDate = time(0);
}

parser::~parser(void)
{
}

std::string getItemsInString(std::string inputString, char itemType){
	int substringBegin;
	int substringEnd;
	std::string symbols = "@#$%& ";
	if(itemType == NULL){
		substringBegin = 0;
		substringEnd = inputString.find_first_of(symbols);
	}else {
		substringBegin = inputString.find_first_of(itemType) + 1;
		substringEnd = inputString.find_first_of(symbols, substringBegin);
	}
	return inputString.substr(substringBegin,substringEnd - substringBegin);
}
void parser::readCommand(std::string commandLine){
	
	std::string commandAction = getItemsInString(commandLine, NULL);
	switch(hashCommandAction(commandAction)){
	case ADD:
		parser::taskTitle = getItemsInString(commandLine, '&');
		parser::taskLocation = getItemsInString(commandLine, '@');
		parser::taskDescription = getItemsInString(commandLine, '#');
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case DELETE:
		parser::taskTitle = getItemsInString(commandLine, '&');
		parser::taskLocation = getItemsInString(commandLine, '@');
		parser::taskDescription = getItemsInString(commandLine, '#');
		break;
	case VIEW:
		parser::taskTitle = getItemsInString(commandLine, '&');
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case DISPLAY:
		//Shijia: what should I put here?
		break;
	case EDIT:
		parser::taskTitle = getItemsInString(commandLine, '&');
		parser::taskLocation = getItemsInString(commandLine, '@');
		parser::taskDescription = getItemsInString(commandLine, '#');
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

	// add, delete, view, display, edit, undo, repeat ,
	// specify, redo, toggle, 
}

commandType hashCommandAction(std::string commandAction){
	std::string commandADD = "add";
	std::string commandDELETE = "delete";
	std::string commandVIEW = "view";
	std::string commandDISPLAY = "display" ;
	std::string commandEDIT = "edit";
	std::string commandUNDO = "undo";
	std::string commandREPEAT = "repeat";
	std::string commandSPECIFY = "specify";
	std::string commandREDO = "redo";
	std::string commandTOGGLE = "toggle";
	if(commandAction.compare(commandADD) == 0) 
		return ADD;
	if(commandAction.compare(commandDELETE) == 0) 
		return DELETE;
	if(commandAction.compare(commandVIEW) == 0) 
		return VIEW;
	if(commandAction.compare(commandDISPLAY) == 0) 
		return DISPLAY;
	if(commandAction.compare(commandEDIT) == 0) 
		return EDIT;
	if(commandAction.compare(commandUNDO) == 0) 
		return UNDO;
	if(commandAction.compare(commandREPEAT) == 0) 
		return REPEAT;
	if(commandAction.compare(commandSPECIFY) == 0) 
		return SPECIFY;
	if(commandAction.compare(commandREDO) == 0) 
		return REDO;
	if(commandAction.compare(commandTOGGLE) == 0) 
		return TOGGLE;

}


