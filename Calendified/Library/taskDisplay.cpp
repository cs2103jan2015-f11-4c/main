//@author A0125489U

#include "taskDisplay.h";


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

std::vector<task> taskDisplay::getDisplayContent(){
	return _displayContent;
}
void taskDisplay::setDisplayContent(std::vector<task> newDisplayContent){
	_displayContent = newDisplayContent;
}

void taskDisplay::setDisplayIndex(int newDisplayIndex){
	_displayIndex = newDisplayIndex;
}

int taskDisplay::getDisplayIndex(){
	return _displayIndex;
}

void taskDisplay::updateStorageSource(){
	std::string newFilePath = _currentStorage.retrieveFilePath();
	_currentStorage.setFilePath(newFilePath);
}

//This operation keeps tracks of currently displayed content in a form of vectors
void taskDisplay::updateDisplayContent(std::vector<task> newDisplayContent){
	std::vector<task> currentDisplayContent = getDisplayContent();
	for(int i=0 ; i < newDisplayContent.size(); i++){
		currentDisplayContent.push_back(newDisplayContent[i]);
	}
	setDisplayContent(currentDisplayContent);
}


//This operation converts selectedIndex to StorageIndex
int taskDisplay::getStorageIndex(std::vector<task> currentDisplayContent, int selectedIndex){
	int storageIndex=-1;
	if(selectedIndex > currentDisplayContent.size()
		|| selectedIndex < 0){
		return storageIndex;
	}
	assert(selectedIndex != NULL);
	assert(selectedIndex >0);
	selectedIndex = selectedIndex-1;
	if(_currentStorage.isFileEmpty()){
		return storageIndex;
	}
	std::vector<task> allTaskList = _currentStorage.readFileJson();
	for(int i =0; i< allTaskList.size();i++){
		if(currentDisplayContent[selectedIndex].getCommandAction().compare(allTaskList[i].getCommandAction()) ==0 &&
			currentDisplayContent[selectedIndex].getIsDone() == allTaskList[i].getIsDone() &&
			currentDisplayContent[selectedIndex].getLocation().compare(allTaskList[i].getLocation()) ==0 &&
			currentDisplayContent[selectedIndex].getTaskType().compare(allTaskList[i].getTaskType()) ==0 &&
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

//This operation sort the list of task w.r.t. to given task list [FloatTaskList]
std::vector<task> taskDisplay::sortFloatTaskList(std::vector<task> givenTaskList){
	std::vector<task> taskList;
	for(int i =0;i < givenTaskList.size();i++){
		/*if(givenTaskList[i].getTimeAndDate().getStartMDay() == 0 || 
			givenTaskList[i].getTimeAndDate().getStartMonth() == 0 || 
			givenTaskList[i].getTimeAndDate().getStartYear() == 0 || 
			givenTaskList[i].getTimeAndDate().getStartTimeHour() == 0){*/
		if(givenTaskList[i].getTaskType().compare("FloatingTask")==0){
				taskList.push_back(givenTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
}

//This operation sort the list of task w.r.t. to given task list [TimedTaskList]
std::vector<task> taskDisplay::sortTimedTaskList(std::vector<task> givenTaskList){
	std::vector<task> taskList;
	for(int i =0;i < givenTaskList.size();i++){
		/*if(givenTaskList[i].getTimeAndDate().getStartMDay() != 0 && 
			givenTaskList[i].getTimeAndDate().getStartMonth() != 0 && 
			givenTaskList[i].getTimeAndDate().getStartYear() != 0 && 
			givenTaskList[i].getTimeAndDate().getStartTimeHour() != 0){*/
		if(givenTaskList[i].getTaskType().compare("TimedTask")==0){
				taskList.push_back(givenTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
}

//This operation sort the list of task w.r.t. to sort type [float|today|nextDay| allDay]
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

	if(_currentStorage.isFileEmpty()){
		return taskList;
	}
	std::vector<task> allTaskList = _currentStorage.readFileJson();
	if(sortType.compare(TYPE_FLOATTASK)==0){ //check if taskList is {float List}
		for(int i =0;i < allTaskList.size();i++){
			/*if(allTaskList[i].getTimeAndDate().getStartMDay() == 0 || 
				allTaskList[i].getTimeAndDate().getStartMonth() == 0 || 
				allTaskList[i].getTimeAndDate().getStartYear() == 0 || 
				allTaskList[i].getTimeAndDate().getStartTimeHour() == 0){*/
			if(allTaskList[i].getTaskType().compare("FloatingTask")==0){
					taskList.push_back(allTaskList[i]);
			}
		}
		updateDisplayContent(taskList);
		return taskList;
	} else if(sortType.compare(TYPE_ALLDAY)==0){ //check if taskList is {all day List}
		for(int i =0;i < allTaskList.size();i++){
			if(!allTaskList[i].getTaskType().compare("FloatingTask")==0){
					taskList.push_back(allTaskList[i]);
			}
		}
		updateDisplayContent(taskList);
		return taskList;
	}else if(sortType.compare(TYPE_TODAY)==0){ //check if taskList is {today List}
		dateDay = getTodayDate(flipCount);
		dateMonth = getTodayDateMonth(flipCount);
		dateYear = getTodayDateYear(flipCount);
	} else if(sortType.compare(TYPE_NEXTDAY)==0){ //check if taskList is {nextDay List}
		dateDay = getNextDayDate(flipCount);
		dateMonth = getNextDayDateMonth(flipCount);
		dateYear = getNextDayDateYear(flipCount);
	}
	dateDay = dateDay.substr(0,2);
	if(dateDay[0] ==KEYWORD_EMPTY_CHAR){
		dateDay = dateDay[1];
	}
	if(dateMonth[0] ==KEYWORD_EMPTY_CHAR){
		dateMonth = dateMonth[1];
	}
	for(int i =0;i < allTaskList.size();i++){
		taskDateDay = std::to_string(allTaskList[i].getTimeAndDate().getStartMDay());
		taskDateMonth = std::to_string(allTaskList[i].getTimeAndDate().getStartMonth());
		taskDateYear = std::to_string(allTaskList[i].getTimeAndDate().getStartYear());
		taskDateTime = std::to_string(allTaskList[i].getTimeAndDate().getStartTimeHour());

		if(taskDateDay.compare(dateDay)==0 && 
			taskDateMonth.compare(dateMonth)==0 &&
			taskDateYear.compare(dateYear)==0 &&
			taskDateTime.compare(dateTime)!=0){
			taskList.push_back(allTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
}
//
std::string taskDisplay::displayToday(int flipCount){
	std::string displayTodayResults = getTodayDate(flipCount)+KEYWORD_SPACE;
	displayTodayResults += getTodayDateMonth_Abbreviated(flipCount)+KEYWORD_NEWLINE;
	std::vector<task> todayTaskList = sortTaskList(TYPE_TODAY,flipCount);
	if(!todayTaskList.size()==0){
		displayTodayResults += formatDisplayResults(todayTaskList,TYPE_TIMEDTASK);
	}
	return displayTodayResults;
}

//
std::string taskDisplay::displayNextDay(int flipCount){
	std::string displayNextDayResults = getNextDayDate(flipCount)+KEYWORD_SPACE;
	displayNextDayResults +=  getNextDayDateMonth_Abbreviated(flipCount)+KEYWORD_NEWLINE;
	std::vector<task> nextDayTaskList = sortTaskList(TYPE_NEXTDAY,flipCount);
	if(!nextDayTaskList.size()==0){
		displayNextDayResults += formatDisplayResults(nextDayTaskList,TYPE_TIMEDTASK);
	}
	return displayNextDayResults;
}

//
std::string taskDisplay::displayFloatDay(int flipCount){
	std::string displayFloatResults= KEYWORD_NEWLINE;
	std::vector<task> floatTaskList = sortTaskList(TYPE_FLOATTASK,flipCount);
	if(!floatTaskList.size()==0){
		displayFloatResults = KEYWORD_TO_DO_LIST+displayFloatResults;
		displayFloatResults += formatDisplayResults(floatTaskList,TYPE_FLOATTASK);
	}
	return displayFloatResults;
}

std::string taskDisplay::displayAll(int flipCount){
	std::string displayAllResults;
	std::vector<task> allTaskList = sortTaskList(TYPE_ALLDAY,flipCount);
	std::vector<task> floatTaskList = sortTaskList(TYPE_FLOATTASK,flipCount);
	displayAllResults+=formatDisplayResults(allTaskList,TYPE_ALLDAY);
	if(!floatTaskList.size()==0){
		displayAllResults = displayAllResults+KEYWORD_NEWLINE+KEYWORD_TO_DO_LIST+KEYWORD_NEWLINE;
		displayAllResults+=formatDisplayResults(floatTaskList,TYPE_FLOATTASK);
	}
	return displayAllResults;
}

std::string taskDisplay::formatTimedTask(std::vector<task> taskList, std::string presentationType){
	std::string formatTimeTaskResults = "";
	int formatingIndex;
	for(int i =0; i< taskList.size();i++){
		formatingIndex = getDisplayIndex()+1;
			formatTimeTaskResults += std::to_string(formatingIndex)+KEYWORD_DOT+KEYWORD_SPACE;
			if(presentationType.compare(TYPE_VIEW)==0){
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMDay())+KEYWORD_DATE_SEPARATOR;
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMonth())+KEYWORD_DATE_SEPARATOR;
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartYear())+KEYWORD_SPACE;
			}
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeHour())+KEYWORD_COLON;
			if(std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()).length() == 1){
				formatTimeTaskResults += TYPE_EMPTY+std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+KEYWORD_SPACE;
			} else {
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+KEYWORD_SPACE;
			}
			formatTimeTaskResults += KEYWORD_TILDE+KEYWORD_SPACE;
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getEndTimeHour())+KEYWORD_COLON;
			if(std::to_string(taskList[i].getTimeAndDate().getEndTimeMin()).length() == 1){
				formatTimeTaskResults += TYPE_EMPTY+std::to_string(taskList[i].getTimeAndDate().getEndTimeMin())+KEYWORD_SPACE;
			} else {
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getEndTimeMin())+KEYWORD_SPACE;
			}
			formatTimeTaskResults += taskList[i].getTitle()+KEYWORD_SPACE;
			if(taskList[i].getLocation().compare("")!=0){
				formatTimeTaskResults += taskList[i].getLocation();
			}
			if(taskList[i].getIsDone()){
				formatTimeTaskResults+= KEYWORD_SPACE+KEYWORD_DONE;
			}
			if(taskList[i].getTaskType().compare(KEYWORD_DEADLINE)==0){
				formatTimeTaskResults+= KEYWORD_SPACE+KEYWORD_DUE;
			}
			formatTimeTaskResults+=KEYWORD_NEWLINE;
			setDisplayIndex(formatingIndex);
		}
	return formatTimeTaskResults;
}

std::string taskDisplay::formatFloatTask(std::vector<task> taskList){
	std::string formatFloatTaskResults = "";
	int formatingIndex;
	for(int i =0; i< taskList.size();i++){
		formatingIndex = getDisplayIndex()+1;
		formatFloatTaskResults += std::to_string(formatingIndex)+KEYWORD_DOT+KEYWORD_SPACE;
		if(std::to_string(taskList[i].getTimeAndDate().getStartTimeHour()).compare(TYPE_EMPTY)!=0){
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeHour())+KEYWORD_COLON;
			if(std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()).length() == 1){
				formatFloatTaskResults += TYPE_EMPTY+std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+KEYWORD_SPACE;
			} else {
				formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+KEYWORD_SPACE;
			}
		}
		if(std::to_string(taskList[i].getTimeAndDate().getStartMDay()).compare(TYPE_EMPTY)!=0){
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMDay())+KEYWORD_DATE_SEPARATOR;
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartMonth())+KEYWORD_DATE_SEPARATOR;
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartYear())+KEYWORD_SPACE;
		}
		formatFloatTaskResults += taskList[i].getTitle()+KEYWORD_SPACE;
		if(taskList[i].getLocation().compare("")!=0){
			formatFloatTaskResults += taskList[i].getLocation();
		}
		if(taskList[i].getIsDone()){
				formatFloatTaskResults+= KEYWORD_SPACE+KEYWORD_DONE;
		}
		if(taskList[i].getTaskType().compare(KEYWORD_DEADLINE)==0){
			formatFloatTaskResults+= KEYWORD_SPACE+KEYWORD_DUE;
		}
		formatFloatTaskResults+=KEYWORD_NEWLINE;
		setDisplayIndex(formatingIndex);
	}
	return formatFloatTaskResults;
}

