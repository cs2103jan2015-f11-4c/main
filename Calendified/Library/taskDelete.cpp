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


std::string taskDelete::executeDelete(int indexToBeDeleted){
	char buffer[999];
	std::vector<task> file;

	storage newStorage;
	file = newStorage.readFileJson();


	if(isEmpty(file)){
		return MESSAGE_ERROR_FILE_IS_EMPTY;
	}
	else if(isNotValidIndex(indexToBeDeleted)){
		return MESSAGE_ERROR_INVALID_INDEX;
	}
	else{
		assert(indexToBeDeleted >= 0);
		try{
			file = performDeleteTask(file,indexToBeDeleted);
			newStorage.writeFileJson(file);
			file.clear();
			return MESSAGE_SUCCESS_DELETED;
		}catch (const std::exception& e){
			return MESSAGE_FAILURE_DELETE;
		}
	}
}

std::vector<task> taskDelete::performDeleteTask(std::vector<task> file, int indexToBeDeleted){
	file.erase(file.begin()+indexToBeDeleted);
	return file;
}

bool taskDelete::isEmpty(std::vector<task> file){
	return file.empty();
}

bool taskDelete::isNotValidIndex(int indexToBeDeleted){
	return (indexToBeDeleted < 0);
}

//@author A0116027R
void taskDelete::undoDelete(taskUndo* taskToBeUndone, std::string results){
	storage storageFile;

	if(results == MESSAGE_SUCCESS_DELETED){
		taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
		taskToBeUndone->insertVector(storageFile.readFileJson());
	}
}