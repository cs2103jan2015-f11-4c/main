#include "logic.h"
using namespace std;

logic::logic(void){
}

logic::~logic(void){
}

string logic::readCommand(std::string commandLine){
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
	string addResults = "";
	string taskString = "";
	taskAdd addTask;
	//Delete operation variables
	taskDelete deleteItem;
	taskEdit editItem;
	taskRef editedTaskRef;

	string deleteResults = "";
	//Display and View operation variables
	string displayResults = "";
	string editResults = "";
	bool isViewed = false;

	//@author A0125489U	
	switch(hashCommandAction(commandAction)){
	case ADD:
		taskString = temp.getTaskRef().dataToString();
		addTask.set_task(taskString);
		addResults = addTask.taskAddTask();
		return addResults;
	case DELETE:
		deleteResults = deleteItem.executeDelete(temp.getTaskRef().getIndexToBeDeleted());
		return deleteResults;
	case VIEW:
		isViewed = newStorage.isFileExist();
		if(isViewed){
			displayResults = newStorage.searchFile(temp.getTaskRef().getSearchItem());
		}
		return displayResults;
	case DISPLAY:
		isViewed = newStorage.isFileExist();
		if(isViewed){
			displayResults ="Calendified Database.:\n";
			displayResults += newStorage.searchFile("");
			return displayResults;
		}
		else{
			displayResults = "Error: File not found";
			return displayResults;
		}
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