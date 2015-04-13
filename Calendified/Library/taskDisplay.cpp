//@author A0125489U

#include "taskDisplay.h"


taskDisplay::taskDisplay(){

}

taskDisplay::taskDisplay(storage inputStorage){
	_currentStorage = inputStorage;
	_displayIndex=0;
}

taskDisplay::~taskDisplay(void)
{
	storage *storagePointer = &_currentStorage;
	storagePointer = NULL;
}

//******************************************************************
// This function executes the display and search command by:
//
// 1. This class display information retrieve from the storage
// 2. This class formats information for respective Calendified or List View
// 3. This class executes Exact Search, Power Search, "Before" Search and "After Search"
//
//******************************************************************


void taskDisplay::setDisplayContent(std::vector<task> newDisplayContent){
	_displayContent = newDisplayContent;
}

void taskDisplay::setDisplayIndex(int newDisplayIndex){
	_displayIndex = newDisplayIndex;
}

//This method updates the storage source whenever the user changes the file source directory
//Use this method when there is a change in file source directroy
void taskDisplay::updateStorageSource(){
	std::string newFilePath = _currentStorage.retrieveFilePath();
	_currentStorage.setFilePath(newFilePath);
}

//This method keeps tracks of currently displayed content in a form of vectors
//Use this method whenever there is a change in displayed items
void taskDisplay::updateDisplayContent(std::vector<task> newDisplayContent){
	std::vector<task> currentDisplayContent = getDisplayContent();
	for(int i = 0 ; i < (int) newDisplayContent.size(); i++){
		currentDisplayContent.push_back(newDisplayContent[i]);
	}
	setDisplayContent(currentDisplayContent);
}

