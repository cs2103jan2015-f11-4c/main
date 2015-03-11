//@author A0114411B

#include "taskDelete.h"
#include "storage.h"
#include <string>
#include <iostream>
#include <vector>

taskDelete::taskDelete(void)
{
}

taskDelete::~taskDelete(void)
{
}

//******************************************************************
// This function executes the delete command by:
//
// Step 1: Extracting the data from storage and save it in a vector of strings
// Step 2: Check if the vector(containing the file's data) is empty
// Step 3: Check if the string to be deleted is inside the file
// Step 4: If found, update session with the string to be deleted
// Step 5: Delete string
// Step 6: Update storage with new information
// Step 7: Print Message Success
//
//******************************************************************


std::string taskDelete::executeDelete(int indexToBeDeleted){
	char buffer[999];
	std::vector<std::string> file;
	
	storage newStorage;
	file = newStorage.readFile();

	if(file.empty()){
		return MESSAGE_ERROR_FILE_IS_EMPTY;
	}
	else if(indexToBeDeleted > file.size()){
		return MESSAGE_ERROR_ITEM_NOT_FOUND;
	}
	else{
		std::string deleteString;
		deleteString = file[indexToBeDeleted-1];
		file.erase(file.begin()+indexToBeDeleted-1);
		if(newStorage.writeFile(file)){
			//updateSession(stringToBeDeleted); //a new function?
			file.clear();
			return MESSAGE_SUCCESS_DELETED;
		}
	}
}
