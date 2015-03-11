#include "parser.h"

parser::parser(void){
}

parser::parser(std::string commandLine){
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';
	char symbolDate = '%';
	char symbolTime = '$';
	bool isSymbol = false;
	unsigned int substringBegin = 0;
	const std::string commandDelete = "delete";

	//@author A0125489U
	//This method determine the 1st index of any non-alphanumeric character (exclude blankspace too)
	std::size_t found = commandLine.find_first_not_of("abcdefghijklmnopqrstuvwxyz1234567890 ");
	//This operator determine whether the commandLine contains any symbol
	if(found != std::string::npos){
		isSymbol=true;
	}

	//If commandLine has symbols
	if(isSymbol){	
		//@author ???
		_taskCommand = getItemsInString(commandLine, NULL);
		taskReference.setTaskTitle(getItemsInString(commandLine, symbolTitle));
		taskReference.setTaskLocation(getItemsInString(commandLine, symbolLocation));
		taskReference.setTaskDescription(getItemsInString(commandLine, symbolDescription));
		taskReference.setTaskDate(getItemsInString(commandLine, symbolDate));
		taskReference.setTaskTime(getItemsInString(commandLine, symbolTime));
	}else{
		//@author A0125489U
		//This method determine the 1st index of non-alpha character
		found = commandLine.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
		_taskCommand = commandLine.substr(substringBegin,found);
		taskReference.setSearchItem(commandLine.substr(found+1, commandLine.size()));

		//@author A0114411B
		//This operator determine whether commandLine is a Delete operation
		if(_taskCommand.compare(commandDelete)==0){
			taskReference.setIndexToBeDeleted(getItemInInteger(commandLine));
		}
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
	char blankSpace=0;
	char checkSpace;
	std::string symbols = "&@#%$";

	if(itemType == '\0'){
		// @author A0125489U
		//This operator determine whether inputString contains any symbol
		if(!inputString.find("&") && !inputString.find("@") && !inputString.find("#") && !inputString.find("%") && !inputString.find("$")!= std::string::npos){
			return inputString;
		}
		substringBegin = 0;
		substringEnd = inputString.find_first_of(symbols);
		std::string inputCommand = inputString.substr(substringBegin,substringEnd);
		
		// @author A0125489U
		// This while loop remove trailing whitespaces
		while(inputCommand.size()>0 && inputCommand.compare(inputCommand.size()-1,1," ")==0){
			inputCommand.erase(inputCommand.end()-1); 
		}
		substringEnd = inputCommand.size();

		//@author ??
	} else{
		if(inputString.find(itemType) != std::string::npos){
			substringBegin = inputString.find_first_of(itemType) + 1;
			substringEnd = inputString.find_first_of(symbols, substringBegin);
			if(substringEnd == std::string::npos){ //print last token
				return inputString.substr(substringBegin);
			}
		} else{
			return "";
		}
	}
	//while(inputString[substringEnd] == ' '){
	//	substringEnd = substringEnd - 1;
	//}
	return inputString.substr(substringBegin,substringEnd - substringBegin);
}

std::string parser::getTaskCommand(){
	return _taskCommand;
}
taskRef parser::getTaskRef(){
	return taskReference;
}
