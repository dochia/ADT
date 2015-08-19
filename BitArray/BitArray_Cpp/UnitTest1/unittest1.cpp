#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitArray_Cpp\BitArray.h"
#include "BitArray_Cpp\BitArray.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCapacity_positive)
		{
			int size = 1;
			BitArray b = BitArray(size);
			Assert::IsTrue(b.getCapacity() == sizeof(unsigned int) * size, L"Wrong capacity", LINE_INFO());
		}
		
		TEST_METHOD(TestCapacity_negative)
		{
			int size = 2;
			BitArray b = BitArray(size);
			Assert::IsFalse(1 * sizeof(int) == b.getCapacity(), L"Wrong capacity", LINE_INFO());
		}

		TEST_METHOD(TestCount_positive)
		{
			int size = 2;
			BitArray b = BitArray(size);
			b.add(7);
			b.add(3);
			Assert::IsTrue(b.getCount() == 2, L"Wrong number of bits set", LINE_INFO());
		}

		TEST_METHOD(TestCount_negative)
		{
			int size = 1;
			BitArray b = BitArray(size);
			b.add(0);
			b.add(1);
			Assert::IsFalse(b.getCount() == 1, L"Wrong number of bits set", LINE_INFO());
		}
		
		TEST_METHOD(TestAdd_positive)
		{
			int size = 1;
			BitArray b = BitArray(size);
			b.add(0);
			Assert::IsTrue(b.isPresent(0), L"Value 0 is not set", LINE_INFO());
		}
		
		TEST_METHOD(TestAdd_negative)
		{
			int size = 1;
			BitArray b = BitArray(size);
			b.add(0);
			Assert::IsFalse(b.isPresent(3), L"Value 3 is set", LINE_INFO());
		}

		TEST_METHOD(TestDefaultCreation)
		{
			BitArray* b = new BitArray(1);
			Assert::IsNotNull(b, L"Object creation" , LINE_INFO());
			Assert::IsTrue(b->print() == "0 0 0 0 ", L"Object creation - initialization", LINE_INFO());
			
		}

		TEST_METHOD(TestIsPresent_positive)
		{
			BitArray b = BitArray({1, 3, 5, 6, 7, 9});
			Assert::IsTrue(b.isPresent(1), L"Bit 1 is set", LINE_INFO());
			Assert::IsTrue(b.isPresent(3), L"Bit 3 is set", LINE_INFO());
			Assert::IsTrue(b.isPresent(9), L"Bit 9 is set", LINE_INFO());
		}
		
		TEST_METHOD(TestIsPresent_negative)
		{
			BitArray b = BitArray({ 1, 3, 5, 6, 7, 9 });
			Assert::IsFalse(b.isPresent(0), L"Bit 0 is not set", LINE_INFO());
			Assert::IsFalse(b.isPresent(2), L"Bit 2 is not set", LINE_INFO());
			Assert::IsFalse(b.isPresent(10), L"Bit 10 is not set", LINE_INFO());
		}
	
		TEST_METHOD(TestPrint_positive)
		{
			BitArray b = BitArray({ 1, 2, 3, 4});
			b.add(5);
			Assert::IsTrue(b.print() == "0 1 1 1 1 1 0 0 ", L"Bit set print", LINE_INFO());
		}
		
		TEST_METHOD(TestPrint_negative)
		{
			BitArray b = BitArray({ 1, 2, 3, 4 });
			b.add(5);
			Assert::IsFalse(b.print() == "0 0 0 0 0 0 0 0 ", L"Bit set print", LINE_INFO());
		}
	};
}