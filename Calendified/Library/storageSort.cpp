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
			if(commandVector[j].getTimeAndDate().getYear() > commandVector[i].getTimeAndDate().getYear()){
				commandVector = switchPlace(i,j,commandVector);
			} else if(commandVector[j].getTimeAndDate().getYear() == commandVector[i].getTimeAndDate().getYear())
				if(commandVector[j].getTimeAndDate().getMonth() > commandVector[i].getTimeAndDate().getMonth()){
					commandVector = switchPlace(i,j,commandVector);
				} else if(commandVector[j].getTimeAndDate().getMonth() == commandVector[i].getTimeAndDate().getMonth())
					if(commandVector[j].getTimeAndDate().getDay() > commandVector[i].getTimeAndDate().getDay()){
						commandVector = switchPlace(i,j,commandVector);
					} else if(commandVector[j].getTimeAndDate().getDay() == commandVector[i].getTimeAndDate().getDay())
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