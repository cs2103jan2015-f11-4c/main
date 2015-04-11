//@author A0114411B

#ifndef STORAGE_H
#define STORAGE_H
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filestream.h"
#include "rapidjson/filewritestream.h"
#include "storageSort.h"
#include "timeAndDate.h"
#include "task.h"

const std::string STORAGE_INFORMATION =
	"storageInformation.txt";

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

	
};

#endif