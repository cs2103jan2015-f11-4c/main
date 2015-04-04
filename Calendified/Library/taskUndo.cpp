//@author A0116027R
#include "taskUndo.h"

taskUndo::taskUndo(void){
	std::vector<task> emptyVectorStack;
	_currentStack.push(emptyVectorStack);
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

bool taskUndo::isNotEmpty(std::stack<std::vector<task>> vectorTasks){
	if (vectorTasks.empty()){
		return false;
	} else {
		return true;
	}
}

bool taskUndo::isUndone(){
	int sessionStackSize = _sessionStack.size();
	int currentStackSize = _currentStack.size();
	if (currentStackSize == sessionStackSize+1 || sessionStackSize == currentStackSize+1){
		return true;
	}
	else {
		return false;
	}
}

std::string taskUndo::undoResults(){
	std::string successMessage = "Undone successfully.";
	std::string failureMessage = "Task not undone. Please try again.";

	if(isUndone()){
		return successMessage;
	} else {
		return failureMessage;
	}
}

void taskUndo::popSessionStack(){
	_sessionStack.pop();
}

std::string taskUndo::executeUndo(){
	storage newStorage;

	if(isNotEmpty(_sessionStack)){
		_currentStack = _sessionStack;
		popSessionStack();
		newStorage.writeFileJson(_currentStack.top());
		return undoResults();
	}
}