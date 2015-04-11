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
	newTask.setLocation(currentCommandReference.getTaskLocation());
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
	int indexToActOnStorage;
	std::vector<task> currentDisplayContent;
	//Display and View operation variables
	static taskDisplay displayTask;
	std::string displayTodayResults = "";
	std::string displayNextDayResults = "";
	//Edit operation variables
	std::string editResults = "";
	//Done and Undone operation variables
	std::string checkDoneResults = "";
	std::string displayFloatResults = "";
	std::string doneResults = "";
	std::string searchItem ="";
	std::vector<task> emptyTaskList;
	int toggleCount;
	//Undo operation variables
	static taskUndo undoTask;
	//Done operation variables
	taskDone newTaskDone;
	std::string undoResults = "";
	//Undone operation variables
	std::string undoneResults = "";
	//Redo operation variables
	static taskRedo redoTask;
	std::string redoResults = "";
	
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
		indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent,indexToActOnDisplay);
		deleteResults = deleteItem.executeDelete(indexToActOnStorage);		
		deleteItem.undoDelete(&undoTask);		
		return deleteResults;
	case SEARCH:
		displayTask.updateStorageSource();
		displayTask.setDisplayContent(emptyTaskList);
		searchItem = newParser.getCommandRef().getSearchItem();
		if(searchItem.compare("done")==0 || searchItem.compare("taskdone")==0){
			displayTodayResults += TYPE_RESULTS+KEYWORD_NEWLINE+displayTask.formatTimedTask(displayTask.sortTimedTaskList(newTaskDone.getListDone()),"view");
			displayTodayResults	+= KEYWORD_TO_DO_LIST+KEYWORD_NEWLINE+displayTask.formatFloatTask(displayTask.sortFloatTaskList(newTaskDone.getListDone()));
		} else if(searchItem.compare("undone")==0 || searchItem.compare("taskundone")==0){
			displayTodayResults += TYPE_RESULTS+KEYWORD_NEWLINE+displayTask.formatTimedTask(displayTask.sortTimedTaskList(newTaskDone.getListUndone()),"view");
			displayTodayResults	+= KEYWORD_TO_DO_LIST+KEYWORD_NEWLINE+displayTask.formatFloatTask(displayTask.sortFloatTaskList(newTaskDone.getListUndone()));
		} else if(searchItem.substr(0,1).compare("\"")==0 && searchItem.substr(searchItem.length()-1,1).compare("\"")==0){
			displayTodayResults = displayTask.formatSearchResults(displayTask.searchExact(searchItem));
		} else if(searchItem.length() > 6){
			if(searchItem.substr(0,6).compare("after ")==0){//check for after:
				searchItem = searchItem.substr(6);
				displayTodayResults = displayTask.searchAfter(searchItem);
			} else if(searchItem.substr(0,6).compare("before")==0){//check for before
				searchItem = searchItem.substr(7);
				displayTodayResults = displayTask.searchBefore(searchItem);
			} else{
				displayTodayResults = displayTask.searchPower(searchItem);
			}
		}
		else{ 
			displayTodayResults = displayTask.searchPower(searchItem);
		}
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
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent, indexToActOnDisplay);
		editItem.setEditingRef(newTask);
		editResults = editItem.executeEdit(indexToActOnStorage);
		editItem.undoEdit(&undoTask);
		return editResults;
	case DONE:
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent,indexToActOnDisplay);
		doneResults = newTaskDone.markDone(indexToActOnStorage);
		newTaskDone.undoDone(&undoTask);
		return doneResults;
	case UNDONE:
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent,indexToActOnDisplay);
		undoneResults = newTaskDone.markUndone(indexToActOnStorage);	
		newTaskDone.undoUndone(&undoTask);
		return undoneResults;
	case UNDO:
		redoTask.redo(undoTask);
		undoResults = undoTask.executeUndo();	
		return undoResults;
	case FLIP:
		return "Flipped!";
	case SPECIFY:
		return "";
	case REDO:
		redoResults = redoTask.executeRedo(&undoTask);
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

	transform(commandAction.begin(),commandAction.end(),commandAction.begin(),tolower);

	if(commandAction.compare(commandAdd) == 0){ 
		return ADD;
	}
	if(commandAction.compare(commandDelete) == 0){ 
		return DELETE;
	}
	if(commandAction.compare(commandSearch) == 0){ 
		return SEARCH;
	}
	if(commandAction.compare(commandDisplay) == 0){ 
		return DISPLAY;
	}
	if(commandAction.compare(commandEdit) == 0){ 
		return EDIT;
	}
	if(commandAction.compare(commandDone) == 0){
		return DONE;
	}
	if(commandAction.compare(commandUndone) == 0){
		return UNDONE;
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
		return DONE;
	}
}