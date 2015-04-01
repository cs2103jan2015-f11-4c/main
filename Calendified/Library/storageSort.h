//author @a0114411b
#pragma once

#ifndef STORAGESORT_H
#define STORAGESORT_H
#include <vector>
#include <iostream>
#include "commandRef.h"

class storageSort
{
public:
	storageSort(void);
	~storageSort(void);

	std::vector<std::string> sortData(std::vector<std::string> file);

	std::vector<commandRef> sortVector(std::vector<commandRef> commandVector);

};

#endif