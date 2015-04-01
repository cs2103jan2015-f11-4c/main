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

std::vector<std::string> storageSort::sortData(std::vector<std::string> file){

	sort(file.begin(),file.end());

	return file;
}


std::vector<task> storageSort::sortVector(std::vector<task> commandVector){

	for(auto i=1; i<commandVector.size(); i++){
		for(auto j=0; j<i; j++){
			if(commandVector[j].getTimeAndDate().getYear() > commandVector[i].getTimeAndDate().getYear()){
				commandVector = switchPlace(i,j,commandVector);
			} else if(commandVector[j].getTimeAndDate().getYear() == commandVector[i].getTimeAndDate().getYear()
				&& commandVector[j].getTimeAndDate().getMonth() > commandVector[i].getTimeAndDate().getMonth()){
					commandVector = switchPlace(i,j,commandVector);
			} else if(commandVector[j].getTimeAndDate().getMonth() == commandVector[i].getTimeAndDate().getMonth()
				&& commandVector[j].getTimeAndDate().getDay() > commandVector[i].getTimeAndDate().getDay()){
					commandVector = switchPlace(i,j,commandVector);
			} else if(commandVector[j].getTimeAndDate().getDay() == commandVector[i].getTimeAndDate().getDay()
				&& commandVector[j].getTimeAndDate().getStartTimeHour() > commandVector[i].getTimeAndDate().getStartTimeHour()){
					commandVector = switchPlace(i,j,commandVector);
			} else if(commandVector[j].getTimeAndDate().getStartTimeHour() == commandVector[i].getTimeAndDate().getStartTimeHour()
				&& commandVector[j].getTimeAndDate().getStartTimeMin() > commandVector[i].getTimeAndDate().getStartTimeMin()){
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