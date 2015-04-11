#include "parser.h"

parser::parser(void){
}
std::vector<std::string> parser::getCommandlineItem(std::string commandLine){

	char blankSpace = ' ';
	unsigned int substringBegin = 0;
	unsigned int substringEnd = 0;
	
	std::vector<std::string> commandLineItemData;
	while(substringEnd != std::string::npos){
		substringEnd = commandLine.find(blankSpace, substringBegin);
		commandLineItemData.push_back(commandLine.substr(substringBegin,substringEnd - substringBegin));
		substringBegin = substringEnd + 1;
		
	}
	return commandLineItemData;

}
parser::parser(std::string commandLine){
	/*char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDate = '%';
	char symbolTime = '$';*/
	bool isSymbol = false;
	bool isIndex = false;
	unsigned int substringBegin = 0;
	int timeDataPosition = 0;
	int dateDataPosition = 0;
	int taskIndexPosition = 0;	int taskTitleDataStartPosition = 0;	int taskTitleDataEndPosition = 0;	int taskLocationDataStartPosition = 0;	int taskLocationDataEndPosition = 0;	std::vector<std::string> commandLineDataContainer;	commandLineDataContainer = getCommandlineItem(commandLine);		//@author A0125489U	//This method determine the 1st index of any non-alphanumeric character (exclude blankspace too)	//std::size_t found = commandLine.find_first_not_of("abcdefghijklmnopqrstuvwxyz1234567890 ");	////This operator determine whether the commandLine contains any symbol	//std::size_t index = commandLine.find_first_of("1234567890");	//if(found != std::string::npos){
	//	isSymbol=true;
	//	if(index < found){
	//		isIndex = true;
	//	}
	//}		commandReference.setCommandAction(commandLineDataContainer[0]);
	_taskCommand = commandLineDataContainer[0];
	std::string searchItem;
	if(commandLineDataContainer[0].compare("search")==0){
		searchItem = commandLine.substr(commandLineDataContainer[0].length()+1,commandLine.length()-commandLineDataContainer[0].length());
		commandReference.setSearchItem(searchItem);
	}
	for(auto i = 1; i < commandLineDataContainer.size(); i++){
		timeAndDate isTime("",commandLineDataContainer[i] );
		if(isTime.isValid()){
			commandReference.setTime(commandLineDataContainer[i]);
			timeDataPosition = i;
		}
		timeAndDate isDate(commandLineDataContainer[i],"");
		if(isDate.isValid()){
			commandReference.setDate(commandLineDataContainer[i]);
			dateDataPosition = i;
		}
		if(commandLineDataContainer[i].size() == 1){
			commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
			taskIndexPosition = i;
		}
		if(commandLineDataContainer[i].find_first_of("@") == 0){
			taskLocationDataStartPosition = i;
		}
		
	}	
			taskTitleDataStartPosition  = taskIndexPosition + 1;
	taskTitleDataEndPosition = commandLineDataContainer.size() -1;
	taskLocationDataEndPosition = commandLineDataContainer.size() -1;
	if(timeDataPosition !=0 && dateDataPosition != 0){
		if(timeDataPosition < dateDataPosition){
			taskTitleDataEndPosition = timeDataPosition - 1;
		}
		else{
			taskTitleDataEndPosition = dateDataPosition - 1;
		}	
	}else if(timeDataPosition == 0){
		taskTitleDataEndPosition = dateDataPosition - 1;
	}else if(dateDataPosition == 0){
		taskTitleDataEndPosition = timeDataPosition - 1;
	}
	if(taskTitleDataStartPosition != 0){

	commandReference.setTaskTitle(
		constructItem(
		commandLineDataContainer,
		taskTitleDataStartPosition,
		taskTitleDataEndPosition
		));
	}
	if(taskLocationDataStartPosition != 0){

	commandReference.setTaskLocation(
		constructItem(
		commandLineDataContainer,
		taskLocationDataStartPosition,
		taskLocationDataEndPosition

		));
	}
	

	
	////If commandLine has symbols
	//if(isSymbol){	
	//	//@author A0083864U
	//	if(isIndex){
	//		commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
	//		_taskCommand = commandLine.substr(substringBegin, index - 1);
	//		commandReference.setCommandAction(_taskCommand);
	//	}else{
	//		_taskCommand = getItemsInString(commandLine, NULL);
	//		commandReference.setCommandAction(_taskCommand);
	//	}
	//	commandReference.setTaskTitle(getItemsInString(commandLine, symbolTitle));
	//	commandReference.setTaskLocation(getItemsInString(commandLine, symbolLocation));
	//	commandReference.setTime(getItemsInString(commandLine, symbolTime));
	//	commandReference.setDate(getItemsInString(commandLine, symbolDate));
	//}else {
	//	//@author A0125489U
	//	//This method determine the 1st index of non-alpha character
	//	found = commandLine.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
	//	_taskCommand = commandLine.substr(substringBegin,found);
	//	commandReference.setCommandAction(_taskCommand);
	//	commandReference.setSearchItem(commandLine.substr(found+1, commandLine.size()));
	//} 
	//if(_taskCommand == "delete"){
	//	commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
	//}

	checkAndSetTaskType(commandLine);
}
std::string parser::constructItem(std::vector<std::string> dataContainor,int startPosition, int endPosition){
	std::string item;
	for(int i = startPosition; i <= endPosition; i++){
		item = item + dataContainor[i];
		if(i != endPosition){
			item = item + ' ';
		}
	}
	return item; 
}
parser::~parser(void){
}

int parser::getItemInInteger(std::string inputString){
	std::string dummy="";
	int indexToBeActOn=NULL;
	std::istringstream in(inputString);
	in >> dummy;
	in >> indexToBeActOn;
	return indexToBeActOn;
}

//std::string parser::getItemsInString(std::string inputString, char itemType){
//	unsigned int substringBegin;
//	unsigned int substringEnd;
//	char blankSpace=0;
//	char checkSpace;
//	std::string symbols = "&@#%$";
//	std::string itemString;
//
//
//	if(itemType == '\0'){
//		// @author A0125489U
//		//This operator determine whether inputString contains any symbol
//		if(!inputString.find("&") && !inputString.find("@") && !inputString.find("#") && !inputString.find("%") && !inputString.find("$")!= std::string::npos){
//			return inputString;
//		}
//		substringBegin = 0;
//		substringEnd = inputString.find_first_of(symbols);
//	} else{
//		if(inputString.find(itemType) != std::string::npos){
//			substringBegin = inputString.find_first_of(itemType) + 1;
//			substringEnd = inputString.find_first_of(symbols, substringBegin);
//			if(substringEnd == std::string::npos){ //print last token
//				return inputString.substr(substringBegin);
//			}
//		} else{
//			return "";
//		}
//	}
//	itemString = inputString.substr(substringBegin,substringEnd - substringBegin);
//	// @author A0125489U
//	// This while loop remove trailing whitespaces
//	while(itemString.size() >0 && itemString.compare(itemString.size() - 1 ,1 , " ") == 0){
//		itemString.erase(itemString.end() -1);
//	}
//	substringEnd = itemString.size();
//	return inputString.substr(substringBegin,substringEnd);
//}

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

