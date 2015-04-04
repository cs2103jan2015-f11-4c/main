#include <string>
#include <string>
#include <iostream>
#include <vector>
#include "storage.h"
#include "taskDelete.h"
#include "taskAdd.h"
#include "taskUndo.h"
#include "commandRef.h"
#include "task.h"


#pragma once
#ifndef TASKEDIT_H
#define TASKEDIT_H

const std::string MESSAGE_SUCCESS_EDIT =
	"Edited!";

const std::string MESSAGE_ERROR_EDIT_FILE_IS_EMPTY =
	"Error: File is empty. There is nothing to edit.\n";

const std::string MESSAGE_ERROR_EDIT_ITEM_NOT_FOUND =
	"Error: Item to be edited not found";

class taskEdit
{
private:
	task editingRef;
	
public:
	taskEdit(void);
	~taskEdit(void);
	
	std::string executeEdit(int indexToBeEdited);
	//commandRef editCommandRef(std::string taskDataString);
	//commandRef getEditingTaskData(std::string taskDataString);
	void setEditingRef(task currentcommandRef);
	void undoEdit(taskUndo* taskToBeUndone);
	
};

#endif