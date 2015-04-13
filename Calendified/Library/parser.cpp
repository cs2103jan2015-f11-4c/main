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
	bool isSymbol = false;
	bool isIndex = false;
	unsigned int substringBegin = 0;
	int timeDataPosition = 0;
	int dateDataPosition = 0;
	int taskIndexPosition = 0;	int taskTitleDataStartPosition = 0;	int taskTitleDataEndPosition = 0;	int taskLocationDataStartPosition = 0;	int taskLocationDataEndPosition = 0;	std::vector<std::string> commandLineDataContainer;	commandLineDataContainer = getCommandlineItem(commandLine);		//@author A0125489U	//This method determine the 1st index of any non-alphanumeric character (exclude blankspace too)	//std::size_t found = commandLine.find_first_not_of("abcdefghijklmnopqrstuvwxyz1234567890 ");	////This operator determine whether the commandLine contains any symbol	//std::size_t index = commandLine.find_first_of("1234567890");	//if(found != std::string::npos){

	_taskCommand = commandLineDataContainer[0];
	bool isCommand = checkCommand(_taskCommand);
	if(!isCommand){
		throw std::exception();
	}
	std::string searchItem;
	if(commandLineDataContainer[0].compare("search")==0){
		searchItem = commandLine.substr(commandLineDataContainer[0].length()+1,commandLine.length()-commandLineDataContainer[0].length());
		commandReference.setSearchItem(searchItem);
	} else if(commandLineDataContainer.size() > 1){
		if(commandLineDataContainer[1].compare("to") ==0 && commandLineDataContainer[0].compare("flip")==0){
			searchItem = commandLine.substr(commandLineDataContainer[0].length()+1+commandLineDataContainer[1].length()+1,commandLine.length()-commandLineDataContainer[0].length()-commandLineDataContainer[1].length());
			if(searchItem.length() !=8 ){
				throw std::exception();
			} else {
				timeAndDate isDate(searchItem.substr(0,2)+"/"+searchItem.substr(2,2)+"/"+searchItem.substr(4),"");
				if(!isDate.isValid()){
					throw std::exception();
				}
			}
			assert(searchItem.length()==8);
			commandReference.setSearchItem(searchItem);
		} else if(commandLineDataContainer[0].compare("flip") ==0 ){
			searchItem = commandLine.substr(commandLineDataContainer[0].length()+1,commandLine.length()-commandLineDataContainer[0].length());
			if(searchItem.length() !=8 ){
				throw std::exception();
			} else {
				timeAndDate isDate(searchItem.substr(0,2)+"/"+searchItem.substr(2,2)+"/"+searchItem.substr(4),"");
				if(!isDate.isValid()){
					throw std::exception();
				}
			}
			assert(searchItem.length()==8);
			commandReference.setSearchItem(searchItem);
		}
	} 
	int deadlineIndex = checkDeadlineIndex(commandLine);
	if(deadlineIndex !=0){
		commandLineDataContainer.erase(commandLineDataContainer.begin() + deadlineIndex);
	}
	for(auto i = 1; i < (int) commandLineDataContainer.size(); i++){
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
		if(std::regex_match(commandLineDataContainer[i], std::regex("[(-|+)|][0-9]+"))
			|| commandLineDataContainer[i].size() == 1){
				commandReference.setIndexToBeActOn(getItemInInteger(commandLine));
				taskIndexPosition = i;
		}
		if(commandLineDataContainer[i].find_first_of("@") == 0){
			taskLocationDataStartPosition = i;
		}

	}	
	taskTitleDataStartPosition  = taskIndexPosition + 1;
	if(taskLocationDataStartPosition==0){
		taskTitleDataEndPosition = commandLineDataContainer.size() -1;
	}else if(timeDataPosition !=0){
		taskTitleDataEndPosition = timeDataPosition -1;
	}else{
		taskTitleDataEndPosition = taskLocationDataStartPosition -1 ;
	}

	if(timeDataPosition !=0 && dateDataPosition != 0){
		if(timeDataPosition < dateDataPosition){
			taskTitleDataEndPosition = timeDataPosition - 1;
		}
		else{
			taskTitleDataEndPosition = dateDataPosition - 1;
		}	
	}else if(timeDataPosition ==0 && dateDataPosition != 0){
		taskTitleDataEndPosition = dateDataPosition - 1;
	}

	commandReference.setTaskTitle(
		constructItem(
		commandLineDataContainer,
		taskTitleDataStartPosition,
		taskTitleDataEndPosition
		));

	if(taskLocationDataStartPosition != 0){
		taskLocationDataEndPosition = commandLineDataContainer.size() -1;
		commandReference.setTaskLocation(
			constructItem(
			commandLineDataContainer,
			taskLocationDataStartPosition,
			taskLocationDataEndPosition
			));
	}
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

