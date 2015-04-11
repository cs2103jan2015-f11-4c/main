//@author A0114411B

//
//*******************************************************************************
//                         Storage.cpp										
//																			
// Description :
// Storage uses addtional library such as RapidJson to store information of the user. 
// RapidJson allows the storing and retrieving of task objects in the text file. 
//
// Storage class is responsible for these actions:
// 1) Creating text file from a specific path passed in.
// 2) Setting and storing the current file path in a separate text file
//    in the UI folder represented by "storageInformation.txt".
// 3) Retrieving of the current file path from the storageInformation.txt
//    for reading and writing of the current text file.
// 4) Transferring of the text file from 1 location to another location,
//    by creating a new textfile, moving of data and removing the old
//    text file in the process. 
// 5) Checks for exisiting database whenever the user opens the application.
//
//*******************************************************************************
//
#include "storage.h"

using namespace rapidjson;

storage::storage(void)
{
	_filePath = storage::retrieveFilePath();
}

storage::~storage(void)
{
}

void storage::setFilePath(std::string filePath){
	_filePath = filePath;
}

void storage::saveInformation(std::string filename){
	std::ofstream writeFile(STORAGE_INFORMATION);
	writeFile << filename;
	writeFile.close();
}

std::string storage::retrieveFilePath(){
	std::ifstream retrieve(STORAGE_INFORMATION);
	std::string directory;
	getline(retrieve,directory);
	return directory;
}

void storage::createFile(std::string fileName){
	std::ofstream writeFile(fileName);
	writeFile.close();
}

void storage::transferDatabase(std::string newFileName){
	std::vector<task> oldFiles;
	std::vector<task> blankVector;
	std::string oldFileName = _filePath;

	createFile(newFileName);
	oldFiles = readFileJson();
	saveInformation(newFileName);
	_filePath = retrieveFilePath();
	writeFileJson(blankVector);
	writeFileJson(oldFiles);
	remove(oldFileName.c_str());
}

bool storage::isFileExist(){

	if(retrieveFilePath() == ""){
		return false;
	} else {
		return true;
	}
}

