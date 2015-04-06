#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandTestDisplay
{		
	TEST_CLASS(CommandTestDisplay)
	{
	public:
		taskDisplay displayTask;

		TEST_METHOD(CommandTestDisplay_sortTaskList)
		{
			std::string sortType_float ="float";
			std::string sortType_today ="today";
			std::string sortType_nextDay ="nextDay";
			std::vector<task> emptyVector;
			int expectedSize = emptyVector.size();
			//testcase 1 empty storage file
			int flipCount;
			std::vector<task> actualResults = displayTask.sortTaskList(sortType_float,flipCount);
			int actualSize = actualResults.size();
			Assert::AreEqual(expectedSize, actualSize);	
		}

	};
}