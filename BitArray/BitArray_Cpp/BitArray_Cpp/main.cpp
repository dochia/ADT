#include <stdio.h>
#include "BitArray.h"
#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
	BitArray b = BitArray(2);
	b.print();
	b.add(2);
	b.print();
	b.add(4);
	b.print();
	b.remove(2);
	b.print();
	b.remove(10);
	b.print();
	b.remove(3);
	b.print();
}
