//@author A0114411B

//******************************************************************
//
// This class governs the marking and unmarking of task
// being done or undone. It also provides functions such as 
// extracting the list of done or undone tasks.
//
//******************************************************************

#include "taskDone.h"


taskDone::taskDone(void)
{
}


taskDone::~taskDone(void)
{
}


std::string taskDone::markDone(int indexToBeActOn){
	std::vector<task> storageVector;
	storage newStorage;

	storageVector = newStorage.readFileJson();
	if(storageVector.empty()){
		return MESSAGE_ERROR_FILE_IS_EMPTY;
	}
	else if(indexToBeActOn < 0 || indexToBeActOn > storageVector.size()){
		return MESSAGE_ERROR_INVALID_INDEX;
	}
	else{
		assert(indexToBeActOn >= 0);
		assert(!storageVector.empty());
		try{
			task newTask;
			newTask = storageVector[indexToBeActOn];
			if(newTask.getIsDone() == true){
				return MESSAGE_ERROR_ALREADY_DONE;
			} else {
				newTask.setIsDone(true);
				storageVector[indexToBeActOn] = newTask;
				newStorage.writeFileJson(storageVector);
				return MESSAGE_SUCCESS_DONE;
			}

		} catch (const std::exception& e){
			throw(e.what());
		}
	}
}

std::string taskDone::markUndone(int indexToBeActOn){
	std::vector<task> storageVector;
	storage newStorage;

	storageVector = newStorage.readFileJson();
	if(storageVector.empty()){
		return MESSAGE_ERROR_FILE_IS_EMPTY;
	}
	else if(indexToBeActOn < 0 || indexToBeActOn > storageVector.size()){
		return MESSAGE_ERROR_INVALID_INDEX;
	}
	else{
		assert(indexToBeActOn >= 0);
		assert(!storageVector.empty());
		try{
			task newTask;
			newTask = storageVector[indexToBeActOn];
			if(newTask.getIsDone() == false){
				return MESSAGE_ERROR_ALREADY_UNDONE;
			} else {
				newTask.setIsDone(false);
				storageVector[indexToBeActOn] = newTask;
				newStorage.writeFileJson(storageVector);
				return MESSAGE_SUCCESS_UNDONE;
			}

		} catch (const std::exception& e){
			throw(e.what());
		}
	}
}

std::vector<task> taskDone::getListDone(){
	std::vector<task> doneVector;
	storage newStorage;
	doneVector = newStorage.readFileJson();

	if(doneVector.empty()){
		return doneVector;
	} else {
		int i;
		for(i=1; i<=doneVector.size(); i++){
			if(doneVector[i-1].getIsDone() == false){
				doneVector.erase(doneVector.begin()+i-1);
				i=0;
			}
		}
		if(doneVector.empty()){
			return doneVector;
		} else{
			assert(!doneVector.empty());
			return doneVector;
		}
	}
}

std::vector<task> taskDone::getListUndone(){
	std::vector<task> undoneVector;
	std::vector<task> newUndoneVector;
	storage newStorage;
	undoneVector = newStorage.readFileJson();

	if(undoneVector.empty()){
		return undoneVector;
	} else {
		int i;
		for(i=0; i<undoneVector.size();i++){
			if(undoneVector[i].getIsDone() == false){
				newUndoneVector.push_back(undoneVector[i]);
			}
		}
		if(newUndoneVector.empty()){
			return newUndoneVector;
		} else{
			assert(!newUndoneVector.empty());
			return newUndoneVector;
		}
	}
}

//@author A0116027R

void taskDone::undoDone(taskUndo* taskToBeUndone, std::string results){
	storage storageFile;
	
	if(results == MESSAGE_SUCCESS_DONE){
		taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
		taskToBeUndone->insertVector(storageFile.readFileJson());
	}
}

//@author A0116027R

void taskDone::undoUndone(taskUndo* taskToBeUndone, std::string results){
	storage storageFile;

	if(results == MESSAGE_SUCCESS_UNDONE){
		taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
		taskToBeUndone->insertVector(storageFile.readFileJson());
	}
}