//This operation formats the display results based on the paramter formatType - [main|float]
std::string taskDisplay::formatDisplayResults(std::vector<task> taskList, std::string formatType){
	std::string formatResults = "";
	if(formatType.compare(TYPE_TIMEDTASK)==0){
		formatResults= formatTimedTask(taskList,TYPE_DISPLAY);
	} if(formatType.compare(TYPE_ALLDAY)==0){
		formatResults= formatTimedTask(taskList,TYPE_VIEW);
	}else if(formatType.compare(TYPE_FLOATTASK)==0){
		formatResults = formatFloatTask(taskList);
	}
	return formatResults;
}

//This operation formats the search results
std::string taskDisplay::formatSearchResults(std::vector<task> searchList){
	std::string searchResults;
	std::vector<task> searchFloatResults;
	searchResults += TYPE_RESULTS+KEYWORD_NEWLINE;
	searchResults += formatTimedTask(sortTimedTaskList(searchList),TYPE_VIEW);
	searchFloatResults = sortFloatTaskList(searchList);
	if(searchFloatResults.size()>0){
		searchResults += KEYWORD_NEWLINE+KEYWORD_TO_DO_LIST+KEYWORD_NEWLINE;
		searchResults += formatFloatTask(searchFloatResults);
	}
	return searchResults;
}

