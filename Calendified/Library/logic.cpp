#include "logic.h"
#include <iomanip>
#include <ctime>

logic::logic(void){
}

logic::~logic(void){
}

std::string logic::readCommand(std::string commandLine){
	parser newParser(commandLine);
	storage newStorage;
	char symbolTitle = '&';
	char symbolLocation = '@';
	char symbolDate = '%';
	char symbolTime = '$';
	currentCommandReference = newParser.getCommandRef().copyTo();

	timeAndDate newTimeAndDate(currentCommandReference.getDate(),currentCommandReference.getTime());
	task newTask;
	std::string TimedTask = "TimedTask";
	std::string FloatingTask = "FloatingTask";
	std::string DeadLine = "DeadLine";
	newTask.setCommandAction(newParser.getTaskCommand());
	newTask.setTimeAndDate(newTimeAndDate);
	newTask.setLocation(newParser.getItemsInString(commandLine,symbolLocation));
	newTask.setTitle(currentCommandReference.getTaskTitle());
	newTask.setTaskType(TimedTask);
	// Setting task type
	// Floating Task:
	// 1. Got date no time
	// 2. No date no time
	// Timed Task:
	// 1. Got date got time
	// DeadLine:
	// 1. Got date got time 
	/*if(newTimeAndDate.getTaskDateInString() != "" && newTimeAndDate.getTaskStartTimeInString() != "" && newTimeAndDate.getTaskEndTimeInString() != ""){
		newTask.setTaskType(TimedTask);
	} else if(newTimeAndDate.getTaskDateInString() != "" && newTimeAndDate.getTaskStartTimeInString() == "" && newTimeAndDate.getTaskEndTimeInString() == ""
		|| newTimeAndDate.getTaskDateInString() == "" && newTimeAndDate.getTaskStartTimeInString() == "" && newTimeAndDate.getTaskEndTimeInString() == ""){
		newTask.setTaskType(FloatingTask);
	} else if(newTimeAndDate.getTaskDateInString() != "" && newTimeAndDate.getTaskStartTimeInString() != "" && newTimeAndDate.getTaskEndTimeInString() != ""){
		newTask.setTaskType(DeadLine);
		//how to differentiate deadline from timed task?
	}*/

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
	//Display and View operation variables
	taskDisplay displayTask;
	std::string displayTodayResults = "";
	std::string displayNextDayResults = "";
	std::string editResults = "";
	std::string checkDoneResults = "";
	std::string displayFloatResults = "FLOAT";
	int toggleCount;
	//Undo operation variables
	taskUndo undoTask;
	std::string undoResults = "";
	//@author A0125489U	
	switch(hashCommandAction(newParser.getTaskCommand())){
	case ADD:
		//taskString = newParser.getCommandRef().dataToString();
		/*if(newTask.getTimeAndDate().getTaskDateInString() != "" && newTask.getTimeAndDate().getTaskTimeInString != ""){
			addTask.setTaskType(TimedTask);
		} else if(newTask.getTimeAndDate().getTaskDateInString() == "" || newTask.getTimeAndDate().getTaskTimeInString == ""){ 
			addTask.setTaskType(FloatingTask);
		}*/
		addTask.setTask(newTask);
		// Testing json : newStorage.writeFileJson(commandVector);
		addResults = addTask.taskAddTask(); 
		undoTask.setSessionStack(undoTask.getCurrentStack());
		undoTask.insertVector(newStorage.readFileJson());
		return addResults;
	case DELETE:

		deleteResults = deleteItem.executeDelete(newParser.getCommandRef().getIndexToBeActOn());		

		deleteResults = deleteItem.executeDelete(currentCommandReference.getIndexToBeActOn());
		

		undoTask.setSessionStack(undoTask.getCurrentStack());
		undoTask.insertVector(newStorage.readFileJson());		
		return deleteResults;
	case VIEW:
		displayTodayResults = displayTask.viewSearchList(newParser.getCommandRef().getSearchItem());
		return displayTodayResults;
	case DISPLAY:			
		displayTodayResults = displayTask.displayToday();
		displayNextDayResults = displayTask.displayNextDay();
		displayFloatResults += displayTask.displayFloatDay();
		return displayTodayResults+"\n"+displayNextDayResults+"\n"+displayFloatResults;
	case CLEAR:
		newStorage.clearFile();
		return newStorage.successMessageClear();
	case EDIT:	
		editItem.setEditingRef(currentCommandReference);
		editResults = editItem.executeEdit(currentCommandReference.getIndexToBeActOn());
		undoTask.setSessionStack(undoTask.getCurrentStack());
		undoTask.insertVector(newStorage.readFileJson());
		return editResults;
	case CHECKDONE:
		checkDoneResults = "list below";
		return checkDoneResults;
	case UNDO:
		undoTask.setCurrentStack(undoTask.getSessionStack());
		if(undoTask.isEmpty(undoTask.getSessionStack()) == false){
		undoTask.getSessionStack().pop();
		newStorage.writeFileJson(undoTask.getCurrentStack().top());
		}
		undoResults = undoTask.undoResults();		
		return undoResults;
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

//author A0125489U
std::vector<std::string> logic::updateUI(std::string logicResult , int toggleIndex){
	taskDisplay displayTask;
	std::string displayLeft;
	std::string displayRight;
	std::vector<std::string> displayResults;
	displayResults.push_back(displayTask.getTodayDate());
	displayResults.push_back(displayTask.getNextDayDate());
	int pos;
	if(toggleIndex == 0){ // 0 for calendifiedView
		pos = displayTask.configureCalendifedView(logicResult);
		if(pos == -1){ // Operations for ADD, DELETE, EDIT
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
	std::string commandClear = "clear";
	std::string commandEdit = "edit";
	std::string commandUndo = "undo";
	std::string commandRepeat = "repeat";
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
	if(commandAction.compare(commandCheckDone) == 0){ 
		return CHECKDONE;
	}
}