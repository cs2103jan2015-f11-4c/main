#include "taskEdit.h"

taskEdit::taskEdit(void){
}

taskEdit::~taskEdit(void){
}

std::string taskEdit::executeEdit(int indexToBeEdited){
	std::vector<task> file;
		storage newStorage;
	//commandRef newCommandRef;

	if(newStorage.isFileExist()){
		
		file = newStorage.readFileJson();
		
		if(file.empty()){
			return MESSAGE_ERROR_EDIT_FILE_IS_EMPTY;
		}else if(indexToBeEdited > file.size()){
			return MESSAGE_ERROR_EDIT_ITEM_NOT_FOUND;
		}else{
			task changingTaskData;
			//std::string taskDataString;
			//changingTaskData = file[indexToBeEdited-1];
			int totalFileSize = file.size();
			int timedTasksSize = 0;
			int floatTaskSize = 0;

			for(int i=0; i<file.size(); i++){
				if(file[i].getTaskType() == "TimedTask"){
					++timedTasksSize;
				}
			}

			floatTaskSize = totalFileSize - timedTasksSize;

			if(indexToBeEdited>=timedTasksSize){ //floating task
				indexToBeEdited = indexToBeEdited - timedTasksSize -1;
				changingTaskData = file[indexToBeEdited];
			} else if(indexToBeEdited<timedTasksSize){ //timed task
				indexToBeEdited = indexToBeEdited + floatTaskSize - 1;
				changingTaskData = file[indexToBeEdited];
			}
				
			if((!editingRef.getCommandAction().empty()) && editingRef.getCommandAction() != changingTaskData.getCommandAction()){
				changingTaskData.setCommandAction(editingRef.getCommandAction());
			}
			if((!editingRef.getIsDone()) && editingRef.getIsDone() != changingTaskData.getIsDone()){
				changingTaskData.setIsDone(editingRef.getIsDone());
			} 
			if((!editingRef.getLocation().empty()) && editingRef.getLocation() != changingTaskData.getLocation()){
				changingTaskData.setLocation(editingRef.getLocation());
			}
			if(editingRef.getTaskType() != changingTaskData.getTaskType()){ //depends on the thing
				changingTaskData.setTaskType(editingRef.getTaskType());
			}
			if((!editingRef.getTimeAndDate().dateAndTimeInString().empty()) && editingRef.getTimeAndDate().dateAndTimeInString() != changingTaskData.getTimeAndDate().dateAndTimeInString()){
				changingTaskData.setTimeAndDate(editingRef.getTimeAndDate());
			}
			if((!editingRef.getTitle().empty()) && editingRef.getTitle() != changingTaskData.getTitle()){
				changingTaskData.setTitle(editingRef.getTitle());
			}

			file[indexToBeEdited-1] = changingTaskData;
			try {
				newStorage.writeFileJson(file);
				return "Edited.";
			} catch (const std::exception& e){
				return "Not edited successfully.";
			}

			//taskDataString = file[indexToBeEdited-1];
		    //newCommandRef = editCommandRef(taskDataString);
			/*task newTaskRef = editCommandRef(taskData);

			taskDataString = newCommandRef.dataToString();
			file[indexToBeEdited-1] = taskDataString;
			if(newStorage.writeFile(file,"main")){
				return "Edited.";
			}else{
				return "Not edited successfully.";
			}
			*/
		}
	}else{
		return "File does not exit.";
	}
}
/*task taskEdit::editCommandRef(task taskDataString){

	commandRef oldTaskData;
	oldTaskData = getEditingTaskData(taskDataString).copyTo();	
	oldTaskData = editingRef.compareAndSetTaskData(oldTaskData);

	task oldTask;
	oldTask = getEditingTaskData();
	
	return oldTaskData;
}

task taskEdit::getEditingTaskData(task taskDataString){

	commandRef oldTaskData;
	oldTaskData.stringTodata(taskDataString);
	return oldTaskData;

	task oldTask;
	
}
*/

void taskEdit::setEditingRef(task currentCommandRef){
	
	editingRef = currentCommandRef;
	//return currentCommandRef.getIndexToBeActOn();

}

void taskEdit::undoEdit(taskUndo* taskToBeUndone){
	storage storageFile;
	taskToBeUndone->setSessionStack(taskToBeUndone->getCurrentStack());
	taskToBeUndone->insertVector(storageFile.readFileJson());
}