//This method sort the list of task w.r.t. to given task list [DeadLineList]
//Use this method whenever there is a need to sort DeadList tasks
std::vector<task> taskDisplay::sortDeadLineList(std::vector<task> givenTaskList){
	std::vector<task> taskList;
	for(int i = 0; i < (int) givenTaskList.size(); i++){
		if(givenTaskList[i].getTaskType().compare(TASK_TYPE_DEADLINE_TASK) == 0){
			taskList.push_back(givenTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
}

//This method sort the list of task w.r.t. to given task list [FloatTaskList]
//Use this method whenever there is a need to sort Float tasks
std::vector<task> taskDisplay::sortFloatTaskList(std::vector<task> givenTaskList){
	std::vector<task> taskList;
	for(int i = 0; i < (int) givenTaskList.size(); i++){
		if(givenTaskList[i].getTaskType().compare(TASK_TYPE_FLOATING_TASK) == 0){
			taskList.push_back(givenTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
}

//This method sort the list of task w.r.t. to given task list [TimedTaskList]
//Use this method whenever there is a need to sort Timed tasks
std::vector<task> taskDisplay::sortTimedTaskList(std::vector<task> givenTaskList){
	std::vector<task> taskList;
	for(int i = 0; i < (int) givenTaskList.size(); i++){
		if(givenTaskList[i].getTaskType().compare(TASK_TYPE_TIMED_TASK) == 0){
			taskList.push_back(givenTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
}

//This operation sort the list of task w.r.t. to sort type [float|today|nextDay| allDay]
//Use this method whenever there is a need categorize an unidentified task list
std::vector<task> taskDisplay::sortTaskList(std::string sortType, int flipCount){
	std::vector<task> taskList;
	std::string taskDateDay;
	std::string taskDateMonth;
	std::string taskDateYear;
	std::string taskDateTime;
	std::string dateDay; 
	std::string dateMonth; 
	std::string dateYear; 
	std::string dateTime=TYPE_EMPTY;

	//This is to ensure that the file source is not empty
	if(_currentStorage.isFileEmpty()){
		return taskList;
	}

	//This is to retrieve all existing data
	std::vector<task> allTaskList = _currentStorage.readFileJson();

	//This is to check if taskList is {float List}
	if(sortType.compare(TYPE_FLOATTASK) == 0){ 
		for(int i = 0; i < (int) allTaskList.size(); i++){
			if(allTaskList[i].getTaskType().compare(TASK_TYPE_FLOATING_TASK) == 0){
				taskList.push_back(allTaskList[i]);
			}
		}
		updateDisplayContent(taskList);
		return taskList;
	} else if(sortType.compare(TYPE_ALLDAY) == 0){ 
		//This is to check if taskList is {all day List}
		for(int i = 0; i < (int) allTaskList.size(); i++){
			if(!allTaskList[i].getTaskType().compare(TASK_TYPE_FLOATING_TASK) == 0){
				taskList.push_back(allTaskList[i]);
			}
		}
		updateDisplayContent(taskList);
		return taskList;
	}else if(sortType.compare(TYPE_TODAY) == 0){ 
		//This is to check if taskList is {today List}
		dateDay = getTodayDate(flipCount);
		dateMonth = getTodayDateMonth(flipCount);
		dateYear = getTodayDateYear(flipCount);
	} else if(sortType.compare(TYPE_NEXTDAY) == 0){ 
		//This is to check if taskList is {nextDay List}
		dateDay = getNextDayDate(flipCount);
		dateMonth = getNextDayDateMonth(flipCount);
		dateYear = getNextDayDateYear(flipCount);
	}

	//This is to format and remove the {st, nd, rd, th} concat behind the date
	dateDay = dateDay.substr(0,2);
	if(dateDay[0] == KEYWORD_EMPTY_CHAR){
		dateDay = dateDay[1];
	}
	if(dateMonth[0] == KEYWORD_EMPTY_CHAR){
		dateMonth = dateMonth[1];
	}
	for(int i =0 ;i < (int) allTaskList.size(); i++){
		taskDateDay = std::to_string(allTaskList[i].getTimeAndDate().getStartMDay());
		taskDateMonth = std::to_string(allTaskList[i].getTimeAndDate().getStartMonth());
		taskDateYear = std::to_string(allTaskList[i].getTimeAndDate().getStartYear());
		taskDateTime = std::to_string(allTaskList[i].getTimeAndDate().getStartTimeHour());
		//This is to return the matched results
		if(taskDateDay.compare(dateDay) == 0 && 
			taskDateMonth.compare(dateMonth) == 0 &&
			taskDateYear.compare(dateYear) == 0 &&
			taskDateTime.compare(dateTime)!= 0){
				taskList.push_back(allTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
}

//This method returns all of today's tasks 
//Use this method to show today's task in calendifiedview
std::string taskDisplay::displayToday(int flipCount){
	std::string displayTodayResults = getTodayDate(flipCount)+KEYWORD_SPACE;
	displayTodayResults += getTodayDateMonth_Abbreviated(flipCount)+KEYWORD_NEWLINE;
	std::vector<task> todayTaskList = sortTaskList(TYPE_TODAY,flipCount);
	if(!todayTaskList.size() == 0){
		displayTodayResults += formatDisplayResults(todayTaskList,TYPE_TIMEDTASK);
	}
	return displayTodayResults;
}

//This method returns all of next day's tasks 
//Use this method to show next day's task in calendifiedview
std::string taskDisplay::displayNextDay(int flipCount){
	std::string displayNextDayResults = getNextDayDate(flipCount)+KEYWORD_SPACE;
	displayNextDayResults +=  getNextDayDateMonth_Abbreviated(flipCount)+KEYWORD_NEWLINE;
	std::vector<task> nextDayTaskList = sortTaskList(TYPE_NEXTDAY,flipCount);
	if(!nextDayTaskList.size() == 0){
		displayNextDayResults += formatDisplayResults(nextDayTaskList,TYPE_TIMEDTASK);
	}
	return displayNextDayResults;
}

//This method returns all of floating's tasks 
//Use this method to show floating's task in calendifiedview
std::string taskDisplay::displayFloatDay(int flipCount){
	std::string displayFloatResults = KEYWORD_NEWLINE;
	std::vector<task> floatTaskList = sortTaskList(TYPE_FLOATTASK,flipCount);
	if(!floatTaskList.size() == 0){
		displayFloatResults = KEYWORD_TO_DO_LIST + displayFloatResults;
		displayFloatResults += formatDisplayResults(floatTaskList,TYPE_FLOATTASK);
	}
	return displayFloatResults;
}

//This method returns all tasks 
//Use this method to show floating's task in listview.
std::string taskDisplay::displayAll(int flipCount){
	std::string displayAllResults;
	std::vector<task> allTaskList = sortTaskList(TYPE_ALLDAY,flipCount);
	std::vector<task> floatTaskList = sortTaskList(TYPE_FLOATTASK,flipCount);
	displayAllResults+=formatDisplayResults(allTaskList,TYPE_ALLDAY);
	if(!floatTaskList.size() == 0){
		displayAllResults = displayAllResults + KEYWORD_NEWLINE + KEYWORD_TO_DO_LIST+KEYWORD_NEWLINE;
		displayAllResults += formatDisplayResults(floatTaskList,TYPE_FLOATTASK);
	}
	return displayAllResults;
}

//This method formats all timed task and returns a string
//This method supports other displaying methods that needs to format
std::string taskDisplay::formatTimedTask(std::vector<task> taskList, std::string presentationType){
	std::string formatTimeTaskResults = "";
	int formatingIndex;
	for(int i =0; i< (int) taskList.size(); i++){
		formatingIndex = getDisplayIndex() + 1;
		formatTimeTaskResults += std::to_string(formatingIndex) + KEYWORD_DOT + KEYWORD_SPACE;
		if(presentationType.compare(TYPE_VIEW) == 0){
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMDay()) + KEYWORD_DATE_SEPARATOR;
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMonth()) + KEYWORD_DATE_SEPARATOR;
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartYear()) + KEYWORD_SPACE;
		}
		formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeHour()) + KEYWORD_COLON;
		if(std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()).length() == 1){
			formatTimeTaskResults += TYPE_EMPTY + std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()) + KEYWORD_SPACE;
		} else {
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()) + KEYWORD_SPACE;
		}
		formatTimeTaskResults += KEYWORD_TILDE + KEYWORD_SPACE;
		formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getEndTimeHour()) + KEYWORD_COLON;
		if(std::to_string(taskList[i].getTimeAndDate().getEndTimeMin()).length() == 1){
			formatTimeTaskResults += TYPE_EMPTY + std::to_string(taskList[i].getTimeAndDate().getEndTimeMin()) + KEYWORD_SPACE;
		} else {
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getEndTimeMin()) + KEYWORD_SPACE;
		}
		formatTimeTaskResults += taskList[i].getTitle() + KEYWORD_SPACE;
		if(taskList[i].getLocation().compare("") != 0){
			formatTimeTaskResults += taskList[i].getLocation();
		}
		if(taskList[i].getIsDone()){
			formatTimeTaskResults += KEYWORD_SPACE + KEYWORD_DONE;
		}
		if(taskList[i].getTaskType().compare(KEYWORD_DEADLINE) == 0){
			formatTimeTaskResults += KEYWORD_SPACE + KEYWORD_DUE;
		}
		formatTimeTaskResults += KEYWORD_NEWLINE;
		setDisplayIndex(formatingIndex);
	}
	return formatTimeTaskResults;
}

//This operation formats all Float Task and returns a string
//This method supports other displaying methods that needs to format
std::string taskDisplay::formatFloatTask(std::vector<task> taskList){
	std::string formatFloatTaskResults = "";
	int formatingIndex;
	for(int i = 0; i < (int) taskList.size(); i++){
		formatingIndex = getDisplayIndex() + 1;
		formatFloatTaskResults += std::to_string(formatingIndex) + KEYWORD_DOT + KEYWORD_SPACE;
		if(std::to_string(taskList[i].getTimeAndDate().getStartTimeHour()).compare(TYPE_EMPTY)!= 0){
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeHour()) + KEYWORD_COLON;
			if(std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()).length() == 1){
				formatFloatTaskResults += TYPE_EMPTY+std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()) + KEYWORD_SPACE;
			} else {
				formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+KEYWORD_SPACE;
			}
		}
		if(std::to_string(taskList[i].getTimeAndDate().getStartMDay()).compare(TYPE_EMPTY) != 0){
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMDay()) + KEYWORD_DATE_SEPARATOR;
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMonth()) + KEYWORD_DATE_SEPARATOR;
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartYear()) + KEYWORD_SPACE;
		}
		formatFloatTaskResults += taskList[i].getTitle() + KEYWORD_SPACE;
		if(taskList[i].getLocation().compare("") != 0){
			formatFloatTaskResults += taskList[i].getLocation();
		}
		if(taskList[i].getIsDone()){
			formatFloatTaskResults += KEYWORD_SPACE + KEYWORD_DONE;
		}
		if(taskList[i].getTaskType().compare(KEYWORD_DEADLINE) == 0){
			formatFloatTaskResults += KEYWORD_SPACE + KEYWORD_DUE;
		}
		formatFloatTaskResults += KEYWORD_NEWLINE;
		setDisplayIndex(formatingIndex);
	}
	return formatFloatTaskResults;
}

