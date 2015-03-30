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

	//std::vector<std::string>::iterator iter;
	//for(auto iter = file.begin(); iter != file.end(); ++iter){
	//for(auto i=0; i<file.size(); i++){
		//if(file[i].find_first_of(" ")){
			//break;
		//}
	//}

	sort(file.begin(),file.end(),compareStringsTime);
	sort(file.begin(),file.end(),compareStringsYear);
	sort(file.begin(),file.end(),compareStringsMonth);
	sort(file.begin(),file.end());

	return file;
}

bool compareStringsTime(std::string a, std::string b){
	return (a[12] < b[12]);
}

bool compareStringsYear(std::string a, std::string b){
	return (a[7] < b[7]);
}

bool compareStringsMonth(std::string a, std::string b){
	return (a[3] < b[3]);
}