//This operation returns current date- Day
std::string taskDisplay::getTodayDate(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	if(timeinfo->tm_mday==1 || timeinfo->tm_mday==21 || timeinfo->tm_mday==31){
		strftime(output,30,"%dst",timeinfo);
	}else if(timeinfo->tm_mday==2 || timeinfo->tm_mday==22){
		strftime(output,30,"%dnd",timeinfo);
	}else if(timeinfo->tm_mday==3 || timeinfo->tm_mday==23){
		strftime(output,30,"%drd",timeinfo);
	}else {
		strftime(output,30,"%dth",timeinfo);
	}
	return std::string(output);
}

//This operation returns current date- Month
std::string taskDisplay::getTodayDateMonth(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%m",timeinfo);
	return std::string(output);
}

//This operation returns current date- Month_Abbreviated eg. Apr, May
std::string taskDisplay::getTodayDateMonth_Abbreviated(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%b",timeinfo);
	return std::string(output);
}

//This operation returns current date- Year
std::string taskDisplay::getTodayDateYear(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%Y",timeinfo);
	return std::string(output);
}

//This operation returns current date- Day Month Year
std::string taskDisplay::getTodayDateDMY(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
	return std::string(output);
}

//This operation returns next date- Day
std::string taskDisplay::getNextDayDate(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	if(timeinfo->tm_mday==1 || timeinfo->tm_mday==21 || timeinfo->tm_mday==31){
		strftime(output,30,"%dst",timeinfo);
	}else if(timeinfo->tm_mday==2 || timeinfo->tm_mday==22){
		strftime(output,30,"%dnd",timeinfo);
	}else if(timeinfo->tm_mday==3 || timeinfo->tm_mday==23){
		strftime(output,30,"%drd",timeinfo);
	}else {
		strftime(output,30,"%dth",timeinfo);
	}
	return std::string(output);
}

