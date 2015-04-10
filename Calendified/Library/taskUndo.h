//@author A0116027R

#ifndef TASKUNDO_H
#define TASKUNDO_H
#pragma once

#include <stack>
#include <vector>
#include "task.h"
#include "storage.h"

class taskUndo
{
private:
	std::stack<std::vector<task>> _currentStack;
	std::stack<std::vector<task>> _sessionStack;
public:
	taskUndo(void);
	~taskUndo(void);

	//getters
	std::stack<std::vector<task>> getCurrentStack();
	std::stack<std::vector<task>> getSessionStack();
	//setters
	void setCurrentStack(std::stack<std::vector<task>> stack);
	void setSessionStack(std::stack<std::vector<task>> stack);
	void insertVector(std::vector<task> vector);
	void insertSessionVector(std::vector<task> vectorTasks);

	bool isNotEmpty(std::stack<std::vector<task>> vectorTasks);
	bool isUndone();
	std::string undoResults();
	void popSessionStack();
	std::string executeUndo();
};

#endif