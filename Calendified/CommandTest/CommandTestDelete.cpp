#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandTestDelete
{		
	TEST_CLASS(CommandTestDelete)
	{
	public:
		taskDelete testTaskDelete;
		TEST_METHOD(CommandTestDelete_successInvalidIndex)
		{
			// Boundary Testing
			// Assumption : File is not empty.
			Assert::AreEqual(MESSAGE_ERROR_INVALID_INDEX, testTaskDelete.executeDelete(-1));
			
			Assert::AreEqual(MESSAGE_ERROR_INVALID_INDEX, testTaskDelete.executeDelete(0));
			// Assuming file size would not exceed 10000
			Assert::AreEqual(MESSAGE_ERROR_INVALID_INDEX, testTaskDelete.executeDelete(10000));


		}

	};
}