#include <stdio.h>
#include "BitArray.h"
#include <iostream>

using namespace std;

void driverBitArray()
{
	try
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
		
		set<int> values = set<int>();
		values.insert(1);
		values.insert(3);
		values.insert(5);
		BitArray bA = BitArray(values);
		cout << bA.getCount() << "\n";
		cout << bA.print() << "\n";
	}
	catch (out_of_range e)
	{
		cout << "An exception occurred. Exception " << e.what() << '\n';
	}
}

int main(int argc, const char* argv[])
{
	driverBitArray();
}
