
#include "taskedit.h"

taskEdit::taskEdit(void){
}

taskEdit::~taskEdit(void){
}

std::string taskEdit::executeEdit(int indexToBeEdited){
	std::vector<std::string> file;
		storage newStorage;
	taskRef newTaskRef;
	
	if(newStorage.isFileExist()){
		
		file = newStorage.readFile();
		
		if(file.empty()){
			return MESSAGE_ERROR_EDIT_FILE_IS_EMPTY;
		}else if(indexToBeEdited > file.size()){
			return MESSAGE_ERROR_EDIT_ITEM_NOT_FOUND;
		}else{
			std::string taskDataString;
			taskDataString = file[indexToBeEdited-1];
		    newTaskRef = editTaskRef(taskDataString);
		    
			taskDataString = newTaskRef.dataToString();
			file[indexToBeEdited-1] = taskDataString;
			if(newStorage.writeFile(file)){
				return "edited";
			}else{
				return "Not edited successfully";
			}
	}

	}else{
		return "File do not exits";
	}
	

	
	

}
taskRef taskEdit::editTaskRef(std::string taskDataString){

	taskRef oldTaskData;
	oldTaskData = getEditingTaskData(taskDataString).copyTo();	
	oldTaskData = editingRef.compareAndSetTaskData(oldTaskData);
	
	return oldTaskData;
}

taskRef taskEdit::getEditingTaskData(std::string taskDataString){

	taskRef oldTaskData;
	oldTaskData.stringTodata(taskDataString);
	return oldTaskData;
}

void taskEdit::setEditingRef(taskRef currentTaskRef){
	
	editingRef = currentTaskRef.copyTo();

}

