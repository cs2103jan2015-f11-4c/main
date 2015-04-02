//author @a0114411b
//
//***************************************************************
//              Storage.cpp										*
//																*			
// Description :												*
// Storage class governs the creating and storing of the		*
// folder of user's choice. It allows the reading and writing	*
// of the storage text file. It will create a text file			*
// if there is no storage to begin with. It also provide		* 
// functions such as clear and search.							*
//																*
//***************************************************************
//
#include "storage.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/filestream.h"
#include "rapidjson/filewritestream.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>


using namespace rapidjson;

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
	std::ifstream extract(filename);
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

bool storage::isFileEmpty(){
	std::string data;
	std::ifstream extract(_filePath);
	getline(extract,data);
	extract.close();

	if(data == ""){
		return true;
	} else{ 
		return false;
	}

}

bool storage::writeFile(std::vector<std::string> file, std::string fileType){
	storageSort storageSort;
	int i=0;
	std::string fileName = "";
	if(fileType.compare("main") == 0){
		fileName = _filePath;
	}
	else if(fileType.compare("float") == 0){
		fileName = FILE_NAME_FLOATING;
	}
	std::ofstream add(fileName);
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


std::vector<task> storage::readFileJson(){
	FILE* in = NULL;
	in = fopen(_filePath.c_str(), "r");
	char buffer[65536];
	FileReadStream iss(in,buffer,sizeof(buffer));

	Document document;
	document.ParseStream(iss);
	assert(document != NULL);
	fclose(in);
	std::vector<task> commandVector;
	commandVector.clear();
	
		const Value& array = document["storage"];

		for(SizeType i=0; i<array.Size(); i++){
			const Value& TaskObject = array[i];
			std::string TaskType = TaskObject["TaskType"].GetString();

			if(TaskType == "TimedTask"){
				task newTask;
				//standard
				newTask.setTaskType(TaskObject["TaskType"].GetString());
				newTask.setTitle(TaskObject["TaskTitle"].GetString());
				newTask.setLocation(TaskObject["Location"].GetString());	
				newTask.setCommandAction(TaskObject["CommandAction"].GetString());
				newTask.setIsDone(TaskObject["IsDone"].GetBool());

				//Date
				timeAndDate newTimeAndDate;
				newTimeAndDate.setMDay(TaskObject["Day"].GetInt());
				newTimeAndDate.setMonth(TaskObject["Month"].GetInt());
				newTimeAndDate.setYear(TaskObject["Year"].GetInt());

				//Time
				newTimeAndDate.setStartTimeHour(TaskObject["StartHour"].GetInt());
				newTimeAndDate.setStartTimeMin(TaskObject["StartMin"].GetInt());
				newTimeAndDate.setEndTimeHour(TaskObject["EndHour"].GetInt());
				newTimeAndDate.setEndTimeMin(TaskObject["EndMin"].GetInt());

				newTask.setTimeAndDate(newTimeAndDate);
				commandVector.push_back(newTask);
			}


			else if(TaskType == "FloatingTask"){
				task newTask;
				//standard
				newTask.setTaskType(TaskObject["TaskType"].GetString());
				newTask.setTitle(TaskObject["TaskTitle"].GetString());
				newTask.setLocation(TaskObject["TaskLocation"].GetString());	
				newTask.setCommandAction(TaskObject["CommandAction"].GetString());
				newTask.setIsDone(TaskObject["IsDone"].GetBool());
				commandVector.push_back(newTask);
			}

			else if(TaskType == "DeadLine"){
				task newTask;
				//standard
				newTask.setTaskType(TaskObject["TaskType"].GetString());
				newTask.setTitle(TaskObject["TaskTitle"].GetString());
				newTask.setLocation(TaskObject["TaskLocation"].GetString());	
				newTask.setCommandAction(TaskObject["CommandAction"].GetString());
				newTask.setIsDone(TaskObject["IsDone"].GetBool());

				//Date
				timeAndDate newTimeAndDate;
				newTimeAndDate.setMDay(TaskObject["Day"].GetInt());
				newTimeAndDate.setMonth(TaskObject["Month"].GetInt());
				newTimeAndDate.setYear(TaskObject["Year"].GetInt());

				//Time
				newTimeAndDate.setStartTimeHour(TaskObject["StartHour"].GetInt());
				newTimeAndDate.setStartTimeMin(TaskObject["StartMin"].GetInt());
				newTimeAndDate.setEndTimeHour(TaskObject["EndHour"].GetInt());
				newTimeAndDate.setEndTimeMin(TaskObject["EndMin"].GetInt());

				newTask.setTimeAndDate(newTimeAndDate);
				commandVector.push_back(newTask);
			}
		}//for loop close
		return commandVector;
}

void storage::writeFileJson(std::vector<task> commandVector){

	storageSort sort;
	commandVector = sort.sortvector(commandVector);

	Document document;
	document.SetObject();
	Value array(kArrayType);

	for(auto i=0; i<commandVector.size(); i++){
		Value obj(kObjectType);
		obj.SetObject();

		if(commandVector[i].getTaskType().compare("TimedTask") == 0 ){
			//Standard
			obj.AddMember("TaskType","TimedTask",document.GetAllocator());

			char title[10000];
			sprintf(title, "%s", commandVector[i].getTitle().c_str());
			Value TaskTitle(kStringType);
			TaskTitle.SetString(title,strlen(title),document.GetAllocator());
			obj.AddMember("TaskTitle",TaskTitle,document.GetAllocator());


			//Converting Location
			char location[99999];
			sprintf(location, "%s", commandVector[i].getLocation().c_str(),document.GetAllocator());
			Value Location(kStringType);
			Location.SetString(location, strlen(location), document.GetAllocator());
			obj.AddMember("Location", Location, document.GetAllocator());

			//Converting CommandAction
			char action[99999];
			sprintf(action, "%s", commandVector[i].getCommandAction().c_str(),document.GetAllocator());
			Value CommandAction(kStringType);
			CommandAction.SetString(action,strlen(action),document.GetAllocator());
			obj.AddMember("CommandAction", CommandAction, document.GetAllocator());
			obj.AddMember("IsDone",commandVector[i].getIsDone(),document.GetAllocator());
			
			//Date
			obj.AddMember("Day", commandVector[i].getTimeAndDate().getMDay(),document.GetAllocator());
			obj.AddMember("Month", commandVector[i].getTimeAndDate().getMonth(),document.GetAllocator());
			obj.AddMember("Year", commandVector[i].getTimeAndDate().getYear(),document.GetAllocator());

			//Time
			obj.AddMember("StartHour", commandVector[i].getTimeAndDate().getStartTimeHour(),document.GetAllocator());
			obj.AddMember("StartMin", commandVector[i].getTimeAndDate().getStartTimeMin(),document.GetAllocator());
			obj.AddMember("EndHour", commandVector[i].getTimeAndDate().getEndTimeHour(),document.GetAllocator());
			obj.AddMember("EndMin", commandVector[i].getTimeAndDate().getEndTimeMin(),document.GetAllocator());
				
		}
		else if(commandVector[i].getTaskType().compare("FloatingTask") == 0){
			//Standard
			char buffer[10000];
			obj.AddMember("TaskType","FloatingTask",document.GetAllocator());
			sprintf(buffer, "%s", commandVector[i].getTitle().c_str());
			Value TaskTitle(kStringType);
			TaskTitle.SetString(buffer,strlen(buffer),document.GetAllocator());
			obj.AddMember("TaskTitle",TaskTitle,document.GetAllocator());


			//Converting Location
			sprintf(buffer, "%s", commandVector[i].getLocation().c_str(),document.GetAllocator());
			Value Location(kStringType);
			Location.SetString(buffer, strlen(buffer), document.GetAllocator());
			obj.AddMember("Location", Location, document.GetAllocator());

			//Converting CommandAction
			sprintf(buffer, "%s", commandVector[i].getCommandAction().c_str(),document.GetAllocator());
			Value CommandAction(kStringType);
			CommandAction.SetString(buffer,strlen(buffer),document.GetAllocator());
			obj.AddMember("CommandAction", CommandAction, document.GetAllocator());
			obj.AddMember("IsDone", commandVector[i].getIsDone(),document.GetAllocator());
		}

		else if(commandVector[i].getTaskType().compare("DeadLine") == 0){
			//Converting Title
			char buffer[99999];
			obj.AddMember("TaskType", "DeadLine", document.GetAllocator());
			sprintf(buffer, "%s", commandVector[i].getTitle().c_str());
			Value TaskTitle(kStringType);
			TaskTitle.SetString(buffer, strlen(buffer), document.GetAllocator());
			obj.AddMember("TaskTitle", TaskTitle, document.GetAllocator());

			obj.AddMember("IsDone", commandVector[i].getIsDone(), document.GetAllocator());

			//Converting Location
			sprintf(buffer, "%s", commandVector[i].getLocation().c_str(),document.GetAllocator());
			Value Location(kStringType);
			Location.SetString(buffer, strlen(buffer), document.GetAllocator());
			obj.AddMember("Location", Location, document.GetAllocator());

			//Converting CommandAction
			sprintf(buffer, "%s", commandVector[i].getCommandAction().c_str(),document.GetAllocator());
			Value CommandAction(kStringType);
			CommandAction.SetString(buffer,strlen(buffer),document.GetAllocator());
			obj.AddMember("CommandAction", CommandAction, document.GetAllocator());



			//Date
			obj.AddMember("Day", commandVector[i].getTimeAndDate().getMDay(),document.GetAllocator());
			obj.AddMember("Month", commandVector[i].getTimeAndDate().getMonth(),document.GetAllocator());
			obj.AddMember("Year", commandVector[i].getTimeAndDate().getYear(),document.GetAllocator());

			//Time
			obj.AddMember("StartHour", commandVector[i].getTimeAndDate().getStartTimeHour(),document.GetAllocator());
			obj.AddMember("StartMin", commandVector[i].getTimeAndDate().getStartTimeMin(),document.GetAllocator());
			obj.AddMember("EndHour", commandVector[i].getTimeAndDate().getEndTimeHour(),document.GetAllocator());
			obj.AddMember("EndMin", commandVector[i].getTimeAndDate().getEndTimeMin(),document.GetAllocator());
		}

		array.PushBack(obj,document.GetAllocator());
	}
	document.AddMember("storage", array, document.GetAllocator());

	FILE* out = fopen(_filePath.c_str(), "w");
	char buffer[65536];
	FileWriteStream oss(out, buffer, sizeof(buffer));
	PrettyWriter<FileWriteStream> out_writer(oss);
	document.Accept(out_writer);
	fclose(out);
}
