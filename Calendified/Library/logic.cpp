#include "logic.h"
#include <iomanip>
#include <ctime>

logic::logic(void){
}

logic::~logic(void){
}


std::string logic::readCommand(std::string commandLine, int toggleCount, int flipCount){
	LOG(INFO) << "Entered Class: Logic. Function: readCommand";
	parser newParser(commandLine);
	storage newStorage;
	//char symbolTitle = '&';
	//char symbolLocation = '@';
	//char symbolDate = '%';
	//char symbolTime = '$';
	currentCommandReference = newParser.getCommandRef().copyTo();

	timeAndDate newTimeAndDate(currentCommandReference.getDate(),currentCommandReference.getTime());
	newTimeAndDate.deadlineTaskDateAndTimeConversion(currentCommandReference.getTaskType());
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
	case COMMAND_ADD:
		LOG(INFO) << "Entered Class: Logic. Case: ADD";
		addTask.setTask(newTask);
		addResults = addTask.executeAdd(); 
		addTask.undoAdd(&undoTask, addResults);
		return addResults;
	case COMMAND_DELETE:
		LOG(INFO) << "Entered Class: Logic. Case: ADD";
		//get current DisplayIndex using displayTask.getStorageIndex
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		if(indexToActOnDisplay <=0){
			return MESSAGE_ERROR_INVALID_INDEX;
		} else {
			indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent,indexToActOnDisplay);
			if(indexToActOnStorage < 0){
				return MESSAGE_ERROR_INVALID_INDEX;
			} else { 
				deleteResults = deleteItem.executeDelete(indexToActOnStorage);		
				deleteItem.undoDelete(&undoTask, deleteResults);	
				return deleteResults;
			}
		}
	case COMMAND_SEARCH:
		LOG(INFO) << "Entered Class: Logic. Case: ADD";
		displayTask.updateStorageSource();
		displayTask.setDisplayContent(emptyTaskList);
		searchItem = newParser.getCommandRef().getSearchItem();
		if(searchItem.compare(TYPE_DONE)==0 || searchItem.compare(TYPE_TASK_DONE)==0){
			displayTodayResults += TYPE_RESULTS+KEYWORD_NEWLINE+displayTask.formatTimedTask(displayTask.sortTimedTaskList(newTaskDone.getListDone()),TYPE_VIEW);
			if(displayTask.sortFloatTaskList(newTaskDone.getListDone()).size()>0){
				displayTodayResults	+= KEYWORD_TO_DO_LIST+KEYWORD_NEWLINE+displayTask.formatFloatTask(displayTask.sortFloatTaskList(newTaskDone.getListDone()));
			}
		} else if(searchItem.compare(TYPE_UNDONE)==0 || searchItem.compare(TYPE_TASK_UNDONE)==0){
			displayTodayResults += TYPE_RESULTS+KEYWORD_NEWLINE+displayTask.formatTimedTask(displayTask.sortTimedTaskList(newTaskDone.getListUndone()),TYPE_VIEW);
			if(displayTask.sortFloatTaskList(newTaskDone.getListUndone()).size()>0){
				displayTodayResults	+= KEYWORD_TO_DO_LIST+KEYWORD_NEWLINE+displayTask.formatFloatTask(displayTask.sortFloatTaskList(newTaskDone.getListUndone()));
			}
		} else if(searchItem.substr(0,1).compare(TYPE_QUOTE)==0 && searchItem.substr(searchItem.length()-1,1).compare(TYPE_QUOTE)==0){
			displayTodayResults = displayTask.formatSearchResults(displayTask.searchExact(searchItem));
		} else if(searchItem.length() > 6){
			if(searchItem.substr(0,6).compare(TYPE_AFTER)==0){//check for after:
				searchItem = searchItem.substr(6);
				displayTodayResults = displayTask.searchAfter(searchItem);
			} else if(searchItem.substr(0,6).compare(TYPE_BEFORE)==0){//check for before
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
	case COMMAND_DISPLAY:		
		LOG(INFO) << "Entered Class: Logic. Case: ADD";
		displayTask.updateStorageSource();
		displayTask.setDisplayContent(emptyTaskList);
		if(toggleCount ==0){ //Display for CalendifiedView	
			displayTodayResults = displayTask.displayToday(flipCount);
			displayNextDayResults = displayTask.displayNextDay(flipCount);
			displayFloatResults += displayTask.displayFloatDay(flipCount);
			displayTask.setDisplayIndex(0);
			return displayTodayResults+KEYWORD_NEWLINE+displayNextDayResults+KEYWORD_NEWLINE+displayFloatResults;
		} else { //Display for ListView
			displayTodayResults = displayTask.displayAll(flipCount);
			displayTask.setDisplayIndex(0);
			return displayTodayResults;
		}
	case COMMAND_EDIT:	
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_EDIT";
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		if(indexToActOnDisplay <=0){
			return MESSAGE_ERROR_INVALID_INDEX;
		}else{
			indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent, indexToActOnDisplay);
			if(indexToActOnStorage < 0){
				return MESSAGE_ERROR_INVALID_INDEX;
			} else {
				editItem.setEditingRef(newTask);
				editResults = editItem.executeEdit(indexToActOnStorage);
				editItem.undoEdit(&undoTask, editResults);
				return editResults;
			}
		}
	case COMMAND_DONE:
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_DONE";
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		if(indexToActOnDisplay <=0){
			return MESSAGE_ERROR_INVALID_INDEX;
		} else{
			indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent,indexToActOnDisplay);
			doneResults = newTaskDone.markDone(indexToActOnStorage);
			newTaskDone.undoDone(&undoTask, doneResults);
			return doneResults;
		}
	case COMMAND_UNDONE:
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_UNDONE";
		displayTask.updateStorageSource();
		currentDisplayContent = displayTask.getDisplayContent();
		indexToActOnDisplay = currentCommandReference.getIndexToBeActOn();
		if(indexToActOnDisplay <=0){
			return MESSAGE_ERROR_INVALID_INDEX;
		}else{
			indexToActOnStorage = displayTask.getStorageIndex(currentDisplayContent,indexToActOnDisplay);
			undoneResults = newTaskDone.markUndone(indexToActOnStorage);	
			newTaskDone.undoUndone(&undoTask, undoneResults);
			return undoneResults;
		}
	case COMMAND_UNDO:
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_UNDO";
		if(undoTask.getCurrentStack().size()!=1){
			redoTask.redo(undoTask);
		}
		undoResults = undoTask.executeUndo();
	//	if(undoResults.compare(MESSAGE_SUCCESS_UNDO)==0){
			//redoTask.redo(undoTask);
		//}
		return undoResults;
	case COMMAND_FLIP:	
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_FLIP";
		FLIP_CONTENT = newParser.getCommandRef().getSearchItem();
		return "Flipped!";
	case COMMAND_SPECIFY:
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_SPECIFY";
		return "";
	case COMMAND_REDO:
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_REDO";
		redoResults = redoTask.executeRedo(&undoTask);
		return redoResults;
	case COMMAND_TOGGLE:
		LOG(INFO) << "Entered Class: Logic. Case: COMMAND_TOGGLE";
		return "Toggled!";	
	default:
		return "";
	return "";
	}
}

