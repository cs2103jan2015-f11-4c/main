#include "parser.h"

parser::parser(void){
}

//@author A0083864U

parser::parser(std::string commandLine){
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDate = '%';
	char symbolTime = '$';
	bool isSymbol = false;
	bool isIndex = false;
	unsigned int substringBegin = 0;


	//A0125489U
	//This method determine the 1st index of any non-alphanumeric character (exclude blankspace too)
	std::size_t found = commandLine.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ");
	//This operator determine whether the commandLine contains any symbol
	std::size_t index = commandLine.find_first_of("1234567890");
	if(found != std::string::npos){
		isSymbol=true;
		if(index < found){
			isIndex = true;
		}
	}

	//If commandLine has symbols
	if(isSymbol){	
		//A0083864U
		if(isIndex){
			commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
			_taskCommand = commandLine.substr(substringBegin, index - 1);
			commandReference.setCommandAction(_taskCommand);
		}else{
			_taskCommand = getItemsInString(commandLine, NULL);
			commandReference.setCommandAction(_taskCommand);
		}
		commandReference.setTaskTitle(getItemsInString(commandLine, symbolTitle));
		commandReference.setTaskLocation(getItemsInString(commandLine, symbolLocation));
		commandReference.setTime(getItemsInString(commandLine, symbolTime));
		commandReference.setDate(getItemsInString(commandLine, symbolDate));
	}else {
		//A0125489U
		//This method determine the 1st index of non-alpha character
		found = commandLine.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
		_taskCommand = commandLine.substr(substringBegin,found);
		commandReference.setCommandAction(_taskCommand);
		commandReference.setSearchItem(commandLine.substr(found+1, commandLine.size()));
	} 
	if(_taskCommand == "delete"){
		commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
	}
	if(_taskCommand == "done"){
		commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
	}
	if(_taskCommand == "undone"){
		commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
	}
	if(_taskCommand == "edit"){
		commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
	}
	checkAndSetTaskType(commandLine);
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

// @author A0125489U

std::string parser::getItemsInString(std::string inputString, char itemType){
	unsigned int substringBegin;
	unsigned int substringEnd;
	char blankSpace=0;
	char checkSpace;
	std::string symbols = "&@#%$";
	std::string itemString;

	if(itemType == '\0'){
		//This operator determine whether inputString contains any symbol
		if(!inputString.find("&") && !inputString.find("@") && !inputString.find("#") && !inputString.find("%") && !inputString.find("$")!= std::string::npos){
			return inputString;
		}
		substringBegin = 0;
		substringEnd = inputString.find_first_of(symbols);
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
	itemString = inputString.substr(substringBegin,substringEnd - substringBegin);

	// This while loop remove trailing whitespaces
	while(itemString.size() >0 && itemString.compare(itemString.size() - 1 ,1 , " ") == 0){
		itemString.erase(itemString.end() -1);
	}
	substringEnd = itemString.size();
	return inputString.substr(substringBegin,substringEnd);
}

std::string parser::getTaskCommand(){
	return _taskCommand;
}

commandRef parser::getCommandRef(){
	return commandReference;
}

//@author A0114411B

std::vector<std::string> parser::detokenizeCommandLine(std::string commandLine){
	std::string buffer; 
	std::stringstream ss(commandLine);

	std::vector<std::string> tokens; 

	while (ss >> buffer){
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
		tokens.push_back(buffer);
	}

	return tokens;
}

//@author A0114411B

void parser::checkAndSetTaskType(std::string commandLine){
	std::vector<std::string> detokenizedVector = detokenizeCommandLine(commandLine);

	for(auto i=0; i<detokenizedVector.size(); i++){
		if(detokenizedVector[i].compare(DATE_DEADLINE_DUE) == 0 ||
			detokenizedVector[i].compare(DATE_DEADLINE_BEFORE) == 0 ||
			detokenizedVector[i].compare(DATE_DEADLINE_BY) == 0){
				commandReference.setTaskType(DEAD_LINE);
				return;
		}
	}

	if(commandReference.getDate() != "" && commandReference.getTime() != ""){
		commandReference.setTaskType(TIMED_TASK);
	} else if(commandReference.getDate() != "" && commandReference.getTime() == "" ||
		commandReference.getDate() == "" && commandReference.getTime() == "" ||
		commandReference.getDate() == "" && commandReference.getTime() != ""){
			commandReference.setTaskType(FLOATING_TASK);
	}
}