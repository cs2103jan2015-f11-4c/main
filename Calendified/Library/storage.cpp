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

bool storage::isFileExist(){

	std::vector<std::string> v1;
	std::string data;
	std::ifstream extract(_fileName);
	while(getline(extract,data)){
		v1.push_back(data);
	}
	extract.close();

	if(v1.empty()){
		return false;
	}
	else 
		return true;
}

std::vector<std::string> storage::readFile(){
	std::string data;
	std::vector<std::string> file;
	std::ifstream extract(_fileName);
	while(getline(extract,data)){
		file.push_back(data);
		extract.close();
	}
	return file;
}

bool storage::writeFile(std::vector<std::string> file){
	std::ofstream add(_fileName);
	int i=0;
	int size=file.size();
	while(size > 0){
		add << file[i] << std::endl;
		i++;
		size--;
	}
	add.close();
	file.clear();
	return true;
}