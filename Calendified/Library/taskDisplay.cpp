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
			currentDisplayContent[selectedIndex].getTimeAndDate().getMDay()==allTaskList[i].getTimeAndDate().getMDay() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getMonth()==allTaskList[i].getTimeAndDate().getMonth() &&
			currentDisplayContent[selectedIndex].getTimeAndDate().getYear()==allTaskList[i].getTimeAndDate().getYear() &&
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
		if(givenTaskList[i].getTimeAndDate().getMDay() == 0 || 
			givenTaskList[i].getTimeAndDate().getMonth() == 0 || 
			givenTaskList[i].getTimeAndDate().getYear() == 0 || 
			givenTaskList[i].getTimeAndDate().getStartTimeHour() == 0){
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
		if(givenTaskList[i].getTimeAndDate().getMDay() != 0 && 
			givenTaskList[i].getTimeAndDate().getMonth() != 0 & 
			givenTaskList[i].getTimeAndDate().getYear() != 0 & 
			givenTaskList[i].getTimeAndDate().getStartTimeHour() != 0){
				taskList.push_back(givenTaskList[i]);
		}
	}
	updateDisplayContent(taskList);
	return taskList;
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
	std::string dateTime=TYPE_EMPTY;

	if(_currentStorage.isFileEmpty()){
		return taskList;
	}
	std::vector<task> allTaskList = _currentStorage.readFileJson();
	if(sortType.compare(TYPE_FLOATTASK)==0){ //check if taskList is {float List}
		for(int i =0;i < allTaskList.size();i++){
			if(allTaskList[i].getTimeAndDate().getMDay() == 0 || 
				allTaskList[i].getTimeAndDate().getMonth() == 0 || 
				allTaskList[i].getTimeAndDate().getYear() == 0 || 
				allTaskList[i].getTimeAndDate().getStartTimeHour() == 0){
					taskList.push_back(allTaskList[i]);
			}
		}
		updateDisplayContent(taskList);
		return taskList;
	} else if(sortType.compare(TYPE_TODAY)==0){ //check if taskList is {today List}
		dateDay = getTodayDate();
		dateMonth = getTodayDateMonth();
		dateYear = getTodayDateYear();
	} else if(sortType.compare(TYPE_NEXTDAY)==0){ //check if taskList is {nextDay List}
		dateDay = getNextDayDate();
		dateMonth = getNextDayDateMonth();
		dateYear = getNextDayDateYear();
	}
	dateDay = dateDay.substr(0,2);
	if(dateDay[0] ==KEYWORD_EMPTY_CHAR){
		dateDay = dateDay[1];
	}
	if(dateMonth[0] ==KEYWORD_EMPTY_CHAR){
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
	updateDisplayContent(taskList);
	return taskList;
}
//
std::string taskDisplay::displayToday(){
	std::string displayTodayResults = getTodayDate()+KEYWORD_NEWLINE;
	std::vector<task> todayTaskList = sortTaskList(TYPE_TODAY);
	if(!todayTaskList.size()==0){
		displayTodayResults += formatDisplayResults(todayTaskList,TYPE_TIMEDTASK);
	}
	return displayTodayResults;
}

//
std::string taskDisplay::displayNextDay(){
	std::string displayNextDayResults = getNextDayDate()+KEYWORD_NEWLINE;
	std::vector<task> nextDayTaskList = sortTaskList(TYPE_NEXTDAY);
	if(!nextDayTaskList.size()==0){
		displayNextDayResults += formatDisplayResults(nextDayTaskList,TYPE_TIMEDTASK);
	}
	return displayNextDayResults;
}

//
std::string taskDisplay::displayFloatDay(){
	std::string displayFloatResults= KEYWORD_NEWLINE;
	std::vector<task> floatTaskList = sortTaskList(TYPE_FLOATTASK);
	if(!floatTaskList.size()==0){
		displayFloatResults += formatDisplayResults(floatTaskList,TYPE_FLOATTASK);
	}
	return displayFloatResults;
}

