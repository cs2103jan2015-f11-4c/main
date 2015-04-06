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
<<<<<<< HEAD
=======
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
			
//error causing, commented by feng			inputVector = testStorageSort.sortData(inputVector); 
			std::ostringstream oss;
			for(int i=0; i < inputVector.size(); i++){
				oss << inputVector[i] << "\n";
			}
			std::string inputString = oss.str();
>>>>>>> efa35a88759e8b70cbcfceb2e10fbb29faab7408


		}

	};
}