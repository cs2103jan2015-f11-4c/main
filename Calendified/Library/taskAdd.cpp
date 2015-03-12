//@author A0116027R

#include "taskAdd.h"

taskAdd::taskAdd(){
}

taskAdd::~taskAdd(void)
{
	_task ="";
}

std::string taskAdd::taskAddTask(){
	storage storageFile;
	std::vector<std::string> _taskStorage;
	std::string successMessage = "Added succesfully!";
	std::string failureMessage = "Task not added. Please try again.";

	if(storageFile.isFileExist()){
		_taskStorage = storageFile.readFile();
		_taskStorage.push_back(_task);
		if(storageFile.writeFile(_taskStorage)){
			return successMessage;
		} else {
			return failureMessage;
		}
	}	
}

void taskAdd::taskAddRecurrent(){

}

void taskAdd::taskAddTitle(){
}

void taskAdd::taskAddLocation(){
}//floating task

void taskAdd::taskAddDescription(){
}//floating task

void taskAdd::set_task(std::string taskString){
	_task = taskString;
}