//This operation returns next date- Month
std::string taskDisplay::getNextDayDateMonth(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%m",timeinfo);
	return std::string(output);
}

//This operation returns next date- Month_Abbreviated eg. Apr, May
std::string taskDisplay::getNextDayDateMonth_Abbreviated(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%b",timeinfo);
	return std::string(output);
}

//This operation returns next date- Year
std::string taskDisplay::getNextDayDateYear(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%Y",timeinfo);
	return std::string(output);
}

//This operation returns next date- Day Month Year
std::string taskDisplay::getNextDayDateDMY(int flipCount){
	time_t timev;
	struct tm * timeinfo;
	time(&timev);
	if(flipCount !=0){
		timev += flipCount * 24 * 60 * 60;
	}
	timev += 1 * 24 * 60 * 60;
	timeinfo = localtime(&timev);
	char output[30];
	strftime(output,30,"%d/%m/%y",timeinfo);
	return std::string(output);
}

//This operation search the all existing data OLDER THAN the search Item input
std::string taskDisplay::searchPower(std::string searchItem){
	std::string searchResults;
	std::string searchBuffer; 
	std::stringstream ss(searchItem);
	std::vector<task> searchList;
	std::vector<task> tempSearchList;
	std::vector<std::string> searchItems; 
	while (ss >> searchBuffer){
		std::transform(searchBuffer.begin(), searchBuffer.end(), searchBuffer.begin(), ::tolower);
		searchItems.push_back(searchBuffer);
	}
	for(int i=0; i<searchItems.size();i++){
		tempSearchList= searchExact(searchItems[i]);
		for(int j=0; j<tempSearchList.size();j++){
			if(!checkSameTask(tempSearchList[j],searchList)){
				searchList.push_back(tempSearchList[j]);
			}
		}
	}
	searchResults = formatSearchResults(searchList);
	return searchResults;
}
bool taskDisplay::checkSameTask(task tempSearchItem , std::vector<task> currenetSearchList){
	bool isSame = false;
	for(int i =0; i <currenetSearchList.size();i++){
		if(currenetSearchList[i].getCommandAction()==tempSearchItem.getCommandAction() &&
			currenetSearchList[i].getIsClash()==tempSearchItem.getIsClash() &&
			currenetSearchList[i].getIsDone()==tempSearchItem.getIsDone() &&
			currenetSearchList[i].getLocation()==tempSearchItem.getLocation() &&
			currenetSearchList[i].getTaskType()==tempSearchItem.getTaskType() &&
			currenetSearchList[i].getTimeAndDate().getStartMDay()==tempSearchItem.getTimeAndDate().getStartMDay() &&
			currenetSearchList[i].getTimeAndDate().getStartMonth()==tempSearchItem.getTimeAndDate().getStartMonth() &&
			currenetSearchList[i].getTimeAndDate().getStartYear()==tempSearchItem.getTimeAndDate().getStartYear() &&
			currenetSearchList[i].getTitle()==tempSearchItem.getTitle()){
				isSame=true;
				break;
		}
	}
	return isSame;
}