//This method formats the display results based on the parameter formatType - [time|float|all] 
//This method will call the other respective methods for different style of formatting 
std::string taskDisplay::formatDisplayResults(std::vector<task> taskList, std::string formatType){
	std::string formatResults = "";
	if(formatType.compare(TYPE_TIMEDTASK) == 0){
		formatResults = formatTimedTask(taskList,TYPE_DISPLAY);
	}else if(formatType.compare(TYPE_ALLDAY) == 0){
		formatResults = formatTimedTask(taskList,TYPE_VIEW);
	}else if(formatType.compare(TYPE_FLOATTASK) == 0){
		formatResults = formatFloatTask(taskList);
	}
	return formatResults;
}

//This method formats the search results
//This method supports other displaying methods that needs to format
std::string taskDisplay::formatSearchResults(std::vector<task> searchList){
	std::string searchResults;
	std::vector<task> searchFloatResults;
	searchResults += TYPE_RESULTS + KEYWORD_NEWLINE;
	searchResults += formatTimedTask(sortTimedTaskList(searchList),TYPE_VIEW);
	searchResults += formatTimedTask(sortDeadLineList(searchList),TYPE_VIEW);
	searchFloatResults = sortFloatTaskList(searchList);
	if(searchFloatResults.size()>0){
		searchResults += KEYWORD_NEWLINE + KEYWORD_TO_DO_LIST + KEYWORD_NEWLINE;
		searchResults += formatFloatTask(searchFloatResults);
	}
	return searchResults;
}

