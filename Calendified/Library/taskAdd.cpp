//@author A0116027R

//Add a task in the following steps:
//Step 1: Check if task title, time and date are valid, and if a storage file exists
//Step 2: Extract data from storage file to a vector of tasks
//Step 3: Add the task to the vector
//Step 4: Write vector into storage file
//Step 5: Return success message if task is successfully added
//Update stack in taskUndo class so for undo execution
//Example user input to edit a task: "add do homework 12pm 13/4/2015"

#include "taskAdd.h"

taskAdd::taskAdd(){
}

taskAdd::~taskAdd(void)
{
}

bool taskAdd::notValidTitle(){
	return (getTask().getTitle() == "");

}

std::string taskAdd::executeAdd(){
	storage storageFile;
	std::vector<task> taskStorage;
	if(notValidTitle()){
		return MESSAGE_FAILURE_ADD;
	}
	 if(_task.getTimeAndDate().isValid() && storageFile.isFileExist()){
		if(storageFile.isFileEmpty()){
			storageFile.writeFileJson(taskStorage);
		}
		taskStorage = storageFile.readFileJson();

		bool clash = isClash(taskStorage);
		try {
			taskStorage.push_back(_task);
			storageFile.writeFileJson(taskStorage);
			if(clash){
				return MESSAGE_WARNING_ADD_CLASH;
			}else {
				return MESSAGE_SUCCESS_ADD;
			}
		} catch (const std::exception& e){
			return MESSAGE_FAILURE_ADD;
		}
	} else {
		return MESSAGE_FAILURE_ADD;
	}
}

void taskAdd::undoAdd(taskUndo* taskToBeUndone, std::string results){
	storage storageFile;

	if((results == MESSAGE_SUCCESS_ADD) || (results == MESSAGE_WARNING_ADD_CLASH)){
		taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
		taskToBeUndone->insertVector(storageFile.readFileJson());
	}
}

//if either is floating task, shouldnt ignore
bool isValidConditions(task newTask, task storedTask){
	if(newTask.getTaskType()!= FLOATING_TASK
		&& storedTask.getTaskType() != FLOATING_TASK){
			return true;
	} else {
		return false;
	}
}

//checks if both dates are different and it clashes
bool isEndDateClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getEndMDay() > storedTask.getTimeAndDate().getStartMDay()
		&& newTask.getTimeAndDate().getEndMonth() > storedTask.getTimeAndDate().getStartMonth()
		&& newTask.getTimeAndDate().getEndYear() > storedTask.getTimeAndDate().getStartYear()
		&& newTask.getTimeAndDate().getEndMDay() < storedTask.getTimeAndDate().getEndMDay()
		&& newTask.getTimeAndDate().getEndMonth() < storedTask.getTimeAndDate().getEndMonth()
		&& newTask.getTimeAndDate().getEndYear() < storedTask.getTimeAndDate().getEndYear()){
			return true;
	} else {
		return false;
	}
}

//checks if both dates are different and it clashes
bool isStartDateClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartMDay() > storedTask.getTimeAndDate().getStartMDay()
		&& newTask.getTimeAndDate().getStartMonth() > storedTask.getTimeAndDate().getStartMonth()
		&& newTask.getTimeAndDate().getStartYear() > storedTask.getTimeAndDate().getStartYear()
		&& newTask.getTimeAndDate().getStartMDay() < storedTask.getTimeAndDate().getEndMDay()
		&& newTask.getTimeAndDate().getStartMonth() < storedTask.getTimeAndDate().getEndMonth()
		&& newTask.getTimeAndDate().getStartYear() < storedTask.getTimeAndDate().getEndYear()){
			return true;
	} else {
		return false;
	}
}

//checks if both dates are different and it clashes
bool isBothDatesClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartMDay() < storedTask.getTimeAndDate().getStartMDay()
		&& newTask.getTimeAndDate().getStartMonth() < storedTask.getTimeAndDate().getStartMonth()
		&& newTask.getTimeAndDate().getStartYear() < storedTask.getTimeAndDate().getStartYear()
		&& newTask.getTimeAndDate().getEndMDay() > storedTask.getTimeAndDate().getEndMDay()
		&& newTask.getTimeAndDate().getEndMonth() > storedTask.getTimeAndDate().getEndMonth()
		&& newTask.getTimeAndDate().getEndYear() > storedTask.getTimeAndDate().getEndYear()){
			return true;
	} else {
		return false;
	}
}

//checks if both timings clashes
bool isEndTimeClashWithStartTime(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getEndTimeHour() >= storedTask.getTimeAndDate().getStartTimeHour()
		&& newTask.getTimeAndDate().getEndTimeMin() > storedTask.getTimeAndDate().getStartTimeMin()
		&& newTask.getTimeAndDate().getEndTimeHour() <= storedTask.getTimeAndDate().getEndTimeHour()
		&& newTask.getTimeAndDate().getEndTimeMin() <= storedTask.getTimeAndDate().getEndTimeMin()){
			return true;
	} else {
		return false;
	}
}

