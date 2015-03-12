//author @a0114411b

#include "storage.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

storage::storage(void)
{
	_fileName = FILE_NAME;
}


storage::~storage(void)
{
}

/*void storage::createFile(){
std::ofstream writeFile(_fileName);
writeFile << "Calendified Database.";
writeFile.close();
}
*/

// This function is to check if the user is a new user
// If the user is a new user, the function returns false
// Hence creating a new file to store the user's calendar
bool storage::isFileExist(){

	std::ifstream extract(_fileName);
	if(extract.good()){
		extract.close();
		return true;
	}
	else {
		extract.close();
		return false;
	}

	/*
	std::vector<std::string> file;
	std::string data;
	std::ifstream extract(_fileName);
	while(getline(extract,data)){
	file.push_back(data);
	}
	extract.close();

	if(file.empty()){
	return false;
	}
	else{
	return true;
	}
	*/
}

std::vector<std::string> storage::readFile(){
	std::string data;
	std::vector<std::string> file;
	std::ifstream extract(_fileName);
	while(!extract.eof()){
		getline(extract,data);
		file.push_back(data);
	}
	extract.close();

	if(file[0] == ""){
		clearFile();
		file.clear();
	}
	return file;
}

bool storage::writeFile(std::vector<std::string> file){
	std::ofstream add(_fileName);
	int i;
	if(file.size() == 0){
		clearFile();
		add.close();
		return true;
	}
	else{
		for(i=0; i<(file.size()-1); i++){
			add << file[i] << '\n';
		}
		add << file[i];
		add.close();
		file.clear();
		return true;
	}
}

std::string storage::searchFile(std::string stringToBeSearched){
	std::vector<std::string> file;
	std::string stringInsideFile;
	std::ostringstream oss;
	file = readFile();
	if(file.empty()){
		clearFile();
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
	std::ofstream add(_fileName);
	add.close();
}

std::string storage::successMessageClear(){
	return MESSAGE_FILE_CLEAR;
}