//This method returns current date- Day
std::string taskDisplay::getTodayDate(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	if(timeinfo->tm_mday == 1 || timeinfo->tm_mday == 21 || timeinfo->tm_mday == 31){
		strftime(output,30,"%dst",timeinfo);
	}else if(timeinfo->tm_mday == 2 || timeinfo->tm_mday == 22){
		strftime(output,30,"%dnd",timeinfo);
	}else if(timeinfo->tm_mday == 3 || timeinfo->tm_mday == 23){
		strftime(output,30,"%drd",timeinfo);
	}else {
		strftime(output,30,"%dth",timeinfo);
	}
	return std::string(output);
}

//This method returns current date- Month
std::string taskDisplay::getTodayDateMonth(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%m",timeinfo);
	return std::string(output);
}

//This method returns current date- Month_Abbreviated eg. Apr, May
std::string taskDisplay::getTodayDateMonth_Abbreviated(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%b",timeinfo);
	return std::string(output);
}

//This method returns current date- Year
std::string taskDisplay::getTodayDateYear(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%Y",timeinfo);
	return std::string(output);
}

//This method returns current date- Day Month Year
std::string taskDisplay::getTodayDateDMY(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
	return std::string(output);
}

//This method returns next date- Day
std::string taskDisplay::getNextDayDate(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	if(timeinfo->tm_mday == 1 || timeinfo->tm_mday == 21 || timeinfo->tm_mday == 31){
		strftime(output,30,"%dst",timeinfo);
	}else if(timeinfo->tm_mday == 2 || timeinfo->tm_mday == 22){
		strftime(output,30,"%dnd",timeinfo);
	}else if(timeinfo->tm_mday == 3 || timeinfo->tm_mday == 23){
		strftime(output,30,"%drd",timeinfo);
	}else {
		strftime(output,30,"%dth",timeinfo);
	}
	return std::string(output);
}

//This method returns next date- Month
std::string taskDisplay::getNextDayDateMonth(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%m",timeinfo);
	return std::string(output);
}

//This method returns next date- Month_Abbreviated eg. Apr, May
std::string taskDisplay::getNextDayDateMonth_Abbreviated(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%b",timeinfo);
	return std::string(output);
}

//This method returns next date- Year
std::string taskDisplay::getNextDayDateYear(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%Y",timeinfo);
	return std::string(output);
}

//This method returns next date- Day Month Year
std::string taskDisplay::getNextDayDateDMY(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount != 0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
	return std::string(output);
}

//This method returns the abbreviated name of the month
std::string taskDisplay::getMonthAbbreviated(int tempMonth){
	std::string monthString="";
	if(tempMonth==1){
		monthString = "jan";
	}else if(tempMonth == 2){
		monthString = "feb";
	}else if(tempMonth == 3){
		monthString = "mar";
	}else if(tempMonth == 4){
		monthString = "apr";
	}else if(tempMonth == 5){
		monthString = "may";
	}else if(tempMonth == 6){
		monthString = "jun";
	}else if(tempMonth == 7){
		monthString = "jul";
	}else if(tempMonth == 8){
		monthString = "aug";
	}else if(tempMonth == 9){
		monthString = "sep";
	}else if(tempMonth == 10){
		monthString = "oct";
	}else if(tempMonth == 11){
		monthString = "nov";
	}else if(tempMonth == 12){
		monthString = "dec";
	}
	return monthString;		
}

//This method results the name of the month 
std::string taskDisplay::getMonthName(int tempMonth){
	std::string monthString = "";
	if(tempMonth == 1){
		monthString = "january";
	}else if(tempMonth == 2){
		monthString = "february";
	}else if(tempMonth == 3){
		monthString = "march";
	}else if(tempMonth == 4){
		monthString = "april";
	}else if(tempMonth == 5){
		monthString = "may";
	}else if(tempMonth == 6){
		monthString = "june";
	}else if(tempMonth == 7){
		monthString = "july";
	}else if(tempMonth == 8){
		monthString = "august";
	}else if(tempMonth == 9){
		monthString = "september";
	}else if(tempMonth == 10){
		monthString = "october";
	}else if(tempMonth == 11){
		monthString = "november";
	}else if(tempMonth == 12){
		monthString = "december";
	}
	return monthString;		
}

std::vector<task> taskDisplay::getDisplayContent(){
	return _displayContent;
}

int taskDisplay::getDisplayIndex(){
	return _displayIndex;
}

