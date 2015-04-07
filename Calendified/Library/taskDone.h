//author @a0114411b

#ifndef TASKDONE_H
#define TASKDONE_H
#pragma once

#include "task.h"
#include <vector>
#include <iostream>

class taskDone
{
public:
	taskDone(void);
	~taskDone(void);

	void markDone(int indexToBeActOn);
	void markUndone(int indexToBeActOn);
	std::vector<task> getListDone();


};

#endif