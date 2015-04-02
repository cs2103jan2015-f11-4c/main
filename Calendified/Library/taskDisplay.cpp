//@author A0125489U
#include "taskDisplay.h";


taskDisplay::taskDisplay(){
}

taskDisplay::taskDisplay(storage inputStorage){
	currentStorage = inputStorage;
}

taskDisplay::~taskDisplay(void)
{
	storage *storagePointer = &currentStorage;
	storagePointer = NULL;
}

//This operation sort the list of task w.r.t. to sort type [float|today|nextDay]
std::vector<task> taskDisplay::sortTaskList(std::string sortType){
	std::vector<task> taskList;
	std::string taskDateDay;
	std::string taskDateMonth;
	std::string taskDateYear;
	std::string taskDateTime;
	std::string dateDay; 
	std::string dateMonth; 
	std::string dateYear; 
	std::string dateTime ="0";
	std::vector<task> allTaskList = currentStorage.readFileJson();
	if(sortType.compare("float")==0){
		for(int i =0;i < allTaskList.size();i++){
			if(allTaskList[i].getTimeAndDate().getMDay() == 0 || 
				allTaskList[i].getTimeAndDate().getMonth() == 0 || 
				allTaskList[i].getTimeAndDate().getYear() == 0 || 
				allTaskList[i].getTimeAndDate().getStartTimeHour() == 0){
					taskList.push_back(allTaskList[i]);
			}
		}
		return taskList;
	} else if(sortType.compare("today")==0){
		dateDay = getTodayDate();
		dateMonth = getTodayDateMonth();
		dateYear = getTodayDateYear();
	} else if(sortType.compare("nextDay")==0){
		dateDay = getNextDayDate();
		dateMonth = getNextDayDateMonth();
		dateYear = getNextDayDateYear();
	}
	dateDay = dateDay.substr(0,2);
	if(dateDay[0] =='0'){
		dateDay = dateDay[1];
	}
	if(dateMonth[0] =='0'){
		dateMonth = dateMonth[1];
	}
	for(int i =0;i < allTaskList.size();i++){
		taskDateDay = std::to_string(allTaskList[i].getTimeAndDate().getMDay());
		taskDateMonth = std::to_string(allTaskList[i].getTimeAndDate().getMonth());
		taskDateYear = std::to_string(allTaskList[i].getTimeAndDate().getYear());
		taskDateTime = std::to_string(allTaskList[i].getTimeAndDate().getStartTimeHour());

		if(taskDateDay.compare(dateDay)==0 && 
			taskDateMonth.compare(dateMonth)==0 &&
			taskDateYear.compare(dateYear)==0 &&
			taskDateTime.compare(dateTime)!=0){
			taskList.push_back(allTaskList[i]);
		}
	}
	return taskList;
}
//
std::string taskDisplay::displayToday(){
	std::string displayTodayResults = getTodayDate()+"\n";
	std::vector<task> todayTaskList = sortTaskList("today");
	if(!todayTaskList.size()==0){
		displayTodayResults += formatDisplayResults(todayTaskList,"main");
	}
	return displayTodayResults;
}

//
std::string taskDisplay::displayNextDay(){
	std::string displayNextDayResults = getNextDayDate()+"\n";
	std::vector<task> nextDayTaskList = sortTaskList("nextDay");
	if(!nextDayTaskList.size()==0){
		displayNextDayResults += formatDisplayResults(nextDayTaskList,"main");
	}
	return displayNextDayResults;
}

//
std::string taskDisplay::displayFloatDay(){
	std::string displayFloatResults= "\n";
	std::vector<task> floatTaskList = sortTaskList("float");
	if(!floatTaskList.size()==0){
		displayFloatResults += formatDisplayResults(floatTaskList,"float");
	}
	return displayFloatResults;
}

//This operation formats the display results based on the paramter formatType - [main|float]
std::string taskDisplay::formatDisplayResults(std::vector<task> taskList, std::string formatType){
	std::string formatResults = "";
	if(formatType.compare("main")==0){
		for(int i =0; i< taskList.size();i++){
			formatResults += std::to_string(i+1)+". ";
			formatResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeHour())+":";
			formatResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+" ";
			formatResults += taskList[i].getTitle()+" ";
			formatResults += taskList[i].getLocation()+"\n";
		}
	} else if(formatType.compare("float")==0){
		for(int i =0; i< taskList.size();i++){
			formatResults += std::to_string(i+1)+". ";
			if(std::to_string(taskList[i].getTimeAndDate().getStartTimeHour()).compare("0")!=0){
				formatResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeHour())+":";
				formatResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+" ";
			}
			if(std::to_string(taskList[i].getTimeAndDate().getMDay()).compare("0")!=0){
				formatResults += std::to_string(taskList[i].getTimeAndDate().getMDay())+"/";
				formatResults += std::to_string(taskList[i].getTimeAndDate().getMonth())+"/";
				formatResults += std::to_string(taskList[i].getTimeAndDate().getYear())+" ";
			}
			formatResults += taskList[i].getTitle()+" ";
			formatResults += taskList[i].getLocation()+"\n";
		}
	}
	return formatResults;
}

//This operation returns current date- Day
std::string taskDisplay::getTodayDate(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%dth",timeinfo);
	return std::string(output);
}

//This operation returns current date- Month
std::string taskDisplay::getTodayDateMonth(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%m",timeinfo);
	return std::string(output);
}