//This method converts selectedIndex to StorageIndex
//Use this method whenever there is a selection on the GUI
int taskDisplay::getStorageIndex(std::vector<task> currentDisplayContent, int selectedIndex){
	int storageIndex = -1;

	//This is to ensure that the selected Index on GUI is valid
	if(selectedIndex > (int) currentDisplayContent.size()
		|| selectedIndex < 0){
			return storageIndex;
	}
	assert(selectedIndex != NULL);
	assert(selectedIndex > 0);
	selectedIndex = selectedIndex - 1;

	//This is to ensure that the file source is not empty
	if(_currentStorage.isFileEmpty()){
		return storageIndex;
	}

	//This is to retrieve all exisiting data
	std::vector<task> allTaskList = _currentStorage.readFileJson();

	//This is to convert selected UI Index into file storage Index
	for(int i = 0; i < (int) allTaskList.size(); i++){
		if(currentDisplayContent[selectedIndex].getCommandAction().compare(allTaskList[i].getCommandAction()) == 0 &&
			currentDisplayContent[selectedIndex].getIsDone() == allTaskList[i].getIsDone() &&
			currentDisplayContent[selectedIndex].getLocation().compare(allTaskList[i].getLocation()) == 0 &&
			currentDisplayContent[selectedIndex].getTaskType().compare(allTaskList[i].getTaskType()) == 0 &&
			currentDisplayContent[selectedIndex].getTitle().compare(allTaskList[i].getTitle()) == 0 &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getStartMDay()==allTaskList[i].getTimeAndDate().getStartMDay() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getStartMonth()==allTaskList[i].getTimeAndDate().getStartMonth() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getStartYear()==allTaskList[i].getTimeAndDate().getStartYear() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getStartTimeHour()==allTaskList[i].getTimeAndDate().getStartTimeHour() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getStartTimeMin()==allTaskList[i].getTimeAndDate().getStartTimeMin() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getEndTimeHour()==allTaskList[i].getTimeAndDate().getEndTimeHour() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getEndTimeMin()==allTaskList[i].getTimeAndDate().getEndTimeMin()){
				storageIndex=i;
		}
	}
	return storageIndex;
}

//This method search the all existing data that is related to the search Item input
std::string taskDisplay::searchPower(std::string searchItem){
	std::string searchResults;
	std::string searchBuffer; 
	std::stringstream ss(searchItem);
	std::vector<task> searchList;
	std::vector<task> tempSearchList;
	std::vector<std::string> searchItems; 

	//This is to break down into smaller strings for more detail searching
	while (ss >> searchBuffer){
		std::transform(searchBuffer.begin(), searchBuffer.end(), searchBuffer.begin(), ::tolower);
		searchItems.push_back(searchBuffer);
	}

	for(int i = 0; i < (int) searchItems.size(); i++){
		if(searchItems[i].length() >= 6){
			//Search for first 3 characters
			tempSearchList = searchExact(searchItems[i].substr(0,3)); 
			for(int j = 0; j < (int) tempSearchList.size(); j++){
				if(!checkSameTask(tempSearchList[j],searchList)){
					searchList.push_back(tempSearchList[j]);
				}
			}
			//Search for mid-field characters
			tempSearchList = searchExact(searchItems[i].substr(searchItems[i].length()/3,searchItems[i].length()/3*2)); 
			for(int j = 0; j < (int) tempSearchList.size(); j++){
				if(!checkSameTask(tempSearchList[j],searchList)){
					searchList.push_back(tempSearchList[j]);
				}
			}
			//Search for last 3 characters
			tempSearchList = searchExact(searchItems[i].substr(searchItems[i].length()-3)); 
		}else{
			tempSearchList= searchExact(searchItems[i]);
		}

		//This is to account for repeated searched Items
		for(int j = 0; j < (int) tempSearchList.size(); j++){
			if(!checkSameTask(tempSearchList[j],searchList)){
				searchList.push_back(tempSearchList[j]);
			}
		}
	}
	searchResults = formatSearchResults(searchList);
	return searchResults;
}

