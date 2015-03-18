//author @a0114411b

#include "storage.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

storage::storage(void)
{
	_filePath = storage::retrieveFilePath();
}


storage::~storage(void)
{
}

void storage::saveInformation(std::string filename){
	std::ofstream writeFile("storageInformation.txt");
	writeFile << filename;
	writeFile.close();
}

std::string storage::retrieveFilePath(){
	std::ifstream retrieve("storageInformation.txt");
	std::string directory;
	getline(retrieve,directory);
	return directory;
}

void storage::createFile(std::string fileName){
	std::ofstream writeFile(fileName);
	writeFile.close();
}

// This function is to check if the user is a new user
// If the user is a new user, the function returns false
// Hence creating a new file to store the user's calendar
bool storage::isFileExist(){

	if(retrieveFilePath() == "")
	{
		return false;
	}
	else {
		return true;
	}

	/*if(extract.good()){
	extract.close();
	return true;
	}
	else {
	extract.close();
	return false;
	}*/
}

std::vector<std::string> storage::readFile(std::string fileType){
	std::string data;
	std::string filename;
	std::vector<std::string> file;
	if(fileType.compare("main") == 0){
		filename = _filePath;
	}
	else if(fileType.compare("float") == 0) {
		filename = FILE_NAME_FLOATING;
	}
	std::ifstream extract(_filePath);
	while(!extract.eof()){
		getline(extract,data);
		if(data == "") {
			return file;
		}
		file.push_back(data);
	}
	extract.close();

	if(file[0] == ""){
		clearFile();
		file.clear();
	}
	return file;
}

bool storage::writeFile(std::vector<std::string> file, std::string fileType){
	std::string fileName = "";
	if(fileType.compare("main") == 0){
		fileName = _filePath;
	}
	else if(fileType.compare("float") == 0){
		fileName = FILE_NAME_FLOATING;
	}
	std::ofstream add(fileName);
	int i;
	if(file.size() == 0){
		clearFile();
		add.close();
		return true;
	}
	else{
		if(file.size() == 1){
			add << file[0];
		}
		else{
			for(i=0; i<(file.size()-1); i++){
				add << file[i] << '\n';
			}
			add << file[i];
		}
		add.close();
		file.clear();
		return true;
	}
}

std::string storage::searchFile(std::string stringToBeSearched, std::string fileType){
	std::vector<std::string> file;
	std::string stringInsideFile;
	std::ostringstream oss;
	file = readFile(fileType);
	if(file.empty()){
		return MESSAGE_FILE_EMPTY;
	}else{
		for(int i=0; i<file.size() ; i++){
			stringInsideFile = file[i];
			if(stringInsideFile.find(stringToBeSearched) != stringInsideFile.npos){
				oss << i+1 << ". " << stringInsideFile << std::endl;
			}
		}
		return oss.str();
	}
}

void storage::clearFile(){
	std::ofstream out1(_filePath);
	out1.close();
	std::ofstream out2(FILE_NAME_FLOATING);
	out2.close();
}

std::string storage::successMessageClear(){
	return MESSAGE_FILE_CLEAR;
}