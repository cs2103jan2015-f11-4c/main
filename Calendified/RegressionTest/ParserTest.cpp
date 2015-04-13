#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParserTest
{		
	TEST_CLASS(ParserTest)
	{
	public:

		//@author A0114411B
		TEST_METHOD(ParserTest_ReadCommand)
		{
			std::string inputCommandString = 
				"commandType &title $13:00 %11/11/2011 @location";
			std::string expectedCommandType = "commandType";
			std::string expectedCommandTitle = "title";
			std::string expectedCommandLocation = "location";

			parser newParser;
//			Assert::AreEqual(expectedCommandType, newParser.getItemsInString(inputCommandString,NULL));
//			Assert::AreEqual(expectedCommandTitle, newParser.getItemsInString(inputCommandString,'&'));
//			Assert::AreEqual(expectedCommandLocation, newParser.getItemsInString(inputCommandString,'@'));
		}

	};
}