//This operation returns current date- Year
std::string taskDisplay::getTodayDateYear(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%Y",timeinfo);
	return std::string(output);
}

//This operation returns current date- Day Month Year
std::string taskDisplay::getTodayDateDMY(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
	return std::string(output);
}

//This operation returns next date- Day
std::string taskDisplay::getNextDayDate(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%dth",timeinfo);
	return std::string(output);
}

//This operation returns next date- Month
std::string taskDisplay::getNextDayDateMonth(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%m",timeinfo);
	return std::string(output);
}

//This operation returns next date- Year
std::string taskDisplay::getNextDayDateYear(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%Y",timeinfo);
	return std::string(output);
}

//This operation returns next date- Day Month Year
std::string taskDisplay::getNextDayDateDMY(){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
	return std::string(output);
}

//This operation search the all existing data w.r.t. the search Item input
std::string taskDisplay::viewSearchList(std::string searchItem){
	std::vector<task> allTaskList = currentStorage.readFileJson();
	std::vector<task> searchList;
	int searchResultsIndex=0;
	std::string searchResults = "Results:\n";
	for(int i =0; i< allTaskList.size();i++){ //populate the the vector with revelant search results
		if(allTaskList[i].getTitle().find(searchItem) != std::string::npos || 
			allTaskList[i].getLocation().find(searchItem) != std::string::npos || 
			std::to_string(allTaskList[i].getTimeAndDate().getMDay()).find(searchItem) != std::string::npos || 
			std::to_string(allTaskList[i].getTimeAndDate().getMonth()).find(searchItem) != std::string::npos || 
			std::to_string(allTaskList[i].getTimeAndDate().getYear()).find(searchItem) != std::string::npos){
				searchList.push_back(allTaskList[i]);
			}
	}

	for(int i =0; i < searchList.size();i++){ //re-arrange and categorize [timed|float] tasks
		if(std::to_string(searchList[i].getTimeAndDate().getMDay()).compare("0") !=0 && 
			std::to_string(searchList[i].getTimeAndDate().getMonth()).compare("0") !=0 && 
			std::to_string(searchList[i].getTimeAndDate().getYear()).compare("0") !=0 &&
			std::to_string(allTaskList[i].getTimeAndDate().getStartTimeHour()).compare("0") !=0){
				searchResults += std::to_string(searchResultsIndex+1)+". ";
				searchResults += searchList[i].getTitle()+" ";
				searchResults += std::to_string(searchList[i].getTimeAndDate().getMDay())+"/";
				searchResults += std::to_string(searchList[i].getTimeAndDate().getMonth())+"/";
				searchResults += std::to_string(searchList[i].getTimeAndDate().getYear())+" ";
				searchResults += std::to_string(searchList[i].getTimeAndDate().getStartTimeHour())+":";
				searchResults += std::to_string(searchList[i].getTimeAndDate().getStartTimeMin())+" ";
				searchResults += searchList[i].getLocation()+"\n";
				searchResultsIndex++;
		}
	}
	searchResults += "\nFLOAT\n";
	for(int i =0; i < searchList.size();i++){ //re-arrange and categorize [timed|float] tasks
		if(std::to_string(searchList[i].getTimeAndDate().getMDay()).compare("0") == 0 || 
				std::to_string(searchList[i].getTimeAndDate().getMonth()).compare("0") == 0 || 
				std::to_string(searchList[i].getTimeAndDate().getYear()).compare("0") == 0 || 
				std::to_string(searchList[i].getTimeAndDate().getStartTimeHour()).compare("0") == 0){
					searchResults += std::to_string(searchResultsIndex+1)+". ";
					searchResults += searchList[i].getTitle()+" ";
					if(std::to_string(searchList[i].getTimeAndDate().getStartTimeHour()).compare("0")!=0){
						searchResults += std::to_string(searchList[i].getTimeAndDate().getStartTimeHour())+":";
						searchResults += std::to_string(searchList[i].getTimeAndDate().getStartTimeMin())+" ";
					}
					if(std::to_string(searchList[i].getTimeAndDate().getMDay()).compare("0")!=0){
						searchResults += std::to_string(searchList[i].getTimeAndDate().getMDay())+"/";
						searchResults += std::to_string(searchList[i].getTimeAndDate().getMonth())+"/";
						searchResults += std::to_string(searchList[i].getTimeAndDate().getYear())+" ";
					}
					searchResults += searchList[i].getLocation()+"\n";
		}			
	}
	return searchResults;
}


//This operation helps to render UI display results in Calendified View
int taskDisplay::configureCalendifedView(std::string logicResult){
	int pos;
	if(logicResult.substr(0,5).compare("Added")==0){ //check for add operation
		pos = -1;
	} else if(logicResult.substr(0,7).compare("Deleted")==0){ //check for delete operation
		pos = -1;
	} else if(logicResult.substr(0,7).compare("Edited.")==0){ //check for edit operation
		pos = -1;
	} else if(logicResult.substr(0,8).compare("Toggled!")==0){ //check for edit operation
		pos = -1;
	} else if(logicResult.substr(0,8).compare("Results:")==0){ //check for view operation
		pos = logicResult.find("FLOAT");
	}else {
		pos = logicResult.find(getNextDayDate()); //check for display operation
	}
	return pos;
}

//This operation helps to render UI display results in List View
std::string taskDisplay::configureListView(std::string logicResult){
	return logicResult;
}