//@author A0114411B
#include "storageSort.h"
#include <algorithm>
#include <string>

const int INDEX_TIME = 11;
const int INDEX_YEAR = 6;
const int INDEX_MONTH = 2;

storageSort::storageSort(void)
{
}


storageSort::~storageSort(void)
{
}

std::vector<task> storageSort::sortvector(std::vector<task> commandVector){

	for(auto i=1; i<commandVector.size(); i++){
		for(auto j=0; j<i; j++){
			if(commandVector[j].getTimeAndDate().getStartYear() > commandVector[i].getTimeAndDate().getStartYear()){
				commandVector = switchPlace(i,j,commandVector);
			} else if(commandVector[j].getTimeAndDate().getStartYear() == commandVector[i].getTimeAndDate().getStartYear())
				if(commandVector[j].getTimeAndDate().getStartMonth() > commandVector[i].getTimeAndDate().getStartMonth()){
					commandVector = switchPlace(i,j,commandVector);
				} else if(commandVector[j].getTimeAndDate().getStartMonth() == commandVector[i].getTimeAndDate().getStartMonth())
					if(commandVector[j].getTimeAndDate().getStartDay() > commandVector[i].getTimeAndDate().getStartDay()){
						commandVector = switchPlace(i,j,commandVector);
					} else if(commandVector[j].getTimeAndDate().getStartDay() == commandVector[i].getTimeAndDate().getStartDay())
						if(commandVector[j].getTimeAndDate().getStartTimeHour() > commandVector[i].getTimeAndDate().getStartTimeHour()){
							commandVector = switchPlace(i,j,commandVector);
						} else if(commandVector[j].getTimeAndDate().getStartTimeHour() == commandVector[i].getTimeAndDate().getStartTimeHour())
							if(commandVector[j].getTimeAndDate().getStartTimeMin() > commandVector[i].getTimeAndDate().getStartTimeMin()){
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