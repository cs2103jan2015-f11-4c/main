//@author A0114411B

#include "storageSort.h"
#include <algorithm>
#include <string>

storageSort::storageSort(void)
{
}


storageSort::~storageSort(void)
{
}

std::vector<task> storageSort::sortvector(std::vector<task> commandVector){
	for(int i=0; i<commandVector.size(); i++){
		for(int j=0; j<commandVector.size(); j++){
			if(isStartYearLarger(i,j,commandVector)){
				commandVector = switchPlace(i,j,commandVector);
			} else if(isStartYearEqual(i, j, commandVector) 
				&& isStartMonthLarger(i, j, commandVector)){
					commandVector = switchPlace(i,j,commandVector);
			} else if(isStartYearEqual(i,j,commandVector)
				&& isStartMonthEqual(i, j, commandVector)
				&& isStartDayLarger(i, j, commandVector)){
					commandVector = switchPlace(i,j,commandVector);
			} else if(isStartYearEqual(i,j,commandVector)
				&& isStartMonthEqual(i,j,commandVector)
				&& isStartDayEqual(i, j, commandVector)
				&& isStartTimeHourLarger(i, j, commandVector)){
					commandVector = switchPlace(i,j,commandVector);
			} else if(isStartYearEqual(i,j,commandVector)
				&& isStartMonthEqual(i,j,commandVector)
				&& isStartDayEqual(i, j, commandVector)
				&& isStartTimeHourEqual(i, j, commandVector)
				&& isStartTimeMinLarger(i,j,commandVector)){
					commandVector = switchPlace(i,j,commandVector);
			}
		}
	}
	return commandVector;
}


std::vector<task> storageSort::switchPlace(int i, int j, std::vector<task> commandVector){
	task temporaryTask;

	temporaryTask = commandVector[i];
	commandVector[i] = commandVector[j];
	commandVector[j] = temporaryTask;

	return commandVector;
}

bool storageSort::isStartYearLarger(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartYear() > commandVector[i].getTimeAndDate().getStartYear());
}

bool storageSort::isStartYearEqual(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartYear() == commandVector[i].getTimeAndDate().getStartYear());
}

bool storageSort::isStartMonthLarger(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartMonth() > commandVector[i].getTimeAndDate().getStartMonth());
}

bool storageSort::isStartMonthEqual(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartMonth() == commandVector[i].getTimeAndDate().getStartMonth());
}

bool storageSort::isStartDayLarger(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartMDay() > commandVector[i].getTimeAndDate().getStartMDay());
}

bool storageSort::isStartDayEqual(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartMDay() == commandVector[i].getTimeAndDate().getStartMDay());
}

bool storageSort::isStartTimeHourLarger(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartTimeHour() > commandVector[i].getTimeAndDate().getStartTimeHour());
}

bool storageSort::isStartTimeHourEqual(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartTimeHour() == commandVector[i].getTimeAndDate().getStartTimeHour());
}

bool storageSort::isStartTimeMinLarger(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartTimeMin() > commandVector[i].getTimeAndDate().getStartTimeMin());
}
