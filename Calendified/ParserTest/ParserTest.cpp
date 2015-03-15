
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ParserTest
{		
	TEST_CLASS(ParserTest)
	{
	public:

		//author @a0114411b
		TEST_METHOD(ParserTest_ReadCommand)
		{
			std::string inputCommandString = 
				"commandType &title $13:00 %11/11/2011 @location #description";
			std::string expectedCommandType = "commandType";
			std::string expectedCommandTitle = "title";
			std::string expectedCommandTime = "13:00";
			std::string expectedCommandDate = "11/11/2011";
			std::string expectedCommandLocation = "location";
			std::string expectedCommandDescription = "description";

			parser newParser;
			Assert::AreEqual(expectedCommandType, newParser.getItemsInString(inputCommandString,NULL));
			Assert::AreEqual(expectedCommandTitle, newParser.getItemsInString(inputCommandString,'&'));
			Assert::AreEqual(expectedCommandTime, newParser.getItemsInString(inputCommandString,'$'));
			Assert::AreEqual(expectedCommandDate, newParser.getItemsInString(inputCommandString,'%'));
			Assert::AreEqual(expectedCommandLocation, newParser.getItemsInString(inputCommandString,'@'));
			Assert::AreEqual(expectedCommandDescription, newParser.getItemsInString(inputCommandString,'#'));
		}

	};
}