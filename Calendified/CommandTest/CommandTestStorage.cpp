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
			std::vector<std::string> inputVector;
			inputVector.push_back("ccc"); 
			inputVector.push_back("bbb"); 
			inputVector.push_back("aaa"); 
			inputVector.push_back("333"); 
			inputVector.push_back("222"); 
			inputVector.push_back("111"); 
			inputVector.push_back("CCC"); 
			inputVector.push_back("BBB"); 
			inputVector.push_back("AAA");

			inputVector = testStorageSort.sortData(inputVector);
			std::ostringstream oss;
			for(int i=0; i < inputVector.size(); i++){
				oss << inputVector[i] << "\n";
			}
			std::string inputString = oss.str();

			std::vector<std::string> expectedVector;
			expectedVector.push_back("111"); 
			expectedVector.push_back("222"); 
			expectedVector.push_back("333"); 
			expectedVector.push_back("AAA");
			expectedVector.push_back("BBB"); 
			expectedVector.push_back("CCC"); 
			expectedVector.push_back("aaa");
			expectedVector.push_back("bbb"); 
			expectedVector.push_back("ccc");

			std::ostringstream os;
			for(int i=0; i < expectedVector.size(); i++){
				os << expectedVector[i] << "\n";
			}
			std::string expectedString = os.str();

			Assert::AreEqual(expectedString,inputString);
		}

	};
}