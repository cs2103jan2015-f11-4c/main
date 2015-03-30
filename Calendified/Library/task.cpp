/*#include "task.h"

task::task(std::string timeString, std::string dateString, std::string title, std::string location, std::string descripion, int indexToBeAction)
{
	_title = title;
	_location = location;
	_descripion = descripion;

	time newTime;
	startTime = newTime.getStartTime(timeString);
	endTime = newTime.getEndTime(dateString);
	_indexToBeAction = indexToBeAction;
}


task::~task(void)
{
}

void task::setTaskType(taskType taskType){
	_taskType = taskType;
}

bool task::isOverlap(time t){
	return t.compare(t);
}
*/