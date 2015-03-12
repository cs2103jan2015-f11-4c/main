//@author A0114411B
#include <string>
#include <string>
#include <iostream>
#include <vector>
#include "storage.h"

#pragma once
#ifndef TASKDELETE_H
#define TASKDELETE_H

const std::string MESSAGE_SUCCESS_DELETED =
	"Deleted!";

const std::string MESSAGE_ERROR_FILE_IS_EMPTY =
	"Error: File is empty. There is nothing to delete.\n";

const std::string MESSAGE_ERROR_ITEM_NOT_FOUND =
	"Error: Item to be deleted not found";

class taskDelete
{
	
public:
	taskDelete(void);
	~taskDelete(void);
	
	std::string executeDelete(int indexToBeDeleted);
	
};

#endif