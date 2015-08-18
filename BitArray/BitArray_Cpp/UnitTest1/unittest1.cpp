#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitArray.h"
#include "BitArray.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			int size = 1;
			BitArray b = BitArray(size);
			Assert::IsTrue(b.getCapacity() == sizeof(int) * size, L"Wrong capacity", LINE_INFO());
			Assert::AreEqual(1, 1);
		}

	};
}