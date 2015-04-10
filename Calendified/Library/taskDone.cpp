//@author A0114411B

#include "taskDone.h"


taskDone::taskDone(void)
{
}


taskDone::~taskDone(void)
{
}


std::string taskDone::markDone(int indexToBeActOn){
	LOG(INFO) << "Entered class: taskDone. Function: markDone";
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
	LOG(INFO) << "Entered class: taskDone. Function: markUndone";
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
	LOG(INFO) << "Entered class: taskDone. Function: getListDone";
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
	LOG(INFO) << "Entered class: taskDone. Function: getListUndone";
	std::vector<task> undoneVector;
	storage newStorage;
	undoneVector = newStorage.readFileJson();

	if(undoneVector.empty()){
		return undoneVector;
	} else {
		int i;
		for(i=1; i<=undoneVector.size();i++){
			if(undoneVector[i-1].getIsDone() == true){
				undoneVector.erase(undoneVector.begin()+i-1);
			}
		}
		if(undoneVector.empty()){
			return undoneVector;
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