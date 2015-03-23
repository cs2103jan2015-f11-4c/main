#include "storageSort.h"
#include <algorithm>
#include <string>


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