//checks if both timings clashes
bool isStartTimeClashWithEndTime(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartTimeHour() >= storedTask.getTimeAndDate().getStartTimeHour()
		&& newTask.getTimeAndDate().getStartTimeMin() >= storedTask.getTimeAndDate().getStartTimeMin()
		&& newTask.getTimeAndDate().getStartTimeHour() <= storedTask.getTimeAndDate().getEndTimeHour()
		&& newTask.getTimeAndDate().getStartTimeMin() < storedTask.getTimeAndDate().getEndTimeMin()){
			return true;
	} else {
		return false;
	}
}

bool isStartTimeClashWithStartTime(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartTimeHour() >= storedTask.getTimeAndDate().getStartTimeHour()
		&& newTask.getTimeAndDate().getStartTimeMin() >= storedTask.getTimeAndDate().getStartTimeMin()){
			return true;
	} else {
		return false;
	}
}

bool isEndTimeClashWithEndTime(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getEndTimeHour() <= storedTask.getTimeAndDate().getEndTimeHour()
		&& newTask.getTimeAndDate().getEndTimeMin() <= storedTask.getTimeAndDate().getEndTimeMin()){
			return true;
	} else {
		return false;
	}
}

//checks if both timings clashes
bool isBothTimesClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartTimeHour() <= storedTask.getTimeAndDate().getStartTimeHour()
		&& newTask.getTimeAndDate().getStartTimeMin() <= storedTask.getTimeAndDate().getStartTimeMin()
		&& newTask.getTimeAndDate().getEndTimeHour() >= storedTask.getTimeAndDate().getEndTimeHour()
		&& newTask.getTimeAndDate().getEndTimeMin() >= storedTask.getTimeAndDate().getEndTimeMin()){
			return true;
	} else {
		return false;
	}
}

bool isSameStartDate(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartMDay() == storedTask.getTimeAndDate().getStartMDay()
		&& newTask.getTimeAndDate().getStartMonth() == storedTask.getTimeAndDate().getStartMonth()
		&& newTask.getTimeAndDate().getStartYear() == storedTask.getTimeAndDate().getStartYear()){
			return true;
	} else {
		return false;
	}
}

bool isSameEndDate(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getEndMDay() > storedTask.getTimeAndDate().getEndMDay()
		&& newTask.getTimeAndDate().getEndMonth() > storedTask.getTimeAndDate().getEndMonth()
		&& newTask.getTimeAndDate().getEndYear() > storedTask.getTimeAndDate().getEndYear()){
			return true;
	} else {
		return false;
	}
}

bool taskAdd::isClash(std::vector<task> &taskStorage){
	for(int i = 0; i < (int)taskStorage.size(); i++){
		if(isValidConditions(_task, taskStorage[i])){
			if(isEndDateClash(_task, taskStorage[i])){ //task have different dates
				_task.setIsClash(true);
				taskStorage[i].setIsClash(true);
				return true;
			} else if(isStartDateClash(_task, taskStorage[i])){ //task have different dates
				_task.setIsClash(true);
				taskStorage[i].setIsClash(true);
				return true;
			} else if(isBothDatesClash(_task, taskStorage[i])){ //task have different dates
				_task.setIsClash(true);
				taskStorage[i].setIsClash(true);
				return true;
			} else if(isSameStartDate(_task, taskStorage[i]) 
				&& isSameEndDate(_task, taskStorage[i])){
				if (isEndTimeClashWithStartTime(_task, taskStorage[i])
					|| isStartTimeClashWithEndTime(_task, taskStorage[i])
					|| isBothDatesClash(_task, taskStorage[i])){
						_task.setIsClash(true);
						taskStorage[i].setIsClash(true);
						return true;
					}
			} else if(isSameStartDate(_task, taskStorage[i]) 
					&& isSameEndDate(_task, taskStorage[i]) == false
					&& isStartTimeClashWithStartTime(_task, taskStorage[i])){
						_task.setIsClash(true);
						taskStorage[i].setIsClash(true);
						return true;
				} else if(isSameStartDate(_task, taskStorage[i]) == false
					&& isSameEndDate(_task, taskStorage[i])
					&& isEndTimeClashWithEndTime(_task, taskStorage[i])){
						_task.setIsClash(true);
						taskStorage[i].setIsClash(true);
						return true;
				}
		}
	}
	return false;
}

task taskAdd::getTask(){
	return _task;
}

void taskAdd::setTask(task newTask){
	_task = newTask;
}