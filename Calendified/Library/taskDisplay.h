//author A0125489U

#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include "logic.h"
#include "storage.h"

const std::string TYPE_TIMEDTASK =
	"timed!";

const std::string TYPE_FLOATTASK = 
	"float";

const std::string TYPE_TODAY =
	"today";

const std::string TYPE_NEXTDAY =
	"nextDay";

const std::string TYPE_ALLDAY =
	"allDay";

const std::string TYPE_ADD =
	"Added";

const std::string TYPE_DELETED = 
	"Deleted";

const std::string TYPE_EDITED =
	"Edited.";

const std::string TYPE_TOGGLED =
	"Toggled!";

const std::string TYPE_RESULTS =
	"Results:";

const std::string TYPE_EMPTY =
	"0";

const std::string TYPE_DATE_EMPTY =
	"-1";

const std::string TYPE_DISPLAY =
	"display";

const std::string TYPE_VIEW =
	"view";

const std::string TYPE_FLOAT =
	"FLOAT";

const std::string KEYWORD_NEWLINE =
	"\n";

const std::string KEYWORD_DATE_SEPARATOR =
	"/";

const std::string KEYWORD_SPACE =
	" ";

const std::string KEYWORD_COLON =
	":";

const std::string KEYWORD_DOT =
	".";

const std::string KEYWORD_AT =
	"@";

const std::string KEYWORD_TILDE =
	"~";

const std::string KEYWORD_DONE =
	"[DONE]";

const std::string KEYWORD_DUE =
	"[DUE]";

const std::string KEYWORD_DEADLINE =
	"DeadLine";

const std::string KEYWORD_TO_DO_LIST =
	"To-Do List";

const char KEYWORD_EMPTY_CHAR =
	'0';



class taskDisplay
{
private:
	storage _currentStorage;
	std::vector<task> _displayContent;
	int _displayIndex;
public:
	taskDisplay();
	taskDisplay(storage currentStorage);
	~taskDisplay(void);
	std::string taskAddTask();
	void taskAddRecurrent();
	void setTask(std::string taskString);
	void setTaskType(std::string taskType);
	std::string getTodayDate(int flipCount);
	std::string getTodayDateMonth(int flipCount);
	std::string getTodayDateMonth_Abbreviated(int flipCount);
	std::string getTodayDateYear(int flipCount);
	std::string getTodayDateDMY(int flipCount);
	std::string getNextDayDate(int flipCount);
	std::string getNextDayDateMonth(int flipCount);
	std::string getNextDayDateMonth_Abbreviated(int flipCount);
	std::string getNextDayDateYear(int flipCount);
	std::string getNextDayDateDMY(int flipCount);
	std::string displayToday(int flipCount);
	std::string displayNextDay(int flipCount);
	std::string displayFloatDay(int flipCount);
	std::string displayAll(int flipCount);
	int configureCalendifedView(std::string logicResult, int flipCount);
	std::string configureListView(std::string logicResult);
	std::string formatDisplayResults(std::vector<task> taskList, std::string formatType);
	std::string formatTimedTask(std::vector<task> taskList, std::string presentationType);
	std::string formatFloatTask(std::vector<task> taskList);
	std::string formatSearchResults(std::vector<task> searchList);
	std::vector<task> sortTaskList(std::string sortType, int flipCount);
	std::vector<task> sortTimedTaskList(std::vector<task> givenTaskList);
	std::vector<task> sortFloatTaskList(std::vector<task> givenTaskList);
	std::vector<task> searchExact(std::string searchItem);
	std::string searchAfter(std::string searchItem);
	std::string searchBefore(std::string searchItem);
	std::string searchPower(std::string searchItem);
	bool taskDisplay::checkSameTask(task tempSearchItem , std::vector<task> currenetSearchList);
	void updateDisplayContent(std::vector<task> newDisplayContent);
	std::vector<task> getDisplayContent();
	void setDisplayContent(std::vector<task> newDisplayContent);
	int getStorageIndex(std::vector<task> currentDisplayContent, int selectedIndex);
	void setDisplayIndex(int newDisplayIndex);
	int getDisplayIndex();
	void updateStorageSource();
};

#endif