//@author A0116027R

#include "taskRedo.h"


taskRedo::taskRedo(void)
{
}

taskRedo::~taskRedo(void)
{
}

std::stack<std::vector<task>> taskRedo::getCurrentStack(){
	return _currentStack;
}

std::stack<std::vector<task>> taskRedo::getSessionStack(){
	return _sessionStack;
}

std::vector<task> taskRedo::getTopCurrentVector(){
	std::vector<task> topCurrentVector = _currentStack.top();
	return topCurrentVector;
}

std::vector<task> taskRedo::getTopSessionVector(){
	std::vector<task> topSessionVector = _sessionStack.top();
	return topSessionVector;
}

void taskRedo::setCurrentStack(std::stack<std::vector<task>> stack){
	_currentStack = stack;
}

void taskRedo::setSessionStack(std::stack<std::vector<task>> stackTasks){
	_sessionStack = stackTasks;
}

void taskRedo::insertCurrentVector(std::vector<task> currentVectorTasks){
	_currentStack.push(currentVectorTasks);
}

void taskRedo::insertSessionVector(std::vector<task> sessionVectorTasks){
	_sessionStack.push(sessionVectorTasks);
}

bool taskRedo::isCurrentStackEmpty(){
	if(_currentStack.empty()){
		return true;
	} else {
		return false;
	}
}

bool taskRedo::isSessionStackEmpty(){
	if(_sessionStack.empty()){
		return true;
	} else {
		return false;
	}
}

void taskRedo::redo(taskUndo taskToBeRedone){
	std::vector<task> currentVectorTasks;
	std::vector<task> sessionVectorTasks;

	if(taskToBeRedone.isNotEmpty(taskToBeRedone.getCurrentStack())){
		currentVectorTasks = taskToBeRedone.getCurrentStack().top();
		_currentStack.push(currentVectorTasks);
	}
	if(taskToBeRedone.isNotEmpty(taskToBeRedone.getSessionStack())){
		sessionVectorTasks = taskToBeRedone.getSessionStack().top();
		_sessionStack.push(sessionVectorTasks);
	}
}

std::string taskRedo::executeRedo(taskUndo* undoTaskStack){
	if(isCurrentStackEmpty() || isSessionStackEmpty()){
		return MESSAGE_FAILURE_REDO;
	}
	storage newStorage;
	undoTaskStack->insertVector(getTopCurrentVector());
	newStorage.writeFileJson(getTopCurrentVector());
	_currentStack.pop();
	undoTaskStack->insertSessionVector(getTopSessionVector());
	_sessionStack.pop();

	return MESSAGE_SUCCESS_REDO;
}