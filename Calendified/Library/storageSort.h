//author @a0114411b
#pragma once

#ifndef STORAGESORT_H
#define STORAGESORT_H
#include <vector>
#include <iostream>
#include "task.h"

class storageSort
{
public:
	storageSort(void);
	~storageSort(void);

	std::vector<std::string> sortData(std::vector<std::string> file);
	std::vector<task> sortVector(std::vector<task> commandVector);
	std::vector<task> switchPlace(int i, int j, std::vector<task> commandVector);

};

#endif