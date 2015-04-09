#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandTestDelete
{		
	TEST_CLASS(CommandTestDelete)
	{
	public:
		taskDelete testTaskDelete;

		TEST_METHOD(CommandTestDelete_ExecuteDelete)
		{
			taskDelete newTaskDelete;

			std::vector<task> inputVector;
			std::string inputString;
			bool isEmpty;
			isEmpty = newTaskDelete.isEmpty(inputVector);

			//Check if vector is an empty vector
			Assert::AreEqual(true,isEmpty);

			task newTask1;

			std::string inputDateString = "5/5/2015";
			std::string inputTimeString = "4pm-6pm";
			std::string inputTitle = "Practice floorball";
			std::string inputLocation = "MPSH 6";
			std::string commandAction = "add";
			bool isDone = false;
			bool isClash = false;

			timeAndDate newTimeAndDate(inputDateString,inputTimeString);

			newTask1.setTaskType(TimedTask);
			newTask1.setCommandAction(commandAction);
			newTask1.setTimeAndDate(newTimeAndDate);
			newTask1.setTitle(inputTitle);
			newTask1.setIsClash(isClash);
			newTask1.setIsDone(isDone);
			inputVector.push_back(newTask1);

			task newTask2;

			inputDateString = "7/5/2015";
			inputTimeString = "12pm-2pm";
			inputTitle = "Family Lunch!";
			inputLocation = "Pizza Hut";
			commandAction = "add";
			isDone = false;
			isClash = false;

			timeAndDate newTimeAndDate2(inputDateString,inputTimeString);

			newTask2.setTaskType(TimedTask);
			newTask2.setCommandAction(commandAction);
			newTask2.setTimeAndDate(newTimeAndDate2);
			newTask2.setTitle(inputTitle);
			newTask2.setIsClash(isClash);
			newTask2.setIsDone(isDone);
			inputVector.push_back(newTask2);

			task newTask3;

			inputDateString = "10/5/2015";
			inputTimeString = "8pm-10pm";
			inputTitle = "Catch up on korean drama!";
			inputLocation = "Home";
			commandAction = "add";
			isDone = false;
			isClash = false;

			timeAndDate newTimeAndDate3(inputDateString,inputTimeString);


			newTask3.setTaskType(TimedTask);
			newTask3.setCommandAction(commandAction);
			newTask3.setTimeAndDate(newTimeAndDate3);
			newTask3.setTitle(inputTitle);
			newTask3.setIsClash(isClash);
			newTask3.setIsDone(isDone);
			inputVector.push_back(newTask3);

			//Boundary Cases before any action
			//Checking on the validity of the indexToBeDeleted input
			Assert::AreEqual(true, newTaskDelete.isNotValidIndex(-1));
			Assert::AreEqual(false, newTaskDelete.isNotValidIndex(0));
			Assert::AreEqual(false, newTaskDelete.isNotValidIndex(1));

			std::vector<task> inputVector2;
			inputVector2 = newTaskDelete.performDeleteTask(inputVector,1);

			inputDateString = inputVector2[1].getTimeAndDate().getStartDateInString();
			inputTimeString = inputVector2[1].getTimeAndDate().getStartTimeInString();
			inputTitle = inputVector2[1].getTitle();
			inputLocation = inputVector2[1].getLocation();
			commandAction = inputVector2[1].getCommandAction();
			isDone = inputVector2[1].getIsDone();
			isClash = inputVector2[1].getIsClash();

			//Checking 2nd element of the new vector after removing the 2nd task of the old vector
			//Check -> newVector[2] == oldVector[3] (?)
			Assert::AreEqual(inputVector[2].getTimeAndDate().getStartDateInString(),inputDateString);
			Assert::AreEqual(inputVector[2].getTimeAndDate().getStartTimeInString(),inputTimeString);
			Assert::AreEqual(inputVector[2].getLocation(), inputLocation);
			Assert::AreEqual(inputVector[2].getTitle(), inputTitle);
			Assert::AreEqual(inputVector[2].getCommandAction(), commandAction);
			Assert::AreEqual(inputVector[2].getIsDone(), isDone);
			Assert::AreEqual(inputVector[2].getIsClash(), isClash);

			inputDateString = inputVector2[0].getTimeAndDate().getStartDateInString();
			inputTimeString = inputVector2[0].getTimeAndDate().getStartTimeInString();
			inputTitle = inputVector2[0].getTitle();
			inputLocation = inputVector2[0].getLocation();
			commandAction = inputVector2[0].getCommandAction();
			isDone = inputVector2[0].getIsDone();
			isClash = inputVector2[0].getIsClash();

			//Checking 1st element of the new vector after removing the 2nd task of the old vector
			//Check -> newVector[0] == oldVector[0] (?)
			//Hypothesis = Nothing changed.
			Assert::AreEqual(inputVector[0].getTimeAndDate().getStartDateInString(),inputDateString);
			Assert::AreEqual(inputVector[0].getTimeAndDate().getStartTimeInString(),inputTimeString);
			Assert::AreEqual(inputVector[0].getLocation(), inputLocation);
			Assert::AreEqual(inputVector[0].getTitle(), inputTitle);
			Assert::AreEqual(inputVector[0].getCommandAction(), commandAction);
			Assert::AreEqual(inputVector[0].getIsDone(), isDone);
			Assert::AreEqual(inputVector[0].getIsClash(), isClash);

		}
	};
}