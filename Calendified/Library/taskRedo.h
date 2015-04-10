//@author A0116027R

#ifndef TASKREDO_H
#define TASKREDO_H
#pragma once

#include <stack>
#include <vector>
#include "task.h"
#include "storage.h"
#include "taskUndo.h"

const std::string MESSAGE_SUCCESS_REDO = 
	"Redo success!";

const std::string MESSAGE_FAILURE_REDO = 
	"Fail to redo.";

class taskRedo
{
private:
	std::stack<std::vector<task>> _currentStack;
	std::stack<std::vector<task>> _sessionStack;

public:
	taskRedo(void);
	~taskRedo(void);

	//getters
	std::stack<std::vector<task>> getCurrentStack();
	std::stack<std::vector<task>> getSessionStack();
	std::vector<task> getTopCurrentVector();
	std::vector<task> getTopSessionVector();

	//setters
	void setCurrentStack(std::stack<std::vector<task>> stack);
	void setSessionStack(std::stack<std::vector<task>> stackTasks);

	void insertCurrentVector(std::vector<task> currentVectorTasks);
	void insertSessionVector(std::vector<task> sessionVectorTasks);
	bool isCurrentStackEmpty();
	bool taskRedo::isSessionStackEmpty();
	void redo(taskUndo taskToBeRedone);
	std::string executeRedo(taskUndo* undoTaskStack);
};

#endif