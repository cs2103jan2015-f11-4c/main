#include "logic.h"
#include <iomanip>
#include <ctime>
// comments
logic::logic(void){
}

logic::~logic(void){
}

std::string logic::readCommand(std::string commandLine){
	parser temp(commandLine);
	storage newStorage;
	currentTaskReference = temp.getTaskRef().copyTo();
	std::string stringDetails;
	std::string commandAction = temp.getTaskCommand();

	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDescription = '#';
	char symbolDate = '%';
	char symbolTime = '$';

	//Add operation variables
	std::string addResults = "";
	std::string taskString = "";
	std::string MAIN = "main";
	std::string FLOAT = "float";
	taskAdd addTask;
	//Delete operation variables
	taskDelete deleteItem;
	taskEdit editItem;
	taskRef editedTaskRef;

	std::string deleteResults = "";
	//Display and View operation variables
	std::string displayTodayResults = "";
	std::string displayNextDayResults = "";
	std::string editResults = "";
	std::string displayFloatResults = "FLOAT";

	//@author A0125489U	
	switch(hashCommandAction(commandAction)){
	case ADD: //@author A0116027R
		//temp.getTaskRef().getTaskTimeAndDateInString();
		taskString = temp.getTaskRef().dataToString();
		if(temp.getTaskRef().getTaskTimeAndDateInString() == " "){ 
			addTask.setTaskType(FLOAT);
		}
		else if(temp.getTaskRef().getTaskTimeAndDateInString() != " "){
			addTask.setTaskType(MAIN);
		}
		addTask.setTask(taskString);

		addResults = addTask.taskAddTask();
		return addResults;
	case DELETE:
		deleteResults = deleteItem.executeDelete(temp.getTaskRef().getIndexToBeDeleted());
		return deleteResults;
	case VIEW:
		displayTodayResults = "Results:\n"+newStorage.searchFile(temp.getTaskRef().getSearchItem(),"main")+"\n";
		displayTodayResults += "FLOAT\n"+newStorage.searchFile(temp.getTaskRef().getSearchItem(),"float");
		return displayTodayResults;
	case DISPLAY:		
		displayTodayResults = getTodayDate()+"\n";
		displayTodayResults += newStorage.searchFile(getTodayDate().substr(0,2)+"/","main");
		displayNextDayResults = getNextDayDate()+"\n";
		displayNextDayResults += newStorage.searchFile(getNextDayDate().substr(0,2)+"/","main");
		displayFloatResults += "\n";
		displayFloatResults += newStorage.searchFile("","float");
		return displayTodayResults+"\n"+displayNextDayResults+"\n"+displayFloatResults;
	case CLEAR:
		newStorage.clearFile();
		return newStorage.successMessageClear();

	case EDIT:
		
		editItem.setEditingRef(currentTaskReference);
		editResults = editItem.executeEdit(currentTaskReference.getIndexToBeEdited());

		return editResults;
	case UNDO:
		return "";
	case REPEAT:
		return "";
	case SPECIFY:
		return "";
	case REDO:
		return "";
	case TOGGLE:
		return "Toggled!";
	default:
		return "";
	return "";
	}
}

//@author A0125489U
//This operation returns current date
std::string logic::getTodayDate(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%dth",timeinfo);
	return std::string(output);
}

//@author A0125489U
//This operation returns current date
std::string logic::getNextDayDate(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%dth",timeinfo);
	return std::string(output);
	//return printf("%02d/%02d/%02d\n",timeinfo->tm_mon+1, timeinfo->tm_mday, timeinfo->tm_year %100);
}

commandType logic::hashCommandAction(std::string commandAction){
	std::string commandAdd = "add";
	std::string commandDelete = "delete";
	std::string commandView = "view";
	std::string commandDisplay = "display";
	std::string commandClear = "clear";
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
	if(commandAction.compare(commandClear) == 0){
		return CLEAR;
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