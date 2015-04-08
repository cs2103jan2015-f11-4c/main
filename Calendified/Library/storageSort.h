//@author A0114411B
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

	std::vector<task> switchPlace(int i, int j, std::vector<task> commandVector);
	std::vector<task> sortvector(std::vector<task> commandVector);
};

#endif