//@author A0114411B

#ifndef STORAGESORT_H
#define STORAGESORT_H
#pragma once

#include <iostream>
#include <vector>
#include "task.h"

class storageSort
{
public:
	storageSort(void);
	~storageSort(void);

	
	std::vector<task> storageSort::sortvector(std::vector<task> commandVector);

	bool EqualYearButMonthLarger(int i, int j, std::vector<task> commandVector);
	bool EqualYearMonthButDayLarger(int i, int j, std::vector<task> commandVector);
	bool EqualYearMonthDayButHourLarger(int i, int j, std::vector<task> commandVector);
	bool EqualYearMonthDayHourButMinLarger(int i, int j, std::vector<task> commandVector);

	std::vector<task> switchPlace(int i, int j, std::vector<task> commandVector);

	bool isStartYearLarger(int i, int j, std::vector<task> commandVector);
	bool isStartYearEqual(int i, int j, std::vector<task> commandVector);
	bool isStartMonthLarger(int i, int j, std::vector<task> commandVector);
	bool isStartMonthEqual(int i, int j, std::vector<task> commandVector);
	bool isStartDayLarger(int i, int j, std::vector<task> commandVector);
	bool isStartDayEqual(int i, int j, std::vector<task> commandVector);
	bool isStartTimeHourLarger(int i, int j, std::vector<task> commandVector);
	bool isStartTimeHourEqual(int i, int j, std::vector<task> commandVector);
	bool isStartTimeMinLarger(int i, int j, std::vector<task> commandVector);
};

#endif