//author A0125489U
int logic::updateUIFlipCount(){
	taskDisplay displayTask;
	timeAndDate tD;
	int totalDiff=0;
	std::string flipContentYear;
	std::string flipContentMonth;
	std::string flipContentDate;
	std::string todayYear;
	std::string todayMonth;
	std::string todayDate;
	if(FLIP_CONTENT.length()>4 && FLIP_CONTENT.length()<=8){
		flipContentYear = FLIP_CONTENT.substr(4);
		flipContentMonth = FLIP_CONTENT.substr(2,2);
		flipContentDate = FLIP_CONTENT.substr(0,2);
		todayYear = displayTask.getTodayDateYear(0);
		todayMonth = displayTask.getTodayDateMonth(0);
		todayDate = displayTask.getTodayDate(0);
		totalDiff = tD.calDay(atoi(flipContentYear.c_str()),atoi(flipContentMonth.c_str()),atoi(flipContentDate.c_str())) 
			- tD.calDay(atoi(todayYear.c_str()),atoi(todayMonth.c_str()),atoi(todayDate.c_str())) -1;
		FLIP_CONTENT="";
	} 
	return totalDiff;
}

//author A0125489U
std::vector<std::string> logic::updateUI(std::string logicResult , int toggleIndex, int flipCount){
	taskDisplay displayTask;
	std::string displayLeft;
	std::string displayRight;
	std::vector<std::string> displayResults;
	displayResults.push_back(displayTask.getTodayDate(flipCount));
	displayResults.push_back(displayTask.getNextDayDate(flipCount));
	displayResults.push_back(displayTask.getTodayDateYear(flipCount));
	displayResults.push_back(displayTask.getTodayDateMonth_Abbreviated(flipCount));
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
		return COMMAND_ADD;
	}
	if(commandAction.compare(commandDelete) == 0){ 
		return COMMAND_DELETE;
	}
	if(commandAction.compare(commandSearch) == 0){ 
		return COMMAND_SEARCH;
	}
	if(commandAction.compare(commandDisplay) == 0){ 
		return COMMAND_DISPLAY;
	}
	if(commandAction.compare(commandEdit) == 0){ 
		return COMMAND_EDIT;
	}
	if(commandAction.compare(commandDone) == 0){
		return COMMAND_DONE;
	}
	if(commandAction.compare(commandUndone) == 0){
		return COMMAND_UNDONE;
	}
	if(commandAction.compare(commandUndo) == 0){ 
		return COMMAND_UNDO;
	}
	if(commandAction.compare(commandFlip) == 0){ 
		return COMMAND_FLIP;
	}
	if(commandAction.compare(commandSpecify) == 0){ 
		return COMMAND_SPECIFY;
	}
	if(commandAction.compare(commandRedo) == 0){ 
		return COMMAND_REDO;
	}
	if(commandAction.compare(commandToggle) == 0){ 
		return COMMAND_TOGGLE;
	}
	if(commandAction.compare(commandCheckDone) == 0){ 
		return COMMAND_DONE;
	}
}