//@author A0114411B

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandTestStorage
{		
	TEST_CLASS(CommandTestStorage)
	{
	public:
		storageSort testStorageSort;

		TEST_METHOD(commandTestStorage_createfile)
		{
			// TODO: Your test code here
		}

		TEST_METHOD(CommandTestStorage_storageSort)
		{
			//Testing sort in days
			std::vector<task> inputVector;

			std::string dateString1 = "5/5/2015";
			std::string dateString2 = "4/5/2015";
			std::string timeStringConst = "16:00";

			timeAndDate newTimeAndDate1(dateString1,timeStringConst);
			timeAndDate newTimeAndDate2(dateString2,timeStringConst);
			task newTask1(TimedTask,"add",newTimeAndDate1,"","",false,false);
			task newTask2(TimedTask,"add",newTimeAndDate2,"","",false,false);
			
			inputVector.push_back(newTask1);
			inputVector.push_back(newTask2);


		}

	};
}