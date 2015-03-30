
#include "taskedit.h"

taskEdit::taskEdit(void){
}

taskEdit::~taskEdit(void){
}

std::string taskEdit::executeEdit(int indexToBeEdited){
	std::vector<std::string> file;
		storage newStorage;
	commandRef newCommandRef;
	
	if(newStorage.isFileExist()){
		
		file = newStorage.readFile("main");
		
		if(file.empty()){
			return MESSAGE_ERROR_EDIT_FILE_IS_EMPTY;
		}else if(indexToBeEdited > file.size()){
			return MESSAGE_ERROR_EDIT_ITEM_NOT_FOUND;
		}else{
			std::string taskDataString;
			taskDataString = file[indexToBeEdited-1];
		    newCommandRef = editCommandRef(taskDataString);
		    
			taskDataString = newCommandRef.dataToString();
			file[indexToBeEdited-1] = taskDataString;
			if(newStorage.writeFile(file,"main")){
				return "Edited.";
			}else{
				return "Not edited successfully.";
			}
	}

	}else{
		return "File does not exit.";
	}
	

	
	

}
commandRef taskEdit::editCommandRef(std::string taskDataString){

	commandRef oldTaskData;
	oldTaskData = getEditingTaskData(taskDataString).copyTo();	
	oldTaskData = editingRef.compareAndSetTaskData(oldTaskData);
	
	return oldTaskData;
}

commandRef taskEdit::getEditingTaskData(std::string taskDataString){

	commandRef oldTaskData;
	oldTaskData.stringTodata(taskDataString);
	return oldTaskData;
}

void taskEdit::setEditingRef(commandRef currentCommandRef){
	
	editingRef = currentCommandRef.copyTo();

}

