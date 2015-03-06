#include "parser.h"
#include <iostream>
#include <ctype.h>

enum commandType { 
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

parser::parser(void)
{
}

parser::~parser(void)
{
}

std::string parser::readCommand(std::string command){
	
 /*switch (str2int(s)){
	case str2int("add"):
		return "added";

	case str2int("delete"):
		return "deleted";

	default:
		return "invalid";
	}
	*/

	std::string commandADD = "add";
	std::string commandDELETE = "delete";
	std::string tolower(command);

	if (command.compare(commandADD) == 0){
		return "added";
	}
	else
		if (command.compare(commandDELETE)== 0){
			return "deleted";
		}

	// add, delete, view, display, edit, undo, repeat ,
	// specify, redo, toggle, 
}

//commandType hashString(std::string inputString){
//	if(inputString == "add") 
//		return ADD;
//	if(inputString == "delete") 
//		return DELETE;
//	if(inputString == "view") 
//		return VIEW;
//	if(inputString == "display") 
//		return DISPLAY;
//	if(inputString == "edit") 
//		return EDIT;
//	if(inputString == "undo") 
//		return UNDO;
//	if(inputString == "repeat") 
//		return REPEAT;
//	if(inputString == "specify") 
//		return SPECIFY;
//	if(inputString == "redo") 
//		return REDO;
//	if(inputString == "toggle") 
//		return TOGGLE;
//
//
//}


