#pragma once
#include <set>
#include <limits.h>
#include <string>

using namespace std;

class BitArray
{
private:
	int bit_array_size;
	unsigned int* bit_arr;
	int capacity;
	void initialize_bit_array();
	int countSetBits(int n);

public:
	BitArray(int size);
	BitArray(set<int> newValues);
	~BitArray();
	
	void add(int value); 
	bool remove(int value);
	
	string print();
	
	int getCapacity();
	int getCount();

	bool isPresent(int position);
};

