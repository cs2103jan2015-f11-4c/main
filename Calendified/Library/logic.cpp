#include "logic.h"
#include <iomanip>
#include <ctime>

logic::logic(void){
}

logic::~logic(void){
}

std::string logic::readCommand(std::string commandLine, int flipCount){
	parser newParser(commandLine);
	storage newStorage;
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDate = '%';
	char symbolTime = '$';
	currentCommandReference = newParser.getCommandRef().copyTo();

	timeAndDate newTimeAndDate(currentCommandReference.getDate(),currentCommandReference.getTime());
	task newTask;

	newTask.setCommandAction(newParser.getTaskCommand());
	newTask.setTimeAndDate(newTimeAndDate);
	newTask.setLocation(newParser.getItemsInString(commandLine,symbolLocation));
	newTask.setTitle(currentCommandReference.getTaskTitle());
	newTask.setTaskType(currentCommandReference.getTaskType());

	//Add operation variables
	std::string addResults = "";
	std::string taskString = "";
	// For Task Type
	taskAdd addTask;
	//Delete operation variables
	taskDelete deleteItem;
	taskEdit editItem;
	commandRef editedcommandRef;
	std::string deleteResults = "";
	int indexToActOnDisplay;
	int indextoActOnStorage;
	std::vector<task> currentDisplayContent;
	//Display and View operation variables
	static taskDisplay displayTask;
	std::string displayTodayResults = "";
	std::string displayNextDayResults = "";
	std::string editResults = "";
	std::string checkDoneResults = "";
	std::string displayFloatResults = "FLOAT";
	std::vector<task> emptyTaskList;
	int toggleCount;
	//Undo operation variables
	static taskUndo undoTask;
	std::string undoResults = "";
	//@author A0125489U	
	switch(hashCommandAction(newParser.getTaskCommand())){
	case ADD:
		addTask.setTask(newTask);
		addResults = addTask.executeAdd(); 
		addTask.undoAdd(&undoTask);
		return addResults;
	case DELETE:
		//get current DisplayIndex using displayTask.getStorageIndex
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		indextoActOnStorage = displayTask.getStorageIndex(currentDisplayContent,indexToActOnDisplay);
		deleteResults = deleteItem.executeDelete(indextoActOnStorage);		
		deleteItem.undoDelete(&undoTask);
		undoTask.setSessionStack(undoTask.getCurrentStack());
		undoTask.insertVector(newStorage.readFileJson());		
		return deleteResults;
	case VIEW:
		displayTask.updateStorageSource();
		displayTask.setDisplayContent(emptyTaskList);
		displayTodayResults = displayTask.viewSearchList(newParser.getCommandRef().getSearchItem());
		displayTask.setDisplayIndex(0);
		return displayTodayResults;
	case DISPLAY:		
		displayTask.updateStorageSource();
		displayTask.setDisplayContent(emptyTaskList);
		displayTodayResults = displayTask.displayToday(flipCount);
		displayNextDayResults = displayTask.displayNextDay(flipCount);
		displayFloatResults += displayTask.displayFloatDay(flipCount);
		displayTask.setDisplayIndex(0);
		return displayTodayResults+"\n"+displayNextDayResults+"\n"+displayFloatResults;
	case EDIT:	
		editItem.setEditingRef(newTask);
		editResults = editItem.executeEdit(currentCommandReference.getIndexToBeActOn());
		editItem.undoEdit(&undoTask);
		return editResults;
	case CHECKDONE:
		checkDoneResults = "list below";
		return checkDoneResults;
	case UNDO:
		undoResults = undoTask.executeUndo();	
		return undoResults;
	case FLIP:
		return "Flipped!";
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

//author A0125489U
std::vector<std::string> logic::updateUI(std::string logicResult , int toggleIndex, int flipCount){
	taskDisplay displayTask;
	std::string displayLeft;
	std::string displayRight;
	std::vector<std::string> displayResults;
	displayResults.push_back(displayTask.getTodayDate(flipCount));
	displayResults.push_back(displayTask.getNextDayDate(flipCount));
	int pos;
	if(toggleIndex == 0){ // 0 for calendifiedView
		pos = displayTask.configureCalendifedView(logicResult, flipCount);
		if(pos == -1){ // Operations for ADD, DELETE, EDIT, FLIP
			displayResults.push_back(logicResult);
			return displayResults;
		}
		displayLeft = logicResult.substr(0,pos); //Operations for VIEW, DISPLAY
		displayRight = logicResult.substr(pos);
		displayResults.push_back(displayLeft);
		displayResults.push_back(displayRight);
	} else { //Operation for ListView
		displayResults.push_back(displayTask.configureListView(logicResult));
	}
	return displayResults;
}


commandType logic::hashCommandAction(std::string commandAction){
	std::string commandAdd = "add";
	std::string commandDelete = "delete";
	std::string commandView = "view";
	std::string commandDisplay = "display";
	std::string commandEdit = "edit";
	std::string commandUndo = "undo";
	std::string commandFlip = "flip";
	std::string commandSpecify = "specify";
	std::string commandRedo = "redo";
	std::string commandToggle = "toggle";
	std::string commandCheckDone = "checkdone";

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
	if(commandAction.compare(commandFlip) == 0){ 
		return FLIP;
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
	if(commandAction.compare(commandCheckDone) == 0){ 
		return CHECKDONE;
	}
}