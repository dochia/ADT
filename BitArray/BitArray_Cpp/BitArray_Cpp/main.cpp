#include <stdio.h>
#include "BitArray.h"
#include <iostream>

using namespace std;

void testBitArray()
{
	BitArray b = BitArray(2);
	b.print();
	b.add(2);
	cout << b.print() << "\n";
	b.add(4);
	cout << b.print() << "\n";
	b.remove(2);
	cout << b.print() << "\n";
	b.remove(10);
	cout << b.print() << "\n";
	b.remove(3);
	cout << b.print() << "\n";
	cout << b.isPresent(4) << "\n";
	cout << b.isPresent(2) << "\n";
	b.add(1);
	cout << b.getCount() << "\n";
	cout << "here" + b.print() + "here" << "\n";
	cout << (b.print().compare("0 1 0 0 1 0 0 0")) << "\n";
}

void testBitArraySet()
{
	set<int> values = set<int>();
	values.insert(1);
	values.insert(3);
	values.insert(5);
	BitArray b = BitArray(values);
	cout << b.getCount() << "\n";
	cout << b.print() << "\n";
}

void testBitArraySet2()
{
	try
	{
		BitArray b = BitArray({ 1, 2, 3, 4 });
		b.add(5);
		cout << (b.print() == "0 1 1 1 1 1 0 0") << "\n";
		cout << b.print();
	}
	catch (out_of_range e)
	{
		cout << "An exception occurred. Exception " << e.what() << '\n';
	}
	
}

int main(int argc, const char* argv[])
{
	//testBitArray();
	//testBitArraySet();
	testBitArraySet2();
}