//This operation search the all existing data OLDER THAN the search Item input
std::string taskDisplay::searchBefore(std::string searchItem){
	std::vector<task> allTaskList;
	std::vector<task> searchList;
	int searchResultsIndex=0;
	std::string searchResults;
	int searchDateYear = atoi(searchItem.substr(4).c_str());
	int searchDateMonth = atoi(searchItem.substr(2,2).c_str());
	int searchDateDay = atoi(searchItem.substr(0,2).c_str());
	int taskListYear;
	int taskListMonth;
	int taskListDay;
	if(_currentStorage.isFileEmpty()){
		searchItem ="";
		return searchItem;
	}
	allTaskList = _currentStorage.readFileJson();
	for(int i =0; i< allTaskList.size();i++){ //populate the the vector with revelant search results

		taskListDay = allTaskList[i].getTimeAndDate().getStartMDay();
		taskListMonth = allTaskList[i].getTimeAndDate().getStartMonth();
		taskListYear = allTaskList[i].getTimeAndDate().getStartYear();
		if(taskListYear!=0 && taskListYear< searchDateYear){
			searchList.push_back(allTaskList[i]);
		}else if(taskListYear!=0 && taskListYear == searchDateYear){
			if(taskListYear!=0 && taskListMonth<searchDateMonth){
				searchList.push_back(allTaskList[i]);
			}else if(taskListYear!=0 && taskListMonth==searchDateMonth){
				if(taskListYear!=0 && taskListDay<searchDateDay){
					searchList.push_back(allTaskList[i]);
				}
			}
		}
	}
		searchResults = formatSearchResults(searchList);
		return searchResults;	
}


