//@author A0116027R

#include "taskAdd.h"

taskAdd::taskAdd(){
}

taskAdd::~taskAdd(void)
{
}

std::string taskAdd::taskAddTask(){
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
		//} else {
		//	return failureMessage;
		//}
	} else {
		return failureMessage;
	}
}

void taskAdd::taskAddRecurrent(){

}

void taskAdd::setTask(task newTask){
	_task = newTask;
}
