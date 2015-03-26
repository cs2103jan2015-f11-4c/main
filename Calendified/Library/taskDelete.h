//@author A0114411B
#pragma once
#ifndef TASKDELETE_H
#define TASKDELETE_H
#include <string>
#include <string>
#include <iostream>
#include <vector>
#include "storage.h"


const std::string MESSAGE_SUCCESS_DELETED =
	"Deleted!";

const std::string MESSAGE_ERROR_FILE_IS_EMPTY =
	"Error: File is empty. There is nothing to delete.\n";

const std::string MESSAGE_ERROR_INVALID_INDEX =
	"Error: Invalid index.";

class taskDelete
{
	
public:
	taskDelete(void);
	~taskDelete(void);
	
	std::string executeDelete(int indexToBeDeleted);
	
};

#endif