std::string parser::getTaskCommand(){
	return _taskCommand;
}

commandRef parser::getCommandRef(){
	return commandReference;
}

//@author A0114411B
// This function tokenize the command line by splitting the words up
// using whitespaces as delimiters.
std::vector<std::string> parser::tokenizeCommandLine(std::string commandLine){
	std::string buffer; 
	std::stringstream ss(commandLine);

	std::vector<std::string> tokens; 

	while (ss >> buffer){
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
		tokens.push_back(buffer);
	}

	return tokens;
}

//@author A0125489U
//This method checks for the deadline index 
//Use this method to remove the deadline keywords {BY, DUE, BEFORE} from the Task Title
int parser::checkDeadlineIndex(std::string commandLine){
	int index=0;
	std::vector<std::string> tokenizedVector = tokenizeCommandLine(commandLine);

	for(auto i=0; i < (int) tokenizedVector.size(); i++){
		if(tokenizedVector[i].compare(DATE_DEADLINE_DUE) == 0 ||
			tokenizedVector[i].compare(DATE_DEADLINE_BEFORE) == 0 ||
			tokenizedVector[i].compare(DATE_DEADLINE_BY) == 0){
				index = i;
				break;
		}
	}
	return index;
}

//@author A0114411B
// This method checks the task type of a event entered by the user.
// It checks by if the task has both time and date, it will be a 
// timed task. If it contained certain keywords such as "by", "due"
// or "before" it will be a deadline task. If there is no time or date,
// got time no date or no date and got time, it will all be floating tasks.
void parser::checkAndSetTaskType(std::string commandLine){
	std::vector<std::string> tokenizedVector = tokenizeCommandLine(commandLine);

	if(commandReference.getDate()[0] >0 && commandReference.getTime()[0] >0){
		commandReference.setTaskType(TIMED_TASK);
	} else if(commandReference.getDate()[0] ==0 && commandReference.getTime()[0] !=0 ||
		commandReference.getDate()[0] !=0 && commandReference.getTime()[0] ==0 ||
		commandReference.getDate()[0] ==0 && commandReference.getTime()[0] ==0){
			commandReference.setTaskType(FLOATING_TASK);
	} else {
		for(auto i=0; i < (int) tokenizedVector.size(); i++){
			if(tokenizedVector[i].compare(DATE_DEADLINE_DUE) == 0 ||
				tokenizedVector[i].compare(DATE_DEADLINE_BEFORE) == 0 ||
				tokenizedVector[i].compare(DATE_DEADLINE_BY) == 0){
					commandReference.setTaskType(DEAD_LINE);
					tokenizedVector.erase(tokenizedVector.begin()+i);
					return;
			}
		}
	}
}

//This method verify whether the commandInput is a valid one
bool parser::checkCommand(std::string checkCommandInput){
	bool isCommand = false;
	std::string commandAdd = "add";
	std::string commandDelete = "delete";
	std::string commandSearch = "search";
	std::string commandDisplay = "display";
	std::string commandDone = "done";
	std::string commandUndone = "undone";
	std::string commandEdit = "edit";
	std::string commandUndo = "undo";
	std::string commandFlip = "flip";
	std::string commandSpecify = "specify";
	std::string commandRedo = "redo";
	std::string commandToggle = "toggle";
	std::string commandCheckDone = "checkdone";
	if(checkCommandInput.compare(commandAdd)==0 ||
		checkCommandInput.compare(commandDelete)==0 ||
		checkCommandInput.compare(commandSearch)==0 ||
		checkCommandInput.compare(commandDisplay)==0 ||
		checkCommandInput.compare(commandDone)==0 ||
		checkCommandInput.compare(commandUndone)==0 ||
		checkCommandInput.compare(commandEdit)==0 ||
		checkCommandInput.compare(commandUndo)==0 ||
		checkCommandInput.compare(commandFlip)==0 ||
		checkCommandInput.compare(commandSpecify)==0 ||
		checkCommandInput.compare(commandRedo)==0 ||
		checkCommandInput.compare(commandToggle)==0 ||
		checkCommandInput.compare(commandCheckDone)==0){
			isCommand = true;
	}
	return isCommand;
}