//This method search the all existing data OLDER THAN the search Item input
std::string taskDisplay::searchBefore(std::string searchItem){
	std::vector<task> allTaskList;
	std::vector<task> searchList;
	int searchResultsIndex = 0;
	std::string searchResults;
	int searchDateYear = atoi(searchItem.substr(4).c_str());		//This is to extract YEAR from the given searchItem
	int searchDateMonth = atoi(searchItem.substr(2,2).c_str());		//This is to extract MONTH from the given searchItem
	int searchDateDay = atoi(searchItem.substr(0,2).c_str());		//This is to extract DATE from the given searchItem
	int taskListYear;
	int taskListMonth;
	int taskListDay;

	//This is ensure that the file source is not empty
	if(_currentStorage.isFileEmpty()){
		searchItem ="";
		return searchItem;
	}
	
	//This is to retrieve all existing file
	allTaskList = _currentStorage.readFileJson();

	for(int i = 0; i < (int) allTaskList.size(); i++){ 
		//populate the the vector with revelant search results
		taskListDay = allTaskList[i].getTimeAndDate().getStartMDay();
		taskListMonth = allTaskList[i].getTimeAndDate().getStartMonth();
		taskListYear = allTaskList[i].getTimeAndDate().getStartYear();
		if(taskListYear != 0 && taskListYear < searchDateYear){
			searchList.push_back(allTaskList[i]);
		}else if(taskListYear != 0 && taskListYear == searchDateYear){
			if(taskListYear != 0 && taskListMonth < searchDateMonth){
				searchList.push_back(allTaskList[i]);
			}else if(taskListYear != 0 && taskListMonth == searchDateMonth){
				if(taskListYear != 0 && taskListDay<searchDateDay){
					searchList.push_back(allTaskList[i]);
				}
			}
		}
	}
	//This is to format the search results for displaying before returning
	searchResults = formatSearchResults(searchList);
	return searchResults;	
}


//This method search the all existing data OLDER THAN the search Item input
std::string taskDisplay::searchAfter(std::string searchItem){
	std::vector<task> allTaskList;
	std::vector<task> searchList;
	int searchResultsIndex=0;
	std::string searchResults;
	int searchDateYear = atoi(searchItem.substr(4).c_str());		//This is to extract YEAR from the given searchItem
	int searchDateMonth = atoi(searchItem.substr(2,2).c_str());		//This is to extract MONTH from the given searchItem
	int searchDateDay = atoi(searchItem.substr(0,2).c_str());		//This is to extract DATE from the given searchItem
	int taskListYear;
	int taskListMonth;
	int taskListDay;

	//This is ensure that the file source is not empty
	if(_currentStorage.isFileEmpty()){
		searchItem = "";
		return searchItem;
	}

	//This is to retrieve all existing file
	allTaskList = _currentStorage.readFileJson();

	for(int i = 0; i < (int) allTaskList.size(); i++){ 
		//populate the the vector with revelant search results
		taskListDay = allTaskList[i].getTimeAndDate().getStartMDay();
		taskListMonth = allTaskList[i].getTimeAndDate().getStartMonth();
		taskListYear = allTaskList[i].getTimeAndDate().getStartYear();
		if(taskListYear > searchDateYear){
			searchList.push_back(allTaskList[i]);
		}else if(taskListYear == searchDateYear){
			if(taskListMonth > searchDateMonth){
				searchList.push_back(allTaskList[i]);
			}else if(taskListMonth == searchDateMonth){
				if(taskListDay > searchDateDay){
					searchList.push_back(allTaskList[i]);
				}
			}
		}
	}
	//This is to format the search results for displaying before returning
	searchResults = formatSearchResults(searchList);
	return searchResults;
}

