//@author A0114411B

#include "taskDelete.h"
#include <assert.h>

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


// Add file type to parameter once the code is stable
std::string taskDelete::executeDelete(int indexToBeDeleted){
	char buffer[999];
	std::vector<task> file;

	storage newStorage;
	file = newStorage.readFileJson();


	if(file.empty()){
		return MESSAGE_ERROR_FILE_IS_EMPTY;
	}
	else if(indexToBeDeleted <= 0 || indexToBeDeleted > file.size() || indexToBeDeleted == NULL){
		return MESSAGE_ERROR_INVALID_INDEX;
	}
	else{
		assert(indexToBeDeleted > 0);
		assert(indexToBeDeleted != NULL);
		task taskToBeDeleted;
		taskToBeDeleted = file[indexToBeDeleted];
		try{
			file.erase(file.begin()+indexToBeDeleted);
			newStorage.writeFileJson(file);
			//updateSession(stringToBeDeleted); //a new function?
			file.clear();
			return MESSAGE_SUCCESS_DELETED;
		}catch (const std::exception& e){
			return MESSAGE_FAILURE;
		}
	}
}

void taskDelete::undoDelete(taskUndo* taskToBeUndone){
	storage storageFile;
	taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
	taskToBeUndone->insertVector(storageFile.readFileJson());
}
