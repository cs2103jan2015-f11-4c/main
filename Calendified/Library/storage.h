//author @a0114411b

#pragma once
#pragma once
#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
#include <vector>

const std::string FILE_NAME = "storage.txt";

class storage
{
private:
	std::string _fileName;

public:
	storage(void);
	~storage(void);

	void createFile();
	std::vector<std::string> readFile();
	bool writeFile(std::vector<std::string> file);
	bool isFileExist();
};

#endif