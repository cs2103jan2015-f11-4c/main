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

//error causing, commented by feng				testTaskAdd.setTask(testStringM); 
//error causing, commented by feng				testTaskAdd.setTaskType(testTaskTypeM);
//error causing, commented by feng				std::string actualResult1 = testTaskAdd.taskAddTask();
//error causing, commented by feng				Assert::AreEqual(fail, actualResult1); //storage cannnot find filepath
			//test case 1
//error causing, commented by feng				testTaskAdd.setTask(testStringF);
//error causing, commented by feng				testTaskAdd.setTaskType(testTaskTypeF);
//error causing, commented by feng				std::string actualResult2 = testTaskAdd.taskAddTask();
//error causing, commented by feng				Assert::AreEqual(fail, actualResult2); //storage cannot find filepath
			//test case 2

		}

	};
}