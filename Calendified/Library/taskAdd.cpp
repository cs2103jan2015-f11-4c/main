//A0116027R

#include "taskAdd.h"
#include "logic.h"
#include <iostream>
#include <vector>

taskAdd::taskAdd(std::string _task){
	logic newLogic;
	_task = newLogic.toString();
}

taskAdd::~taskAdd(void)
{
}

bool taskAdd::readingFile(std::string fileName, std::vector<std::string> _taskStorage){
	std::ifstream readFile(fileName);
	std::string task;
	while (getline(readFile, task)){
		_taskStorage.push_back(task);
	}
	readFile.close();
	return true;
}

bool taskAdd::writingFile(std::string fileName, std::vector<std::string> _taskStorage){
	std::ofstream writeFile(fileName);
	for(int countTask=0; countTask<_taskStorage.size(); countTask++){
		writeFile << _taskStorage[countTask]
				  << std::endl;
	}
	writeFile.close();
	return true;
}

std::string taskAdd::taskAddTask(std::vector<std::string> _taskStorage){
	std::string fileName = "storage.txt"; //temp filename
	std::string successMessage = "Added succesfully!";
	std::string failureMessage = "Task not added. Please try again.";

	if(readingFile(fileName, _taskStorage)){
		int sizeBeforeAdd = _taskStorage.size();
		_taskStorage.push_back(_task);
		writingFile(fileName, _taskStorage);
		int sizeAfterAdd = _taskStorage.size();

		if (isAdded(sizeBeforeAdd, sizeAfterAdd)){
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

bool taskAdd::isAdded(int sizeBeforeAdd, int sizeAfterAdd){
	if (sizeAfterAdd == sizeBeforeAdd+1){
		return true;
	}
	else{
		return false;
	}
}

