#include <string>
#include <string>
#include <iostream>
#include <vector>
#include "storage.h"
#include "taskDelete.h"
#include "taskAdd.h"
#include "taskRef.h"


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
	taskRef editingRef;
	
public:
	taskEdit(void);
	~taskEdit(void);
	
	std::string executeEdit(int indexToBeEdited);
	taskRef editTaskRef(std::string taskDataString);
	taskRef getEditingTaskData(std::string taskDataString);
	void setEditingRef(taskRef currentTaskRef);
	
};

#endif