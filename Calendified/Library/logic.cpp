#include "logic.h"
#include <algorithm>
#include <string>
#include <sstream>
#include "taskAdd.h"
#include "taskRef.h"
#include "storage.h"

using namespace std;

logic::logic(void){
}

logic::~logic(void){
}

string logic::readCommand(std::string commandLine){
	parser temp(commandLine);
	storage newStorage;
	vector <string> fileContent;
	currentTaskReference = temp.getTaskRef().copyTo();

	std::string stringDetails;

	std::string taskString = temp.getTaskRef().dataToString(); //for taskAdd
	taskAdd addTask(taskString);							 //for taskAdd

	std::string commandAction = temp.getTaskCommand();

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

	switch(hashCommandAction(commandAction)){
	case ADD:

	
		
	//	taskAdd taskToBeAdded(task);//use currentTaskReference to assign the data to storage(maybe use dataTostring(); or copyTo();? );
	//	taskToBeAdded.taskAddTask();

	//taskAdd taskToBeAdded(commandLine);

		/*addResults = taskToBeAdded.taskAddTask();*/
		//addResults="Added Successfully!";
		return addResults;
		break;
	case DELETE:



		/*title = temp.getTaskTitle();
		location = temp.getTaskLocation();
		description = temp.getTaskDescription();
		date = temp.getTaskDate();
		time = temp.getTaskTime();*/
		//use currentTaskReference to assign the data to storage(maybe use dataTostring(); or copyTo();? );

		//stringToBeDeleted = title + location + description; //tostring
		//deleteItem.executeDelete(stringToBeDeleted);

		/*
		title = temp.getTaskTitle();
		location = temp.getTaskLocation();
		description = temp.getTaskDescription();
		date = temp.getTaskDate();
		time = temp.getTaskTime();
		*/
		//stringToBeDeleted = title + location + description; //tostring
		
		//deleteItem.executeDelete(stringDetails);

		return "Deleted Successfully!";
		break;
	case VIEW:
		//_title = temp.getItemsInString(commandLine, symbolTitle);
		/*title = temp.getTaskTitle();
		date = temp.getTaskDate();
		time = temp.getTaskTime();*/
		//use currentTaskReference to assign the data to storage(maybe use dataTostring(); or copyTo();? );

		return "";
		break;
	case DISPLAY:
		isViewed = newStorage.isFileExist();
		if(isViewed){
			fileContent = newStorage.readFile();
			displayResults ="Results:\n";

			for(vector <string>:: iterator index = fileContent.begin(); index != fileContent.end(); index++){
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
		/*title = temp.getTaskTitle();
		location = temp.getTaskLocation();
		description = temp.getTaskDescription();
		date = temp.getTaskDate();
		time = temp.getTaskTime();*/
		//use currentTaskReference to assign the data to storage(maybe use dataTostring(); or copyTo();? );

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

commandType logic::hashCommandAction(std::string commandAction){
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