std::string taskDisplay::formatTimedTask(std::vector<task> taskList, std::string presentationType){
	std::string formatTimeTaskResults = "";
	int formatingIndex;
	for(int i =0; i< taskList.size();i++){
		formatingIndex = getDisplayIndex()+1;
			formatTimeTaskResults += std::to_string(formatingIndex)+KEYWORD_DOT+KEYWORD_SPACE;
			if(presentationType.compare(TYPE_VIEW)==0){
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getMDay())+KEYWORD_DATE_SEPARATOR;
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getMonth())+KEYWORD_DATE_SEPARATOR;
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getYear())+KEYWORD_SPACE;
			}
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeHour())+KEYWORD_COLON;
			if(std::to_string(taskList[i].getTimeAndDate().getStartTimeMin()).length() == 1){
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+TYPE_EMPTY+KEYWORD_SPACE;
			} else {
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+KEYWORD_SPACE;
			}
			formatTimeTaskResults += KEYWORD_TILDE+KEYWORD_SPACE;
			formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getEndTimeHour())+KEYWORD_COLON;
			if(std::to_string(taskList[i].getTimeAndDate().getEndTimeMin()).length() == 1){
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getEndTimeMin())+TYPE_EMPTY+KEYWORD_SPACE;
			} else {
				formatTimeTaskResults += std::to_string(taskList[i].getTimeAndDate().getEndTimeMin())+KEYWORD_SPACE;
			}
			formatTimeTaskResults += taskList[i].getTitle()+KEYWORD_SPACE;
			if(taskList[i].getLocation().compare("")!=0){
				formatTimeTaskResults += KEYWORD_AT+taskList[i].getLocation();
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
				formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+TYPE_EMPTY+KEYWORD_SPACE;
			} else {
				formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getStartTimeMin())+KEYWORD_SPACE;
			}
		}
		if(std::to_string(taskList[i].getTimeAndDate().getMDay()).compare(TYPE_EMPTY)!=0){
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getMDay())+KEYWORD_DATE_SEPARATOR;
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getMonth())+KEYWORD_DATE_SEPARATOR;
			formatFloatTaskResults += std::to_string(taskList[i].getTimeAndDate().getYear())+KEYWORD_SPACE;
		}
		formatFloatTaskResults += taskList[i].getTitle()+KEYWORD_SPACE;
		if(taskList[i].getLocation().compare("")!=0){
			formatFloatTaskResults += KEYWORD_AT+taskList[i].getLocation();
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
	} else if(formatType.compare(TYPE_FLOATTASK)==0){
		formatResults = formatFloatTask(taskList);
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
	std::vector<task> allTaskList;
	std::vector<task> searchList;
	int searchResultsIndex=0;
	std::string searchResults; 
	if(_currentStorage.isFileEmpty()){
		return searchItem;
	}
	allTaskList = _currentStorage.readFileJson();
	for(int i =0; i< allTaskList.size();i++){ //populate the the vector with revelant search results
		if(allTaskList[i].getTitle().find(searchItem) != std::string::npos || 
			allTaskList[i].getLocation().find(searchItem) != std::string::npos || 
			std::to_string(allTaskList[i].getTimeAndDate().getMDay()).find(searchItem) != std::string::npos || 
			std::to_string(allTaskList[i].getTimeAndDate().getMonth()).find(searchItem) != std::string::npos || 
			std::to_string(allTaskList[i].getTimeAndDate().getYear()).find(searchItem) != std::string::npos){
				searchList.push_back(allTaskList[i]);
			}
	}
	searchResults += TYPE_RESULTS+KEYWORD_NEWLINE;
	searchResults += formatTimedTask(sortTimedTaskList(searchList),TYPE_VIEW);
	searchResults += KEYWORD_NEWLINE+TYPE_FLOAT+KEYWORD_NEWLINE;
	searchResults += formatFloatTask(sortFloatTaskList(searchList));
	return searchResults;
}


//This operation helps to render UI display results in Calendified View
int taskDisplay::configureCalendifedView(std::string logicResult){
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
		pos = logicResult.find(TYPE_FLOAT);
	}else {
		pos = logicResult.find(getNextDayDate()); //check for display operation
	}
	return pos;
}

//This operation helps to render UI display results in List View
std::string taskDisplay::configureListView(std::string logicResult){
	return logicResult;
}