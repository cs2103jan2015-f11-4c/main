#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TaskRefTest
{		
	TEST_CLASS(TaskRefTest)
	{
	public:
		taskRef testTaskRef;

		TEST_METHOD(TestRefTest_testTimeAndDate)
		{
			std::string	testTaskDate1 = "01/01/1900"; //boundary date case
			std::string	testTaskDate2 = "01/01/1899"; //boundary date case negative partition
			std::string	testTaskDate3 = "30/02/1900"; //invalid date case, overflows to 02/02/1900
			std::string testTaskTime1 = "00:00"; //boundary time case
			std::string testTaskTime2 = "23:59"; //boundary time case
			std::string testTaskTitle = "birthday party";
			std::string testTaskDescription = "lunch";
			std::string testTaskLocation = "town";

			testTaskRef.setTaskDate(testTaskDate1);
			testTaskRef.setTaskTime(testTaskTime1);
			testTaskRef.setTaskTitle(testTaskTitle);
			testTaskRef.setTaskDescription(testTaskDescription);
			testTaskRef.setTaskLocation(testTaskLocation);

			std::string expectedResult1 = "01/01/1900";
			std::string actualResult1 = testTaskRef.getTaskDateInString();
			Assert::AreEqual(expectedResult1, actualResult1);
			//test case 1


			

				
		}

	};
}