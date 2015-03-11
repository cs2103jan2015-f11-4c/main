//A0116027R

#include "taskAdd.h"
#include "logic.h"
#include "storage.h"
#include <iostream>
#include <vector>

taskAdd::taskAdd(std::string _task){
	parser taskReference;
	taskRef task;

	task = taskReference.getTaskRef();
	_task = task.dataToString(); //to add the task in a string of specific format
								 //command &Title $Time %Date @Location #Description 
}

taskAdd::~taskAdd(void)
{
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

