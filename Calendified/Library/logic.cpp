#include "logic.h"
#include <algorithm>
#include <string>
#include <sstream>
#include "taskAdd.h"

using namespace std;

commandType hashCommandAction(std::string commandAction);

logic::logic(void){
}

logic::~logic(void){
}

string logic::readCommand(std::string commandLine){
	parser temp(commandLine);
	std::string commandAction = temp.getTaskCommand();

	std::string title;
	std::string location;
	std::string description;
	time_t date;
	time_t time;

	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';
	char symbolDate = '%';
	char symbolTime = '$';

	//Add operation variables
	string addResults;
	//Delete operation variables
	taskDelete deleteItem;
	std::string stringToBeDeleted ="";
	//Display operation variables
	std::string displayResults="";
	bool isViewed;

	std::string task = logic::toString();
	taskAdd taskToBeAdded(task);

	switch(hashCommandAction(commandAction)){
	case ADD:
		title = temp.getTaskTitle();
		location = temp.getTaskLocation();
		description = temp.getTaskDescription();
		date = temp.getTaskDate();
		time = temp.getTaskTime();
		taskToBeAdded.taskAddTask();

		//addResults="Added Successfully!";
		return addResults;
		break;
	case DELETE:
		title = temp.getTaskTitle();
		location = temp.getTaskLocation();
		description = temp.getTaskDescription();
		date = temp.getTaskDate();
		time = temp.getTaskTime();

		stringToBeDeleted = title + location + description; //tostring
		deleteItem.executeDelete(stringToBeDeleted);
		return "Deleted Successfully!";
		break;
	case VIEW:
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		title = temp.getTaskTitle();
		date = temp.getTaskDate();
		time = temp.getTaskTime();
		return "";
		break;
	case DISPLAY:
		isViewed = displayTasks();
		if(isViewed){
			displayResults ="Results:\n";
			for(set<string>:: iterator index = allTasks.begin(); index != allTasks.end(); index++){
				displayResults += *index+"\n";
			}	
			return displayResults;
		}
		else{
			displayResults = "Error: File not found";
			return displayResults;
		}
		break;
	case EDIT:
		title = temp.getTaskTitle();
		location = temp.getTaskLocation();
		description = temp.getTaskDescription();
		date = temp.getTaskDate();
		time = temp.getTaskTime();
		return "";
		break;
	case UNDO:
		//Shijia: what should I put here?
		return "";
		break;
	case REPEAT:
		//Shijia: what should I put here?
		return "";
		break;
	case SPECIFY:
		//Shijia: what should I put here?
		return "";
		break;
	case REDO:
		//Shijia: what should I put here?
		return "";
		break;
	case TOGGLE:
		//Shijia: what should I put here?
		return "";
		break;
	default:
		return "";
		break;
	}
	return "";
}

std::string logic::toString(){
	parser taskAdd;
	std::ostringstream details;
	details << taskAdd.getTaskDate()
			<< taskAdd.getTaskTime()
			<< taskAdd.getTaskTitle()
			<< taskAdd.getTaskLocation()
			<< taskAdd.getTaskDescription();

	return details.str();
}

void logic::setCommand(std::string command){
}

void logic::setTitle(std::string title){
}

void logic::setLocation(std::string location){
}

void logic::setDescription(std::string description){
}

void logic::setDate(std::string date){
}

void logic::setTime(std::string time){
}

/*
std::string logic::getCommand(){
}

std::string logic::getTitle(){
}

std::string logic::getLocation(){
}

std::string logic::getDescription(){
}

std::string logic::getDate(){
}

std::string logic::getTime(){
}
*/

/*
void logic::toParser(std::string commandLine){ //repetitive
	//parser newParser;
	//newParser.readCommand(command);

	return;
}
*/

bool logic::displayTasks(){
	ifstream myReadFile;
	string task;
	myReadFile.open("storage.txt");
	if (myReadFile.is_open()){
		while (!myReadFile.eof()){
			getline(myReadFile,task);
			allTasks.insert(task);
		}
		myReadFile.close();
		return true;
	}
	else{
		return false;
	}
}

commandType hashCommandAction(std::string commandAction){
	std::string commandAdd = "add";
	std::string commandDelete = "delete";
	std::string commandView = "view";
	std::string commandDisplay = "display" ;
	std::string commandEdit = "edit";
	std::string commandUndo = "undo";
	std::string commandRepeat = "repeat";
	std::string commandSpecify = "specify";
	std::string commandRedo = "redo";
	std::string commandToggle = "toggle";

	transform(commandAction.begin(),commandAction.end(),commandAction.begin(),tolower);

	if(commandAction.compare(commandAdd) == 0){ 
		return ADD;
	}
	if(commandAction.compare(commandDelete) == 0){ 
		return DELETE;
	}
	if(commandAction.compare(commandView) == 0){ 
		return VIEW;
	}
	if(commandAction.compare(commandDisplay) == 0){ 
		return DISPLAY;
	}
	if(commandAction.compare(commandEdit) == 0){ 
		return EDIT;
	}
	if(commandAction.compare(commandUndo) == 0){ 
		return UNDO;
	}
	if(commandAction.compare(commandRepeat) == 0){ 
		return REPEAT;
	}
	if(commandAction.compare(commandSpecify) == 0){ 
		return SPECIFY;
	}
	if(commandAction.compare(commandRedo) == 0){ 
		return REDO;
	}
	if(commandAction.compare(commandToggle) == 0){ 
		return TOGGLE;
	}
}