//@author A0114411B

#include "commandDelete.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

commandDelete::commandDelete(void)
{
}

commandDelete::~commandDelete(void)
{
}

//******************************************************************
// This function executes the delete command by:
//
// Step 1: Extracting the data from storage and save it in a vector of strings
// Step 2: Check if the vector(containing the file's data) is empty
// Step 3: If empty -> print error message
// Step 4: Search through vector for the string to be deleted
// Step 5: If string not found, print error message
// Step 6: If found, update session with the string to be deleted
// Step 7: Delete string
// Step 8: Update storage with new information
// Step 9: Print Message Success
//
//******************************************************************


void commandDelete::executeDelete(std::string stringToBeDeleted){
	char buffer[999];
	std::vector<std::string> file;
	std::string data;
	std::ifstream extract(storageName); //insert storage location file name here

	while(getline(extract,data)){
		file.push_back(data);
	}
	extract.close();

	if(file.empty()){
		sprintf_s(buffer,MESSAGE_ERROR_FILE_IS_EMPTY.c_str());
	}
	else{
		int indexToBeDeleted;
		std::vector<std::string>::iterator iter;
		iter = find(file.begin(),file.end(),stringToBeDeleted);

		if(iter != file.end()){
			
			updateSession(stringToBeDeleted); //a new function?

			file.erase(iter);
			std::ofstream add(storageName); //insert storage location file name here
			for(int i=0; file.size()>0 ; i++){
				add << file[i] << '\n';
			}
			add.close();
			file.clear();
			sprintf_s(buffer,MESSAGE_SUCCESS_DELETED.c_str(), stringToBeDeleted);
		}
		else{
			sprintf_s(buffer,MESSAGE_ERROR_ITEM_NOT_FOUND.c_str());
		}
	}
}