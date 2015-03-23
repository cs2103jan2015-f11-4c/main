//author @a0114411b
#pragma once

#ifndef STORAGESORT_H
#define STORAGESORT_H
#include <vector>
#include <iostream>

class storageSort
{
public:
	storageSort(void);
	~storageSort(void);

	std::vector<std::string> sortData(std::vector<std::string> file);
};

#endif