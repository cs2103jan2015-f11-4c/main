//@author A0116027R
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandTestAdd
{		
	TEST_CLASS(CommandTestAdd)
	{
	public:
		taskAdd testTaskAdd;

		TEST_METHOD(CommandTestAdd_taskAddTask)
		{
			std::string expectedResult = "Added succesfully!";
			std::string fail = "Task not added. Please try again.";
			std::string testTaskTypeM = "main";
			std::string testTaskTypeF = "float"; 
			std::string testStringM = "13/03/2015 13:00 visit school @utown";
			std::string testStringF = "visit school";

			//commented by feng		testTaskAdd.setTask(testStringM); 
			//commented by feng		testTaskAdd.setTaskType(testTaskTypeM);
			std::string actualResult1 = testTaskAdd.taskAddTask();
			Assert::AreEqual(fail, actualResult1); //storage cannnot find filepath
			//test case 1
			//commented by feng		testTaskAdd.setTask(testStringF);
			//commented by feng		testTaskAdd.setTaskType(testTaskTypeF);
			std::string actualResult2 = testTaskAdd.taskAddTask();
			Assert::AreEqual(fail, actualResult2); //storage cannot find filepath
			//test case 2

		}

	};
}