bool storage::isFileEmpty(){
	std::string data;
	std::ifstream extract(_filePath);
	getline(extract,data);
	extract.close();

	if(data == ""){
		return true;
	} else { 
		return false;
	}
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
			newTask.setIsClash(TaskObject["IsClash"].GetBool());

			//Date
			timeAndDate newTimeAndDate;
			newTimeAndDate.setStartMDay(TaskObject["StartDay"].GetInt());
			newTimeAndDate.setStartMonth(TaskObject["StartMonth"].GetInt());
			newTimeAndDate.setStartYear(TaskObject["StartYear"].GetInt());
			newTimeAndDate.setEndMDay(TaskObject["EndDay"].GetInt());
			newTimeAndDate.setEndMonth(TaskObject["EndMonth"].GetInt());
			newTimeAndDate.setEndYear(TaskObject["EndYear"].GetInt());

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
			newTask.setLocation(TaskObject["Location"].GetString());	
			newTask.setCommandAction(TaskObject["CommandAction"].GetString());
			newTask.setIsDone(TaskObject["IsDone"].GetBool());
			newTask.setIsClash(TaskObject["IsClash"].GetBool());

			//Date
			timeAndDate newTimeAndDate;
			newTimeAndDate.setStartMDay(TaskObject["StartDay"].GetInt());
			newTimeAndDate.setStartMonth(TaskObject["StartMonth"].GetInt());
			newTimeAndDate.setStartYear(TaskObject["StartYear"].GetInt());
			newTimeAndDate.setEndMDay(TaskObject["EndDay"].GetInt());
			newTimeAndDate.setEndMonth(TaskObject["EndMonth"].GetInt());
			newTimeAndDate.setEndYear(TaskObject["EndYear"].GetInt());

			newTask.setTimeAndDate(newTimeAndDate);
			commandVector.push_back(newTask);
		}

		else if(TaskType == "DeadLine"){
			task newTask;
			//standard
			newTask.setTaskType(TaskObject["TaskType"].GetString());
			newTask.setTitle(TaskObject["TaskTitle"].GetString());
			newTask.setLocation(TaskObject["Location"].GetString());	
			newTask.setCommandAction(TaskObject["CommandAction"].GetString());
			newTask.setIsDone(TaskObject["IsDone"].GetBool());
			newTask.setIsClash(TaskObject["IsClash"].GetBool());

			//Date
			timeAndDate newTimeAndDate;
			newTimeAndDate.setStartMDay(TaskObject["StartDay"].GetInt());
			newTimeAndDate.setStartMonth(TaskObject["StartMonth"].GetInt());
			newTimeAndDate.setStartYear(TaskObject["StartYear"].GetInt());
			newTimeAndDate.setEndMDay(TaskObject["EndDay"].GetInt());
			newTimeAndDate.setEndMonth(TaskObject["EndMonth"].GetInt());
			newTimeAndDate.setEndYear(TaskObject["EndYear"].GetInt());

			//Time
			newTimeAndDate.setStartTimeHour(TaskObject["StartHour"].GetInt());
			newTimeAndDate.setStartTimeMin(TaskObject["StartMin"].GetInt());
			newTimeAndDate.setEndTimeHour(TaskObject["EndHour"].GetInt());
			newTimeAndDate.setEndTimeMin(TaskObject["EndMin"].GetInt());

			newTask.setTimeAndDate(newTimeAndDate);
			commandVector.push_back(newTask);
		}
	}
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
			obj.AddMember("IsClash",commandVector[i].getIsClash(),document.GetAllocator());

			//Date
			obj.AddMember("StartDay", commandVector[i].getTimeAndDate().getStartMDay(),document.GetAllocator());
			obj.AddMember("StartMonth", commandVector[i].getTimeAndDate().getStartMonth(),document.GetAllocator());
			obj.AddMember("StartYear", commandVector[i].getTimeAndDate().getStartYear(),document.GetAllocator());
			obj.AddMember("EndDay", commandVector[i].getTimeAndDate().getEndMDay(),document.GetAllocator());
			obj.AddMember("EndMonth", commandVector[i].getTimeAndDate().getEndMonth(),document.GetAllocator());
			obj.AddMember("EndYear", commandVector[i].getTimeAndDate().getEndYear(),document.GetAllocator());

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
			obj.AddMember("IsClash",commandVector[i].getIsClash(),document.GetAllocator());

			//Date
			obj.AddMember("StartDay", commandVector[i].getTimeAndDate().getStartMDay(),document.GetAllocator());
			obj.AddMember("StartMonth", commandVector[i].getTimeAndDate().getStartMonth(),document.GetAllocator());
			obj.AddMember("StartYear", commandVector[i].getTimeAndDate().getStartYear(),document.GetAllocator());
			obj.AddMember("EndDay", commandVector[i].getTimeAndDate().getEndMDay(),document.GetAllocator());
			obj.AddMember("EndMonth", commandVector[i].getTimeAndDate().getEndMonth(),document.GetAllocator());
			obj.AddMember("EndYear", commandVector[i].getTimeAndDate().getEndYear(),document.GetAllocator());
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
			obj.AddMember("IsClash",commandVector[i].getIsClash(),document.GetAllocator());

			//Date
			obj.AddMember("StartDay", commandVector[i].getTimeAndDate().getStartMDay(),document.GetAllocator());
			obj.AddMember("StartMonth", commandVector[i].getTimeAndDate().getStartMonth(),document.GetAllocator());
			obj.AddMember("StartYear", commandVector[i].getTimeAndDate().getStartYear(),document.GetAllocator());
			obj.AddMember("EndDay", commandVector[i].getTimeAndDate().getEndMDay(),document.GetAllocator());
			obj.AddMember("EndMonth", commandVector[i].getTimeAndDate().getEndMonth(),document.GetAllocator());
			obj.AddMember("EndYear", commandVector[i].getTimeAndDate().getEndYear(),document.GetAllocator());

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