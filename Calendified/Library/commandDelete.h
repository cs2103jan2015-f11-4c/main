//@author A0114411B

#pragma once
#ifndef COMMANDDELETE_H
#define COMMANDDELETE_H

const std::string MESSAGE_SUCCESS_DELETED =
	"%s is deleted!";

const std::string MESSAGE_ERROR_FILE_IS_EMPTY =
	"Error: File is empty. There is nothing to delete.\n";

const std::string MESSAGE_ERROR_ITEM_NOT_FOUND =
	"Error: Item to be deleted not found";

class commandDelete
{
	
public:
	commandDelete(void);
	~commandDelete(void);
	
	void executeDelete(std::string stringToBeDeleted);
};

#endif
