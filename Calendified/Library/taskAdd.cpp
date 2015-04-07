//@author A0116027R

#include "taskAdd.h"

taskAdd::taskAdd(){
}

taskAdd::~taskAdd(void)
{
}

std::string taskAdd::executeAdd(){
	storage storageFile;
	std::vector<task> _taskStorage;
	std::string successMessage = "Added succesfully!";
	std::string failureMessage = "Task not added. Please try again.";
	if(_task.getTimeAndDate().isValid() && storageFile.isFileExist()){
		if(storageFile.isFileEmpty()){
			storageFile.writeFileJson(_taskStorage);
		}
		_taskStorage = storageFile.readFileJson();
		_taskStorage.push_back(_task);		
		try {
			storageFile.writeFileJson(_taskStorage);
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


bool checkIsClash(task newTask, std::vector<task> storageVector){

	for(auto i=0; i<storageVector.size(); i++){

		if(newTask.getTimeAndDate().getStartDay() == storageVector[i].getTimeAndDate().getStartDay()
			&& newTask.getTimeAndDate().getStartTimeHour() != 0
			&& newTask.getTimeAndDate().getEndTimeHour() != 0
			&& storageVector[i].getTaskType() != FloatingTask
			&& storageVector[i].getIsDone() != true
			&& newTask.getIsDone() != true){

				if(newTask.getTimeAndDate().getStartTimeHour() < storageVector[i].getTimeAndDate().getStartTimeHour()
					&& newTask.getTimeAndDate().getEndTimeHour() > storageVector[i].getTimeAndDate().getStartTimeHour()){
						newTask.setIsClash(true);
						storageVector[i].setIsClash(true);
				} else if(newTask.getTimeAndDate().getStartTimeHour() > storageVector[i].getTimeAndDate().getStartTimeHour()
					&& newTask.getTimeAndDate().getStartTimeHour() < storageVector[i].getTimeAndDate().getEndTimeHour()){
						newTask.setIsClash(true);
						storageVector[i].setIsClash(true);
				}

		}
	}

	if(newTask.getIsClash()){
		return true;
	} else {
		return false;
	}

}