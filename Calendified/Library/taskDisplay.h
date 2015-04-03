//author A0125489U
#ifndef TASKDISPLAY_H
#define TASKDISPLAY_H

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

const char KEYWORD_EMPTY_CHAR =
	'0';

class taskDisplay
{
private:
	storage currentStorage;

public:
	taskDisplay();
	taskDisplay(storage currentStorage);
	~taskDisplay(void);
	std::string taskAddTask();
	void taskAddRecurrent();
	void setTask(std::string taskString);
	void setTaskType(std::string taskType);
	std::string getTodayDate();
	std::string getTodayDateMonth();
	std::string getTodayDateYear();
	std::string getTodayDateDMY();
	std::string getNextDayDate();
	std::string getNextDayDateMonth();
	std::string getNextDayDateYear();
	std::string getNextDayDateDMY();
	std::string displayToday();
	std::string displayNextDay();
	std::string displayFloatDay();
	int configureCalendifedView(std::string logicResult);
	std::string configureListView(std::string logicResult);
	std::string formatDisplayResults(std::vector<task> taskList, std::string formatType);
	std::string formatTimedTask(std::vector<task> taskList, std::string presentationType);
	std::string formatFloatTask(std::vector<task> taskList);
	std::vector<task> sortTaskList(std::string sortType);
	std::vector<task> sortTimedTaskList(std::vector<task> givenTaskList);
	std::vector<task> sortFloatTaskList(std::vector<task> givenTaskList);
	std::string viewSearchList(std::string searchItem);
};

#endif