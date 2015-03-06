#include "parser.h"
#include <iostream>
#include <ctype.h>

enum commandType { ADD, DELETE };

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

	if (command.compare(commandADD) == 0 ){
		return "added";
	}
	else if (command.compare(commandDELETE) == 0 ){
			return "deleted";
		} else {
			return "invalid";
	}

	// add, delete, view, display, edit, undo, repeat ,
	// specify, redo, toggle, 
}



