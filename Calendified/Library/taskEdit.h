//@author A0116027R

#ifndef TASKEDIT_H
#define TASKEDIT_H
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "storage.h"
#include "taskUndo.h"
#include "task.h"

const std::string MESSAGE_ERROR_EDIT_FILE_IS_EMPTY =
	"Error: File is empty.";

const std::string MESSAGE_ERROR_EDIT_ITEM_NOT_FOUND =
	"Error: Invalid index.";

const std::string MESSAGE_SUCCESS_EDIT =
	"Edited!";

const std::string MESSAGE_FAILURE_EDIT =
	"Fail to edit.";

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