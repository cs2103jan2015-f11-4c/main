//@author A0116027R

//Edit a task in the following steps:
//Step 1: Take in an index and identify which task is to be edited
//Step 2: Checks if storage file has any task to edit
//Step 3: Extract data from storage file to a vector of tasks
//Step 4: Edits the original task from the storage file by comparing 
//it with the data from the user input
//Step 5: Adds the task to the vector
//Step 6: Write vector into storage file
//Step 7: Return success message if task is successfully edited
//Updates stack in taskUndo class so for undo execution
//Example user input to edit a task: "edit 1 12pm"

#include "taskEdit.h"

taskEdit::taskEdit(void){
}

taskEdit::~taskEdit(void){
}

bool isDoneEdited(task editingReference, task originalTask){
	if(editingReference.getIsDone() == true 
		&& editingReference.getIsDone() != originalTask.getIsDone()){
		return true;
	} else {
		return false;
	}
}

bool isLocationEdited(task editingReference, task originalTask){
	if(!editingReference.getLocation().empty() 
		&& (editingReference.getLocation() != originalTask.getLocation())){
		return true;
	} else {
		return false;
	}
}

bool isNotEmptyTime(task editingReference){
	if(editingReference.getTimeAndDate().getStartTimeHour() == 0
		&& editingReference.getTimeAndDate().getStartTimeMin() == 0
		&& editingReference.getTimeAndDate().getEndTimeHour() == 0
		&& editingReference.getTimeAndDate().getEndTimeMin() == 0){
			return false;
	} else {
		return true;
	}
}

bool isTimeEdited(task editingReference, task originalTask){
	if(isNotEmptyTime(editingReference)
		&& (editingReference.getTimeAndDate().getStartTimeHour() != originalTask.getTimeAndDate().getStartTimeHour()
		|| editingReference.getTimeAndDate().getStartTimeMin() != originalTask.getTimeAndDate().getStartTimeMin()
		|| editingReference.getTimeAndDate().getEndTimeHour() != originalTask.getTimeAndDate().getEndTimeHour()
		|| editingReference.getTimeAndDate().getEndTimeMin() != originalTask.getTimeAndDate().getEndTimeMin())){
			return true;
	} else {
		return false;
	}
}

timeAndDate editedTime(task editingReference, task taskToBeEdited){
	timeAndDate tempTimeAndDate;
	tempTimeAndDate.setStartTimeHour(editingReference.getTimeAndDate().getStartTimeHour());
	tempTimeAndDate.setStartTimeMin(editingReference.getTimeAndDate().getStartTimeMin());
	tempTimeAndDate.setEndTimeHour(editingReference.getTimeAndDate().getEndTimeHour());
	tempTimeAndDate.setEndTimeMin(editingReference.getTimeAndDate().getEndTimeMin());
	tempTimeAndDate.setStartMDay(taskToBeEdited.getTimeAndDate().getStartMDay());
	tempTimeAndDate.setStartMonth(taskToBeEdited.getTimeAndDate().getStartMonth());
	tempTimeAndDate.setStartYear(taskToBeEdited.getTimeAndDate().getStartYear());
	tempTimeAndDate.setEndMDay(taskToBeEdited.getTimeAndDate().getEndMDay());
	tempTimeAndDate.setEndMonth(taskToBeEdited.getTimeAndDate().getEndMonth());
	tempTimeAndDate.setEndYear(taskToBeEdited.getTimeAndDate().getEndYear());

	return tempTimeAndDate;
}

bool isNotEmptyDate(task editingReference){
	if(editingReference.getTimeAndDate().getStartMDay() <= 0
		&& editingReference.getTimeAndDate().getStartMonth() <= 0
		&& editingReference.getTimeAndDate().getStartYear() <= 0
		&& editingReference.getTimeAndDate().getEndMDay() <= 0
		&& editingReference.getTimeAndDate().getEndMonth() <= 0
		&& editingReference.getTimeAndDate().getEndYear() <= 0){
			return false;
	} else {
		return true;
	}
}
bool isDateEdited(task editingReference, task originalTask){
	if(isNotEmptyDate(editingReference)
		&& (editingReference.getTimeAndDate().getStartMDay() != originalTask.getTimeAndDate().getStartMDay()
		|| editingReference.getTimeAndDate().getStartMonth() != originalTask.getTimeAndDate().getStartMonth()
		|| editingReference.getTimeAndDate().getStartYear() != originalTask.getTimeAndDate().getStartYear()
		|| editingReference.getTimeAndDate().getEndMDay() != originalTask.getTimeAndDate().getEndMDay()
		|| editingReference.getTimeAndDate().getEndMonth() != originalTask.getTimeAndDate().getEndMonth()
		|| editingReference.getTimeAndDate().getEndYear() != originalTask.getTimeAndDate().getEndYear())){
			return true;
	} else {
		return false;
	}
}

