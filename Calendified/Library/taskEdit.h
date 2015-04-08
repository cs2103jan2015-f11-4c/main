#pragma once
#ifndef TASKEDIT_H
#define TASKEDIT_H

#include <string>
#include <string>
#include <iostream>
#include <vector>
#include "storage.h"
#include "taskUndo.h"
#include "task.h"
#include <assert.h>

const std::string MESSAGE_SUCCESS_EDIT =
	"Edited!";

const std::string MESSAGE_ERROR_EDIT_FILE_IS_EMPTY =
	"Error: File is empty. There is nothing to edit.";

const std::string MESSAGE_ERROR_EDIT_ITEM_NOT_FOUND =
	"Error: Item to be edited not found";

class taskEdit
{
private:
	task _editingReference;
	
public:
	taskEdit(void);
	~taskEdit(void);

	void setEditingRef(task currentcommandRef);
	std::string executeEdit(int indexToBeEdited);
	void undoEdit(taskUndo* taskToBeUndone);
};

#endif