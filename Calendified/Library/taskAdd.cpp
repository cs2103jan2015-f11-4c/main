//@author A0116027R

#include "taskAdd.h"

taskAdd::taskAdd(){
}

taskAdd::~taskAdd(void)
{
}

std::string taskAdd::executeAdd(){
	LOG(INFO) << "Entered class: taskAdd. Function: executeAdd";
	storage storageFile;
	std::vector<task> taskStorage;
	
	if(_task.getTimeAndDate().isValid() && storageFile.isFileExist()){
		if(storageFile.isFileEmpty()){
			storageFile.writeFileJson(taskStorage);
		}
		taskStorage = storageFile.readFileJson();

		bool clash = isClash(taskStorage);
		LOG_IF(clash,INFO) << "Is Clash detected!";
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

void taskAdd::undoAdd(taskUndo* taskToBeUndone){
	storage storageFile;
	taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
	taskToBeUndone->insertVector(storageFile.readFileJson());
}

void taskAdd::setTask(task newTask){
	_task = newTask;
}

bool isValidConditions(task newTask, task storedTask){
	if(storedTask.getTaskType() != FLOATING_TASK
		&& newTask.getTaskType() != FLOATING_TASK
		&& !storedTask.getIsDone()
		&& !newTask.getIsDone()){
			return true;
	} else {
		return false;
	}
}

bool isEndDateClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getEndMDay() >= storedTask.getTimeAndDate().getStartMDay()
		&& newTask.getTimeAndDate().getEndMonth() >= storedTask.getTimeAndDate().getStartMonth()
		&& newTask.getTimeAndDate().getEndYear() >= storedTask.getTimeAndDate().getStartYear()
		&& newTask.getTimeAndDate().getEndMDay() <= storedTask.getTimeAndDate().getEndMDay()
		&& newTask.getTimeAndDate().getEndMonth() <= storedTask.getTimeAndDate().getEndMonth()
		&& newTask.getTimeAndDate().getEndYear() <= storedTask.getTimeAndDate().getEndYear()){
			return true;
	} else {
		return false;
	}
}

bool isEndTimeClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getEndTimeHour() >= storedTask.getTimeAndDate().getStartTimeHour()
		&& newTask.getTimeAndDate().getEndTimeMin() > storedTask.getTimeAndDate().getStartTimeMin()
		&& newTask.getTimeAndDate().getEndTimeHour() <= storedTask.getTimeAndDate().getEndTimeHour()
		&& newTask.getTimeAndDate().getEndTimeMin() <= storedTask.getTimeAndDate().getEndTimeMin()){
			return true;
	} else {
		return false;
	}
}

bool isStartDateClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartMDay() >= storedTask.getTimeAndDate().getStartMDay()
		&& newTask.getTimeAndDate().getStartMonth() >= storedTask.getTimeAndDate().getStartMonth()
		&& newTask.getTimeAndDate().getStartYear() >= storedTask.getTimeAndDate().getStartYear()
		&& newTask.getTimeAndDate().getStartMDay() <= storedTask.getTimeAndDate().getEndMDay()
		&& newTask.getTimeAndDate().getStartMonth() <= storedTask.getTimeAndDate().getEndMonth()
		&& newTask.getTimeAndDate().getStartYear() <= storedTask.getTimeAndDate().getEndYear()){
			return true;
	} else {
		return false;
	}
}

bool isStartTimeClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartTimeHour() >= storedTask.getTimeAndDate().getStartTimeHour()
		&& newTask.getTimeAndDate().getStartTimeMin() >= storedTask.getTimeAndDate().getStartTimeMin()
		&& newTask.getTimeAndDate().getStartTimeHour() <= storedTask.getTimeAndDate().getEndTimeHour()
		&& newTask.getTimeAndDate().getStartTimeMin() < storedTask.getTimeAndDate().getEndTimeMin()){
			return true;
	} else {
		return false;
	}
}

bool isBothDatesClash(task newTask, task storedTask){
	if(newTask.getTimeAndDate().getStartMDay() <= storedTask.getTimeAndDate().getStartMDay()
		&& newTask.getTimeAndDate().getStartMonth() <= storedTask.getTimeAndDate().getStartMonth()
		&& newTask.getTimeAndDate().getStartYear() <= storedTask.getTimeAndDate().getStartYear()
		&& newTask.getTimeAndDate().getEndMDay() >= storedTask.getTimeAndDate().getEndMDay()
		&& newTask.getTimeAndDate().getEndMonth() >= storedTask.getTimeAndDate().getEndMonth()
		&& newTask.getTimeAndDate().getEndYear() >= storedTask.getTimeAndDate().getEndYear()){
			return true;
	} else {
		return false;
	}
}

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

bool taskAdd::isClash(std::vector<task> &taskStorage){
	LOG(INFO) << "Entered class: taskAdd. Function: isClash";
	for(int i=0; i<taskStorage.size(); i++){
		if(isValidConditions(_task, taskStorage[i])){
			if(isEndDateClash(_task, taskStorage[i]) && isEndTimeClash(_task, taskStorage[i])){
				_task.setIsClash(true);
				taskStorage[i].setIsClash(true);
				return true;
			} else if(isStartDateClash(_task, taskStorage[i]) && isStartTimeClash(_task, taskStorage[i])){
				_task.setIsClash(true);
				taskStorage[i].setIsClash(true);
				return true;
			} else if(isBothDatesClash(_task, taskStorage[i]) && isBothTimesClash(_task, taskStorage[i])){
				_task.setIsClash(true);
				taskStorage[i].setIsClash(true);
				return true;
			} 
		}
	}
	return false;
}