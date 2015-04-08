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
		return MESSAGE_ERROR_FILE_EMPTY;
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
		return MESSAGE_ERROR_FILE_EMPTY;
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
	std::vector<task> isDoneVector;
	storage newStorage;
	isDoneVector = newStorage.readFileJson();

	if(isDoneVector.empty()){
		throw MESSAGE_ERROR_FILE_EMPTY;
	} else {
		std::vector<task>::iterator iter;
		int i;
		for(iter=isDoneVector.begin(),i=0; iter<isDoneVector.end(); iter++,i++){
			if(isDoneVector[i].getIsDone() == false){
				isDoneVector.erase(iter);
			}
		}
		if(isDoneVector.empty()){
			throw MESSAGE_ERROR_NO_TASK_DONE;
		} else{
			assert(!isDoneVector.empty());
			return isDoneVector;
		}
	}
}

std::vector<task> taskDone::getListUndone(){
	std::vector<task> isUndoneVector;
	storage newStorage;
	isUndoneVector = newStorage.readFileJson();

	if(isUndoneVector.empty()){
		throw MESSAGE_ERROR_FILE_EMPTY;
	} else {
		std::vector<task>::iterator iter;
		int i;
		for(iter=isUndoneVector.begin(),i=0; iter<isUndoneVector.end(); iter++,i++){
			if(isUndoneVector[i].getIsDone() == false){
				isUndoneVector.erase(iter);
			}
		}
		if(isUndoneVector.empty()){
			throw MESSAGE_ERROR_NO_TASK_UNDONE;
		} else{
			assert(!isUndoneVector.empty());
			return isUndoneVector;
		}
	}
}