timeAndDate editedDate(task editingReference, task taskToBeEdited){
	timeAndDate tempTimeAndDate;
	tempTimeAndDate.setStartMDay(editingReference.getTimeAndDate().getStartMDay());
	tempTimeAndDate.setStartMonth(editingReference.getTimeAndDate().getStartMonth());
	tempTimeAndDate.setStartYear(editingReference.getTimeAndDate().getStartYear());
	tempTimeAndDate.setEndMDay(editingReference.getTimeAndDate().getEndMDay());
	tempTimeAndDate.setEndMonth(editingReference.getTimeAndDate().getEndMonth());
	tempTimeAndDate.setEndYear(editingReference.getTimeAndDate().getEndYear());
	tempTimeAndDate.setStartTimeHour(taskToBeEdited.getTimeAndDate().getStartTimeHour());
	tempTimeAndDate.setStartTimeMin(taskToBeEdited.getTimeAndDate().getStartTimeMin());
	tempTimeAndDate.setEndTimeHour(taskToBeEdited.getTimeAndDate().getEndTimeHour());
	tempTimeAndDate.setEndTimeMin(taskToBeEdited.getTimeAndDate().getEndTimeMin());
	
	return tempTimeAndDate;
}

void taskTypeEdited(task* originalTask){
	if(originalTask->getTimeAndDate().getStartMDay() > 0
		&& originalTask->getTimeAndDate().getStartMonth() > 0
		&& originalTask->getTimeAndDate().getStartYear() > 0){
			originalTask->setTaskType("TimedTask");
	} else if(originalTask->getTimeAndDate().getEndMDay() > 0
		&& originalTask->getTimeAndDate().getEndMonth() > 0
		&& originalTask->getTimeAndDate().getEndYear() > 0){
			originalTask->setTaskType("DeadLine");
	} else {
		originalTask->setTaskType("FloatingTask");
	}
}

bool isTitleEdited(task editingReference, task originalTask){
	if((!editingReference.getTitle().empty()) && editingReference.getTitle() != originalTask.getTitle()){
		return true;
	} else {
		return false;
	}
}

std::string taskEdit::executeEdit(int indexToBeEdited){
	std::vector<task> storageTasks;
	storage newStorage;
	try{
		if(newStorage.isFileExist()){	
			storageTasks = newStorage.readFileJson();
			if(storageTasks.empty()){
				return MESSAGE_ERROR_FILE_IS_EMPTY;
			} else if(indexToBeEdited > storageTasks.size()){
				return MESSAGE_ERROR_INVALID_INDEX;
			} else {
				assert(indexToBeEdited >= 0);
				task taskToBeEdited = storageTasks[indexToBeEdited];
				
				if(isDoneEdited(_editingReference, taskToBeEdited)){
					taskToBeEdited.setIsDone(_editingReference.getIsDone());
				} //only edits undone to done
				if(isLocationEdited(_editingReference, taskToBeEdited)){
					taskToBeEdited.setLocation(_editingReference.getLocation());
				}
				if(isTimeEdited(_editingReference, taskToBeEdited)){
					timeAndDate tempTimeAndDate = editedTime(_editingReference, taskToBeEdited);
					taskToBeEdited.setTimeAndDate(tempTimeAndDate);
				}
				if(isDateEdited(_editingReference, taskToBeEdited)){
					timeAndDate tempTimeAndDate1 = editedDate(_editingReference, taskToBeEdited);
					taskToBeEdited.setTimeAndDate(tempTimeAndDate1);
				}
				if(isTitleEdited(_editingReference, taskToBeEdited)){
					taskToBeEdited.setTitle(_editingReference.getTitle());
				}
				taskTypeEdited(&taskToBeEdited);
				storageTasks[indexToBeEdited] = taskToBeEdited;
				try {
					newStorage.writeFileJson(storageTasks);
					return MESSAGE_SUCCESS_EDIT;
				} catch (const std::exception& e){
					return MESSAGE_FAILURE_EDIT;
				}
			}
		} else {
			return MESSAGE_ERROR_EDIT_FILE_NONEXISTENT;
		}
	} catch (const std::exception& e){
		return MESSAGE_FAILURE_EDIT;
	}
}

void taskEdit::undoEdit(taskUndo* taskToBeUndone, std::string results){
	storage storageFile;

	if(results == MESSAGE_SUCCESS_EDIT){
		taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
		taskToBeUndone->insertVector(storageFile.readFileJson());
	}
}

void taskEdit::setEditingRef(task currentTaskData){
	_editingReference = currentTaskData;
}