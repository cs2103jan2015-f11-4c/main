//@author A0116027R

#include "taskAdd.h"

taskAdd::taskAdd(){
}

taskAdd::~taskAdd(void)
{
	_task = "";
	_taskType = "";
}

std::string taskAdd::taskAddTask(){
	storage storageFile;
	std::vector<std::string> _taskStorage;
	std::string successMessage = "Added succesfully!";
	std::string failureMessage = "Task not added. Please try again.";
	if(storageFile.isFileExist()){
		_taskStorage = storageFile.readFile(_taskType);
		_taskStorage.push_back(_task);
		if(storageFile.writeFile(_taskStorage, _taskType)){
			assert (storageFile.writeFile(_taskStorage, _taskType) == 1);
			return successMessage;
		} else {
			return failureMessage;
		}
	}	
}

void taskAdd::taskAddRecurrent(){

}

void taskAdd::setTask(std::string taskString){
	_task = taskString;
}

void taskAdd::setTaskType(std::string taskType){
	_taskType = taskType;
}
