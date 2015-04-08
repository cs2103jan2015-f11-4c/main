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

	for(auto i=1; i<commandVector.size(); i++){
		for(auto j=0; j<i; j++){
			if(isStartYearLarger(i,j,commandVector)){
				commandVector = switchPlace(i,j,commandVector);
			} else if(isStartYearEqual(i, j, commandVector))
				if(isStartMonthLarger(i, j, commandVector)){
					commandVector = switchPlace(i,j,commandVector);
				} else if(isStartMonthEqual(i, j, commandVector))
					if(isStartDayLarger(i, j, commandVector)){
						commandVector = switchPlace(i,j,commandVector);
					} else if(isStartDayEqual(i, j, commandVector))
						if(isStartTimeHourLarger(i, j, commandVector)){
							commandVector = switchPlace(i,j,commandVector);
						} else if(isStartTimeHourEqual(i, j, commandVector))
							if(isStartTimeMinLarger(i, j, commandVector)){
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
	return (commandVector[j].getTimeAndDate().getStartDay() > commandVector[i].getTimeAndDate().getStartDay());
}

bool storageSort::isStartDayEqual(int i, int j, std::vector<task> commandVector){
	return (commandVector[j].getTimeAndDate().getStartDay() == commandVector[i].getTimeAndDate().getStartDay());
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
