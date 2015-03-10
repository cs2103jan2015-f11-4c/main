//A0116027R

#include "taskAdd.h"
#include "logic.h"
#include <iostream>
#include <vector>
#include <sstream>

taskAdd::taskAdd(std::string _task){
	_task = toString();
}

std::string taskAdd::toString(){
	logic task;
	std::ostringstream details;
	details << task.getTitle()
			<< task.getLocation()
			<< task.getDescription()
			<< task.getDate()
			<< task.getTime();
	return details.str();
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

void taskAdd::taskAddTask(std::string, std::vector<std::string> _taskStorage){
	std::string fileName = "file1"; //temp filename
	std::string successMessage = "Added succesfully!";
	std::string failureMessage = "Task not added. Please try again.";

	if(readingFile(fileName, _taskStorage)){
		int sizeBeforeAdd = _taskStorage.size();
		_taskStorage.push_back(_task);
		writingFile(fileName, _taskStorage);
		int sizeAfterAdd = _taskStorage.size();

		if (isAdded(sizeBeforeAdd, sizeAfterAdd)){
			std::cout << successMessage;
		} else {
			std::cout << failureMessage;
		}
	}	
}

void taskAdd::taskAddRecurrent(std::string){
}

void taskAdd::taskAddTitle(std::string){
}

void taskAdd::taskAddLocation(std::string){
}//floating task

void taskAdd::taskAddDescription(std::string){
}//floating task

bool taskAdd::isAdded(int sizeBeforeAdd, int sizeAfterAdd){
	if (sizeAfterAdd == sizeBeforeAdd+1){
		return true;
	}
	else{
		return false;
	}
}

taskAdd::~taskAdd(void)
{
}

