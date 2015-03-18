//author @a0114411b

#pragma once
#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
#include <vector>

const std::string FILE_NAME_FLOATING 
	= "floatingTask.txt";
const std::string MESSAGE_FILE_EMPTY =
	"File is empty!";
const std::string MESSAGE_FILE_CLEAR =
	"File cleared!";

class storage
{
private:
	std::string _filePath;

public:
	storage(void);
	~storage(void);

	void saveInformation(std::string filename);
	std::string retrieveFilePath();
	void createFile(std::string fileName);
	std::vector<std::string> readFile(std::string fileType);
	bool writeFile(std::vector<std::string> file, std::string fileType);
	bool isFileExist();
	std::string searchFile(std::string stringToBeSearched, std::string fileType);
	void clearFile();
	std::string successMessageClear();
};

#endif