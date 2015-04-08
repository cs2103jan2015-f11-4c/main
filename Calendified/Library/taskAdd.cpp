//@author A0116027R

#include "taskAdd.h"

taskAdd::taskAdd(){
}

taskAdd::~taskAdd(void)
{
}

std::string taskAdd::executeAdd(){
	storage storageFile;
	std::vector<task> taskStorage;
	std::string successMessage = "Added succesfully!";
	std::string failureMessage = "Task not added. Please try again.";

	if(_task.getTimeAndDate().isValid() && storageFile.isFileExist()){
		if(storageFile.isFileEmpty()){
			storageFile.writeFileJson(taskStorage);
		}
		taskStorage = storageFile.readFileJson();
		taskStorage.push_back(_task);

		try {
			storageFile.writeFileJson(taskStorage);
			return successMessage;
		} catch (const std::exception& e){
			return failureMessage;
		}
	} else {
		return failureMessage;
	}
}

void taskAdd::undoAdd(taskUndo* taskToBeUndone){
	storage storageFile;
	taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
	taskToBeUndone->insertVector(storageFile.readFileJson());
}

void taskAdd::taskAddRecurrent(){

}

void taskAdd::setTask(task newTask){
	_task = newTask;
}

bool taskAdd::isClash(std::vector<task> taskStorage){
	for(auto i=0; i<taskStorage.size(); i++){
		if(_task.getTimeAndDate().getStartMDay() == taskStorage[i].getTimeAndDate().getStartMDay()
			&& _task.getTimeAndDate().getStartMonth() == taskStorage[i].getTimeAndDate().getStartMonth()
			&& _task.getTimeAndDate().getStartYear() == taskStorage[i].getTimeAndDate().getStartYear()
			&& _task.getTimeAndDate().getEndMDay() == taskStorage[i].getTimeAndDate().getEndMDay()
			&& _task.getTimeAndDate().getEndMonth() == taskStorage[i].getTimeAndDate().getEndMonth()
			&& _task.getTimeAndDate().getEndYear() == taskStorage[i].getTimeAndDate().getEndYear()
			&& _task.getTimeAndDate().getStartTimeHour() != 0
			&& _task.getTimeAndDate().getEndTimeHour() != 0
			&& taskStorage[i].getTaskType() != FloatingTask
			&& !taskStorage[i].getIsDone()
			&& !_task.getIsDone()){

				if(_task.getTimeAndDate().getEndTimeHour() >= taskStorage[i].getTimeAndDate().getStartTimeHour()
					&& _task.getTimeAndDate().getEndTimeMin() > taskStorage[i].getTimeAndDate().getStartTimeMin()
					&& _task.getTimeAndDate().getEndTimeHour() <= taskStorage[i].getTimeAndDate().getEndTimeHour()
					&& _task.getTimeAndDate().getEndTimeMin() <= taskStorage[i].getTimeAndDate().getEndTimeMin()){
						_task.setIsClash(true);
						taskStorage[i].setIsClash(true);
						return true;
				} else if(_task.getTimeAndDate().getStartTimeHour() >= taskStorage[i].getTimeAndDate().getStartTimeHour()
					&& _task.getTimeAndDate().getStartTimeMin() >= taskStorage[i].getTimeAndDate().getStartTimeMin()
					&& _task.getTimeAndDate().getStartTimeHour() <= taskStorage[i].getTimeAndDate().getEndTimeHour()
					&& _task.getTimeAndDate().getStartTimeMin() < taskStorage[i].getTimeAndDate().getEndTimeMin()){
						_task.setIsClash(true);
						taskStorage[i].setIsClash(true);
						return true;
				} else if(_task.getTimeAndDate().getStartTimeHour() <= taskStorage[i].getTimeAndDate().getStartTimeHour()
					&& _task.getTimeAndDate().getStartTimeMin() < taskStorage[i].getTimeAndDate().getStartTimeMin()
					&& _task.getTimeAndDate().getEndTimeHour() >= taskStorage[i].getTimeAndDate().getEndTimeHour()
					&& _task.getTimeAndDate().getEndTimeMin() > taskStorage[i].getTimeAndDate().getEndTimeMin()){
						_task.setIsClash(true);
						taskStorage[i].setIsClash(true);
						return true;
				} else {
					return false;
				}
		}
	}
}