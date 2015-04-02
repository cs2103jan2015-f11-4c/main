#pragma once
#ifndef UNDO_H
#define UNDO_H
#include <stack>
#include <vector>
#include "task.h"

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
	void setCurrentStack(std::stack<std::vector<task>> stack);
	void setSessionStack(std::stack<std::vector<task>> stack);
	void insertVector(std::vector<task> vector);
	bool isEmpty(std::stack<std::vector<task>> vectorTasks);
	bool isUndone();
	std::string undoResults();
};

#endif

