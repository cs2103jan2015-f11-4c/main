#include "logic.h"

using namespace std;

logic::logic(void){
}

logic::~logic(void){
}

logic::logic(std::string command, std::string title, std::string time, std::string date, 
	  std::string location, std::string description){
		  _command = command;
		  _title = title;
		  _time = time;
		  _date = date;
		  _location = location;
		  _description = description;
}
commandType hashCommandAction(std::string commandAction);
string logic::readCommand(std::string commandLine){
	parser temp;
	std::string commandAction = temp.getItemsInString(commandLine, '\0');
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';

	std::string title,location,description;
	//Add operation variables
	string addResults;
	//Delete operation variables
	taskDelete deleteItem;
	std::string stringToBeDeleted ="";
	//Display operation variables
	string displayResults="";
	bool isViewed;

	switch(hashCommandAction(commandAction)){
	case ADD:
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		location = temp.getItemsInString(commandLine, symbolLocation);
		setLocation(location);
		description = temp.getItemsInString(commandLine, symbolDescription);
		setDescription(description);
		addResults="Added Successfully!";
		return addResults;
		//put convert string to time_h class funtion here(timeAndDate)
		break;
	case DELETE:
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		//_location = temp.getItemsInString(commandLine, symbolLocation);
		//_description = temp.getItemsInString(commandLine, symbolDescription);
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		location = temp.getItemsInString(commandLine, symbolLocation);
		setLocation(location);
		description = temp.getItemsInString(commandLine, symbolDescription);
		setDescription(description);

		stringToBeDeleted = title + location + description;
		deleteItem.executeDelete(stringToBeDeleted);
		return "Deleted Successfully!";
		break;
	case VIEW:
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		//put convert string to time_h class funtion here(timeAndDate)
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
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		//_location = temp.getItemsInString(commandLine, symbolLocation);
		//_description = temp.getItemsInString(commandLine, symbolDescription);
		title = temp.getItemsInString(commandLine, symbolTitle);
		setTitle(title);
		location = temp.getItemsInString(commandLine, symbolLocation);
		setLocation(location);
		description = temp.getItemsInString(commandLine, symbolDescription);
		setDescription(description);
		//put convert string to time_h class funtion here(timeAndDate)
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

void logic::setCommand(std::string command){
	_command = command;
}

void logic::setTitle(std::string title){
	_title = title;
}

void logic::setTime(std::string time){
	_time = time;
}

void logic::setDate(std::string date){
	_date = date;
}

void logic::setLocation(std::string location){
	_location = location;
}

void logic::setDescription(std::string description){
	_description = description;
}

std::string logic::getCommand(){
	return _command;
}

std::string logic::getTitle(){
	return _title;
}

std::string logic::getTime(){
	return _time;
}
std::string logic::getDate(){
	return _date;
}
std::string logic::getLocation(){
	return _location;
}
std::string logic::getDescription(){
	return _description;
}
void logic::toParser(std::string command){
	//parser newParser;
	//newParser.readCommand(command);

	return;
}
bool logic::displayTasks(){
	ifstream myReadFile;
	string task;
	myReadFile.open("storage.txt");
	if (myReadFile.is_open()){
		while (!myReadFile.eof()){
			getline(myReadFile,task);
			allTasks.insert(task);
		}
		return true;
	}
	else{
		return false;
	}
}