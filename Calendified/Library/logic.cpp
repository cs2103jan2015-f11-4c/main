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

	std::string displayTodayResults = "";
	std::string displayNextDayResults = "";
	std::string editResults = "";
	std::string checkDoneResults = "";
	std::string displayFloatResults = "FLOAT";
	std::string s;
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
		deleteResults = deleteItem.executeDelete(currentCommandReference.getIndexToBeActOn());
		
		undoTask.setSessionStack(undoTask.getCurrentStack());
		undoTask.insertVector(newStorage.readFileJson());
		
		return deleteResults;
	case VIEW:
		displayTodayResults = "Results:\n"+newStorage.searchFile(newParser.getCommandRef().getSearchItem(),"main")+"\n";
		displayTodayResults += "FLOAT\n"+newStorage.searchFile(newParser.getCommandRef().getSearchItem(),"float");
		return displayTodayResults;
	case DISPLAY:		
		displayTodayResults = getTodayDate()+"\n";
		displayTodayResults += newStorage.searchFile(getTodayDateDMY().substr(0,5)+"/","main");
		displayNextDayResults = getNextDayDate()+"\n";
		displayNextDayResults += newStorage.searchFile(getNextDayDateDMY().substr(0,5)+"/","main");
		displayFloatResults += "\n";
		displayFloatResults += newStorage.searchFile("","float");
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

//@author A0125489U
//This operation returns current date- Day
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
//This operation returns current date- Day
std::string logic::getTodayDateDMY(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
	return std::string(output);
}

//@author A0125489U
//This operation returns current date- Day
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

//@author A0125489U
//This operation returns current date- Day
std::string logic::getNextDayDateDMY(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
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