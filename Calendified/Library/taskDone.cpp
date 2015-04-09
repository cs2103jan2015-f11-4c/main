//@author A0114411B

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
			newTask.setIsDone(true);
			storageVector[indexToBeActOn] = newTask;
			newStorage.writeFileJson(storageVector);
			return MESSAGE_SUCCESS_DONE;

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
			newTask.setIsDone(false);
			storageVector[indexToBeActOn] = newTask;
			newStorage.writeFileJson(storageVector);
			return MESSAGE_SUCCESS_DONE;

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
		throw MESSAGE_ERROR_FILE_IS_EMPTY;
	} else {
		int i;
		for(i=0; i<doneVector.size();i++){
			if(doneVector[i].getIsDone() == false){
				doneVector.erase(doneVector.begin()+i);
			}
		}
		if(doneVector.empty()){
			throw MESSAGE_ERROR_NO_TASK_DONE;
		} else{
			assert(!doneVector.empty());
			return doneVector;
		}
	}
}

std::vector<task> taskDone::getListUndone(){
	std::vector<task> undoneVector;
	storage newStorage;
	undoneVector = newStorage.readFileJson();

	if(undoneVector.empty()){
		throw MESSAGE_ERROR_FILE_IS_EMPTY;
	} else {
		int i;
		for(i=0; i<undoneVector.size();i++){
			if(undoneVector[i].getIsDone() == true){
				undoneVector.erase(undoneVector.begin()+i);
			}
		}
		if(undoneVector.empty()){
			throw MESSAGE_ERROR_NO_TASK_UNDONE;
		} else{
			assert(!undoneVector.empty());
			return undoneVector;
		}
	}
}

void taskDone::undoDone(taskUndo* taskToBeUndone){
	storage storageFile;
	taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
	taskToBeUndone->insertVector(storageFile.readFileJson());
}

void taskDone::undoUndone(taskUndo* taskToBeUndone){
	storage storageFile;
	taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
	taskToBeUndone->insertVector(storageFile.readFileJson());
}