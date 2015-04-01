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


std::vector<commandRef> storageSort::sortVector(std::vector<commandRef> commandVector){


	return commandVector;
}