//This operation search the all existing data OLDER THAN the search Item input
std::string taskDisplay::searchAfter(std::string searchItem){
	std::vector<task> allTaskList;
	std::vector<task> searchList;
	int searchResultsIndex=0;
	std::string searchResults;
	int searchDateYear = atoi(searchItem.substr(4).c_str());
	int searchDateMonth = atoi(searchItem.substr(2,2).c_str());
	int searchDateDay = atoi(searchItem.substr(0,2).c_str());
	int taskListYear;
	int taskListMonth;
	int taskListDay;
	if(_currentStorage.isFileEmpty()){
		searchItem ="";
		return searchItem;
	}
	allTaskList = _currentStorage.readFileJson();
	for(int i =0; i< allTaskList.size();i++){ //populate the the vector with revelant search results

		taskListDay = allTaskList[i].getTimeAndDate().getStartMDay();
		taskListMonth = allTaskList[i].getTimeAndDate().getStartMonth();
		taskListYear = allTaskList[i].getTimeAndDate().getStartYear();
		if(taskListYear> searchDateYear){
			searchList.push_back(allTaskList[i]);
		}else if(taskListYear==searchDateYear){
			if(taskListMonth>searchDateMonth){
				searchList.push_back(allTaskList[i]);
			}else if(taskListMonth==searchDateMonth){
				if(taskListDay>searchDateDay){
					searchList.push_back(allTaskList[i]);
				}
			}
		}
	}
		searchResults = formatSearchResults(searchList);
		return searchResults;
}
//This operation search the all existing data w.r.t. the search Item input
std::vector<task> taskDisplay::searchExact(std::string searchItem){
	bool isExact = false;
	std::vector<task> allTaskList;
	std::vector<task> allTaskListLower;
	std::vector<task> searchList;
	char chars[] = "\"";
	int searchResultsIndex=0;
	std::string searchResults; 
	std::string tempLowerStr;
	if(_currentStorage.isFileEmpty()){
		searchItem ="";
		return searchList;
	}
	if(searchItem[0] =='"'){
		isExact = true;
		searchItem.erase (std::remove(searchItem.begin(), searchItem.end(), chars[0]), searchItem.end());
	}
	allTaskList = _currentStorage.readFileJson();
	allTaskListLower = allTaskList;
	//Transform to lower case
	for(int i =0; i < allTaskList.size(); i++){
		tempLowerStr = allTaskList[i].getLocation();
		std::transform(tempLowerStr.begin(), tempLowerStr.end(), tempLowerStr.begin(), ::tolower);
		allTaskListLower[i].setLocation(tempLowerStr);
		tempLowerStr = allTaskList[i].getTitle();
		std::transform(tempLowerStr.begin(), tempLowerStr.end(), tempLowerStr.begin(), ::tolower);
		allTaskListLower[i].setTitle(tempLowerStr);
	}

	for(int i =0; i< allTaskListLower.size();i++){ //populate the the vector with revelant search results
		std::string tempTitle = allTaskListLower[i].getTitle();
		std::string tempLocation = allTaskListLower[i].getLocation();
		int tempDay = allTaskListLower[i].getTimeAndDate().getStartMDay();
		int tempMonth = allTaskListLower[i].getTimeAndDate().getStartMonth();
		int tempYear = allTaskListLower[i].getTimeAndDate().getStartYear();
		if(!isExact){
			if(tempTitle.find(searchItem) != std::string::npos || 
				tempLocation.find(searchItem) != std::string::npos || 
				std::to_string(tempDay).find(searchItem) != std::string::npos || 
				std::to_string(tempMonth).find(searchItem) != std::string::npos || 
				std::to_string(tempYear).find(searchItem) != std::string::npos){
					searchList.push_back(allTaskList[i]);
			}
		} else {
			if(tempTitle.compare(searchItem) ==0 || 
				tempLocation.compare(searchItem) ==0|| 
				std::to_string(tempDay).compare(searchItem) ==0 || 
				std::to_string(tempMonth).compare(searchItem) ==0 || 
				std::to_string(tempYear).compare(searchItem) ==0){
					searchList.push_back(allTaskList[i]);
			}
		}
	}
	return searchList;
}


//This operation helps to render UI display results in Calendified View
int taskDisplay::configureCalendifedView(std::string logicResult, int flipCount){
	int pos;
	if(logicResult.substr(0,5).compare(TYPE_ADD)==0){ //check for add operation
		pos = -1;
	} else if(logicResult.substr(0,7).compare(TYPE_DELETED)==0){ //check for delete operation
		pos = -1;
	} else if(logicResult.substr(0,7).compare(TYPE_EDITED)==0){ //check for edit operation
		pos = -1;
	} else if(logicResult.substr(0,8).compare(TYPE_TOGGLED)==0){ //check for edit operation
		pos = -1;
	} else if(logicResult.substr(0,8).compare(TYPE_RESULTS)==0){ //check for view operation
		pos = logicResult.find(KEYWORD_TO_DO_LIST);
		pos = logicResult.length();
	}else {
		pos = logicResult.find(getNextDayDate(flipCount)); //check for display operation
	}
	return pos;
}

//This operation helps to render UI display results in List View
std::string taskDisplay::configureListView(std::string logicResult){
	return logicResult;
}