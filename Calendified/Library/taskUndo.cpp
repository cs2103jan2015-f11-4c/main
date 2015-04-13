//@author A0116027R

//Undo is maintained by two stacks of vector<task>, _currentStack and _sessionStack
//Top of _currentStack contains the most updated vector of tasks while
//top of _sessionStack contains the previous vector of tasks
//Undo a task in the following steps:
//Step 1: Check if _sessionStack is empty
//Step 2: Update the two stacks if undo is possible
//Step 3: Write top vector of _currentStack into storage file
//Step 5: Return success message if undo is successful
//Example user input to undo a task: "undo"

#include "taskUndo.h"

taskUndo::taskUndo(void){
	storage readStorage;
	std::vector<task> vectorStack;
	if(readStorage.isFileEmpty()){
		readStorage.writeFileJson(vectorStack);
	}
	vectorStack = readStorage.readFileJson();
	_currentStack.push(vectorStack);
}

taskUndo::~taskUndo(void){
}

std::stack<std::vector<task>> taskUndo::getCurrentStack(){
	return _currentStack;
}

std::stack<std::vector<task>> taskUndo::getSessionStack(){
	return _sessionStack;
}

void taskUndo::setCurrentStack(std::stack<std::vector<task>> stack){
	_currentStack = stack;
}

void taskUndo::setSessionStack(std::stack<std::vector<task>> stackTasks){
	_sessionStack = stackTasks;
}

void taskUndo::insertVector(std::vector<task> vectorTasks){
	_currentStack.push(vectorTasks);
}

void taskUndo::insertSessionVector(std::vector<task> vectorTasks){
	_sessionStack.push(vectorTasks);
}

bool taskUndo::isNotEmpty(std::stack<std::vector<task>> vectorTasks){
	if (vectorTasks.empty()){
		return false;
	} else {
		return true;
	}
}

void taskUndo::popSessionStack(){
	_sessionStack.pop();
}

std::string taskUndo::executeUndo(){
	storage newStorage;
	try{
		if(isNotEmpty(_sessionStack)){
			_currentStack = _sessionStack;
			popSessionStack();
			newStorage.writeFileJson(_currentStack.top());
			return MESSAGE_SUCCESS_UNDO;
		} else {
			return MESSAGE_ERROR_CANNOT_UNDO;
		}
	}
	catch (const std::exception& e){
		return MESSAGE_ERROR_CANNOT_UNDO;
	}
}