//This method search exactly to the all existing data w.r.t. the search Item input
//This method supports the method for power searching
std::vector<task> taskDisplay::searchExact(std::string searchItem){
	bool isExact = false;
	std::vector<task> allTaskList;
	std::vector<task> allTaskListLower;
	std::vector<task> searchList;
	char chars[] = "\"";
	int searchResultsIndex=0;
	std::string searchResults; 
	std::string tempLowerStr;
	std::string tempTitle;
	std::string tempLocation;
	int tempDay;
	int tempMonth;
	int tempYear;
	std::string tempDate;
	std::string tempDateBackslash;
	std::string tempDateDash;
	std::string tempMonthAbbreviated;
	std::string tempMonthName;
	std::string tempDateAbbreviated;
	std::string tempDateAbbreviatedBackslash;
	std::string tempDateAbbreviatedDash;
	std::string tempDateName;
	std::string tempDateNameBackslash;
	std::string tempDateNameDash;	
	int tempHour;
	int tempMin;
	std::string tempTimeHour;
	std::string tempTimeMin;
	std::string tempTimeColon;
	std::string tempTimeHourAM;
	std::string tempTimeHourPM;
	std::string tempTime24;
	std::string tempTime12;

	//This is ensure that the file source is not empty
	if(_currentStorage.isFileEmpty()){
		searchItem = "";
		return searchList;
	}

	//This is to differ whether a EXACT or POWER search is conducted
	if(searchItem[0] == '"'){
		isExact = true;
		searchItem.erase (std::remove(searchItem.begin(), 
			searchItem.end(), 
			chars[0]), 
			searchItem.end()
			);
	}

	//This is to retrieve all existing file
	allTaskList = _currentStorage.readFileJson();
	allTaskListLower = allTaskList;

	//Transform to lower case for more accurate searches
	for(int i = 0; i < (int) allTaskList.size(); i++){
		tempLowerStr = allTaskList[i].getLocation();
		std::transform(tempLowerStr.begin(), tempLowerStr.end(), tempLowerStr.begin(), ::tolower);
		allTaskListLower[i].setLocation(tempLowerStr);
		tempLowerStr = allTaskList[i].getTitle();
		std::transform(tempLowerStr.begin(), tempLowerStr.end(), tempLowerStr.begin(), ::tolower);
		allTaskListLower[i].setTitle(tempLowerStr);
	}

	for(int i = 0; i < (int) allTaskListLower.size(); i++){ 
		//populate the the vector with revelant search results
		tempTitle = allTaskListLower[i].getTitle();
		tempLocation = allTaskListLower[i].getLocation();
		if(tempTitle[0] == 0){
			tempTitle = KEYWORD_INVALID;
		}
		if(tempLocation[0] == 0){
			tempLocation = KEYWORD_INVALID;
		}

		//Initialize the search parameters
		tempDay = allTaskListLower[i].getTimeAndDate().getStartMDay();
		tempMonth = allTaskListLower[i].getTimeAndDate().getStartMonth();
		tempYear = allTaskListLower[i].getTimeAndDate().getStartYear();
		tempHour = allTaskListLower[i].getTimeAndDate().getStartTimeHour();
		tempMin = allTaskListLower[i].getTimeAndDate().getStartTimeMin();
		if(tempDay != 0 && tempMonth != 0 && tempYear != 0){
			tempDate = std::to_string(tempDay) + std::to_string(tempMonth) + std::to_string(tempYear);
			tempDateBackslash = std::to_string(tempDay) + KEYWORD_DATE_SEPARATOR + std::to_string(tempMonth) + KEYWORD_DATE_SEPARATOR + std::to_string(tempYear);
			tempDateDash = std::to_string(tempDay) + KEYWORD_DASH+std::to_string(tempMonth) + KEYWORD_DASH+std::to_string(tempYear);
			tempMonthAbbreviated = getMonthAbbreviated(tempMonth);
			tempMonthName = getMonthName(tempMonth);
			tempDateAbbreviated = std::to_string(tempDay) + tempMonthAbbreviated + std::to_string(tempYear);
			tempDateAbbreviatedBackslash = std::to_string(tempDay) + KEYWORD_DATE_SEPARATOR + tempMonthAbbreviated + KEYWORD_DATE_SEPARATOR + std::to_string(tempYear);
			tempDateAbbreviatedDash = std::to_string(tempDay) + KEYWORD_DASH + tempMonthAbbreviated + KEYWORD_DASH + std::to_string(tempYear);
			tempDateName = std::to_string(tempDay) + tempMonthName+std::to_string(tempYear);
			tempDateNameBackslash = std::to_string(tempDay) + KEYWORD_DATE_SEPARATOR + tempMonthName + KEYWORD_DATE_SEPARATOR + std::to_string(tempYear);
			tempDateNameDash = std::to_string(tempDay) + KEYWORD_DASH + tempMonthName + KEYWORD_DASH + std::to_string(tempYear);
		} else { 
			tempDate = KEYWORD_INVALID;
			tempDateBackslash = KEYWORD_INVALID;
			tempDateDash = KEYWORD_INVALID;
			tempMonthAbbreviated = KEYWORD_INVALID;
			tempMonthName = KEYWORD_INVALID;
			tempDateAbbreviated = KEYWORD_INVALID;
			tempDateAbbreviatedBackslash = KEYWORD_INVALID;
			tempDateAbbreviatedDash = KEYWORD_INVALID;
			tempDateName = KEYWORD_INVALID;
			tempDateNameBackslash = KEYWORD_INVALID;
			tempDateNameDash = KEYWORD_INVALID;
		}
		if(tempHour != 0){
			tempTimeHour = std::to_string(tempHour);
			tempTimeMin = std::to_string(tempMin);
			if(tempHour > 12){
				tempTime12 = std::to_string(tempHour - 12);
			}else {
				tempTime12 = tempTimeHour;
			}
			if(tempTimeMin.length() == 1){
				tempTimeMin =TYPE_EMPTY + tempTimeMin;
			}
			tempTimeColon = tempTimeHour + KEYWORD_COLON + tempTimeMin;
			tempTimeHourAM = tempTime12 + KEYWORD_AM;
			tempTimeHourPM = tempTime12 + KEYWORD_PM;
			tempTime24 = tempTimeHour + tempTimeMin;
		} else{
			tempTimeHour = KEYWORD_INVALID;
			tempTimeMin = KEYWORD_INVALID;
			tempTimeColon = KEYWORD_INVALID;
			tempTimeHourAM = KEYWORD_INVALID;
			tempTimeHourPM = KEYWORD_INVALID;
			tempTime24 = KEYWORD_INVALID;
		}
		
		//This is to search for possible reusults w.r.t. to all searching parameters
		if(tempTitle.find(searchItem) != std::string::npos || 
			tempLocation.find(searchItem) != std::string::npos || 
			std::to_string(tempDay).find(searchItem) != std::string::npos || 
			std::to_string(tempMonth).find(searchItem) != std::string::npos || 
			std::to_string(tempYear).find(searchItem) != std::string::npos ||
			tempDate.find(searchItem) != std::string::npos ||
			tempDateBackslash.find(searchItem) != std::string::npos ||
			tempDateDash.find(searchItem) != std::string::npos ||
			tempMonthAbbreviated.find(searchItem) != std::string::npos ||
			tempMonthName.find(searchItem) != std::string::npos ||
			tempDateAbbreviated.find(searchItem) != std::string::npos ||
			tempDateAbbreviatedBackslash.find(searchItem) != std::string::npos ||
			tempDateAbbreviatedDash.find(searchItem) != std::string::npos ||
			tempDateName.find(searchItem) != std::string::npos ||
			tempDateNameBackslash.find(searchItem) != std::string::npos ||
			tempDateNameDash.find(searchItem) != std::string::npos ||
			tempTimeHour.find(searchItem) != std::string::npos ||
			tempTimeMin.find(searchItem) != std::string::npos ||
			tempTimeColon.find(searchItem) != std::string::npos ||
			tempTimeHourAM.find(searchItem) != std::string::npos ||
			tempTimeHourPM.find(searchItem) != std::string::npos ||
			tempTime24.find(searchItem) != std::string::npos){
				searchList.push_back(allTaskList[i]);
		}

		//This is to account for power search
		if(!isExact){
			std::vector<std::string> searchItems; 
			std::string searchBuffer; 
			std::stringstream ss(tempTitle);

			//This break down the "task title" into smaller strings for more possible search results
			while (ss >> searchBuffer){
				std::transform(searchBuffer.begin(), searchBuffer.end(), searchBuffer.begin(), ::tolower);
				searchItems.push_back(searchBuffer);
			}

			//This is to search for more results in a "task title"
			for(int j = 0; j < (int) searchItems.size(); j++){
				if(searchItems[j].find(searchItem) != std::string::npos){
					searchList.push_back(allTaskList[i]);
				}else if (searchItem.find(searchItems[j]) != std::string::npos){
					searchList.push_back(allTaskList[i]);
				}
			}
		}
	}
	return searchList;
}

