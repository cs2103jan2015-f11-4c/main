//@author A0114411B

#pragma once
#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
#include <vector>
#include "storageSort.h"
#include "task.h"
#include "timeAndDate.h"

const std::string MESSAGE_ERROR_FILE_IS_EMPTY =
	"Error: File is empty.";

const std::string MESSAGE_ERROR_INVALID_INDEX =
	"Error: Invalid index.";

class storage
{
private:
	std::string _filePath;

public:
	storage(void);
	~storage(void);
	
	void setFilePath(std::string filePath);
	void saveInformation(std::string filename);
	std::string retrieveFilePath();
	void createFile(std::string fileName);
	void transferDatabase(std::string newFileName);

	bool isFileExist();
	bool isFileEmpty();

	std::vector<task> readFileJson();
	void writeFileJson(std::vector<task> commandVector);
	//std::string searchFile(std::string stringToBeSearched);

	
};

#endif