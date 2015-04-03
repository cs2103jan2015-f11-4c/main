#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandTestIntegration
{		
	TEST_CLASS(CommandTestIntegration)
	{
	public:
		taskAdd addTask;
		taskDelete deleteTask;
		taskDisplay displayTask;
		taskEdit editTask;
		storage newStorage;
		logic newLogic;
		task newTask;

		//@author A0125489U
		//Top Down Approach
		TEST_METHOD(CommandTestIntegration_TopDownApproach) 
		{
			newStorage.saveInformation("test.txt");
			//UI Interface - Assuming user input "display" as input command
			std::string inputCommand = "display";
			
			//Parser test initialization with "display" as input command using commandRef object
			parser newParser(inputCommand);
			commandRef expectedCommandRef;
			expectedCommandRef.setCommandAction(inputCommand);
			std::string expectedCommandAction = expectedCommandRef.getCommandAction();
			std::string actualCommandAction = newParser.getTaskCommand();
			Assert::AreEqual(expectedCommandAction,actualCommandAction);

			//Task test to ensure accurate passing of data from commandRef object
			newTask.setCommandAction(newParser.getTaskCommand());
			std::string expectedTaskCommandAction = "display";
			std::string actualTaskCommandAction = newTask.getCommandAction();
			Assert::AreEqual(expectedTaskCommandAction,actualTaskCommandAction);
			
			//commandType test to identify the expected commandType DISPLAY
			commandType expectedCommandType = DISPLAY;
			std::string expectedCommandTypeString = expectedCommandAction.c_str();
			commandType actualCommandType = newLogic.hashCommandAction(newParser.getTaskCommand());
			std::string actualCommandTypeString;
			if(actualCommandType == DISPLAY){
				actualCommandTypeString="display";
			}
			Assert::AreEqual(expectedCommandTypeString,actualCommandTypeString);
			
			
			//timeAndDate test to initialize and test for a single attribute startimeHour
			int expectedTD__startTimeHour = -1;
			timeAndDate actualTD(newParser.getCommandRef().getDate(),newParser.getCommandRef().getTime());
			int actualTD__startTimeHour = actualTD.getStartTimeHour();
			Assert::AreEqual(expectedTD__startTimeHour,actualTD__startTimeHour);

			//Storage test for file reading - Assuming file is empty
			std::vector<task> expectedReadFileResult;
			int expectedSize = expectedReadFileResult.size();
			std::vector<task> actualReadFileResult = newStorage.readFileJson();
			int actualSize = actualReadFileResult.size();
			Assert::AreEqual(expectedSize,actualSize);

			//Display test empty results - Assuming Storage file is empty
			std::string expectedDisplayResult = displayTask.getTodayDate()+KEYWORD_NEWLINE;
			std::string actualDisplayResult = displayTask.displayToday();
			Assert::AreEqual(expectedDisplayResult, actualDisplayResult);

			//Logic test to ensure accurate results passed back to UI interface
			std::string expectedResultsToUI = displayTask.getTodayDate()+KEYWORD_NEWLINE+KEYWORD_NEWLINE+displayTask.getNextDayDate()+KEYWORD_NEWLINE+KEYWORD_NEWLINE+TYPE_FLOAT+KEYWORD_NEWLINE;
			std::string actualResultsToUI = newLogic.readCommand(inputCommand);
			Assert::AreEqual(expectedResultsToUI,actualResultsToUI);
		}
	};
}