//This method helps to check for duplicate results in a vector during a search
//Use this method for search process to remove duplicate results
bool taskDisplay::checkSameTask(task tempSearchItem , std::vector<task> currenetSearchList){
	bool isSame = false;
	for(int i =0; i < (int) currenetSearchList.size();i++){
		if(currenetSearchList[i].getCommandAction()==tempSearchItem.getCommandAction() &&
			currenetSearchList[i].getIsClash()==tempSearchItem.getIsClash() &&
			currenetSearchList[i].getIsDone()==tempSearchItem.getIsDone() &&
			currenetSearchList[i].getLocation()==tempSearchItem.getLocation() &&
			currenetSearchList[i].getTaskType()==tempSearchItem.getTaskType() &&
			currenetSearchList[i].getTimeAndDate().getStartMDay()==tempSearchItem.getTimeAndDate().getStartMDay() &&
			currenetSearchList[i].getTimeAndDate().getStartMonth()==tempSearchItem.getTimeAndDate().getStartMonth() &&
			currenetSearchList[i].getTimeAndDate().getStartYear()==tempSearchItem.getTimeAndDate().getStartYear() &&
			currenetSearchList[i].getTitle()==tempSearchItem.getTitle()){
				isSame = true;
				break;
		}
	}
	return isSame;
}

//This method helps to render UI display results in Calendified View
//Use this method for CalendifiedView
int taskDisplay::configureCalendifedView(std::string logicResult, int flipCount){
	//This variable is to account for the UI CalendifiedView 
	int pos; 
	//Update pos for add operation
	if(logicResult.substr(0,5).compare(TYPE_ADD) == 0){
		pos = -1;
	//Update pos for delete operation
	} else if(logicResult.substr(0,7).compare(TYPE_DELETED) == 0){ 
		pos = -1;
	//Update pos for edit operation
	} else if(logicResult.substr(0,7).compare(TYPE_EDITED) == 0){ 
		pos = -1;
	//Update pos for toggle operation
	} else if(logicResult.substr(0,8).compare(TYPE_TOGGLED) == 0){ 
		pos = -1;
	//Update pos for search operation
	} else if(logicResult.substr(0,8).compare(TYPE_RESULTS) == 0){ 
		pos = logicResult.find(KEYWORD_TO_DO_LIST);
		pos = logicResult.length();
	}else {
	//Update pos for display operation
		pos = logicResult.find(getNextDayDate(flipCount)); 
	}
	return pos;
}

//This method helps to render UI display results in List View
std::string taskDisplay::configureListView(std::string logicResult){
	return logicResult;
}