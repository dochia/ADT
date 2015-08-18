#pragma once
#include <set>
#include <limits.h>

using namespace std;

class BitArray
{
private:
	int bit_array_size;
	unsigned int* bit_arr;
	int capacity;
	void initialize_bit_array();

public:
	BitArray(int size);
	BitArray(set<int> newValues);
	~BitArray();
	void add(int value);
	void print();
	int getCapacity();
	bool remove(int value);
};

