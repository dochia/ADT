#include "BitArray.h"

BitArray::BitArray(set<int> newValues)
{	
	bool incomplete_bite = (*(newValues.crbegin()) + 1) % sizeof(int) != 0;
	bit_array_size = (*(newValues.crbegin()) + 1) / sizeof(int) + (incomplete_bite ? 1 : 0);
	bit_arr = new unsigned int[bit_array_size];
	capacity = bit_array_size * sizeof(int);
	initialize_bit_array();
	for (set<int>::iterator it = newValues.begin(); it != newValues.end(); it++)
	{
		add(*it);
	}
}

BitArray::BitArray(int size)
{
	bit_array_size = size;
	bit_arr = new unsigned int[bit_array_size];
	initialize_bit_array();
	capacity = bit_array_size * sizeof(int);
}

void BitArray::initialize_bit_array()
{
	for (int i = 0; i < bit_array_size; i++)
		*(bit_arr + i) = 0;
}

void BitArray::add(int value)
{
	if (value > capacity)
		throw out_of_range("Value larger than capacity");
	int location_bit = value / sizeof(int);
	int mask = sizeof(int) - value % sizeof(int);
	int shift = 1 << mask;
	*(bit_arr + location_bit) |= shift;
	int number = *(bit_arr + location_bit);
}

BitArray::~BitArray()
{
	delete(this->bit_arr);
}

string BitArray::print()
{
	string result = "";
	for (int i = 0; i < bit_array_size; i++)
	{
		int mask = 1 << sizeof(int);
		int number = *(bit_arr + i);
		for (int j = 0; j < sizeof(int); j++)
		{
			int aux = number & mask;
			//printf("%d ", aux == mask? 1 : 0);
			result.append(aux == mask ? "1 " : "0 ");
			mask = mask >> 1;
		}
	}
	//printf("\n");
	return result;
}

int BitArray::getCapacity()
{
	return this->capacity;
}

int BitArray::countSetBits(int n)
{
	int j;
	for (j = 0; n; j++)
	{
		n &= n - 1;
	}
	return j;
}

int BitArray::getCount()
{
	int result = 0;
	for (int i = 0; i < bit_array_size; i++)
	{
		int aux = *(bit_arr + i);
		result += countSetBits(aux);
	}
	return result;
}

bool BitArray::remove(int value)
{
	if (value > capacity)
	{
		printf("Value is larger than Bit Array Capacity. \n");
		return false;
	}
	else
	{
		int location_bit = value / sizeof(int);
		int mask = 1 << (sizeof(int) - value % sizeof(int));
		*(bit_arr + location_bit) &= ~mask;
		return true;
	}
}

bool BitArray::isPresent(int position)
{
	int mask = 1 << (sizeof(int) - position % sizeof(int));
	return  (*(bit_arr + position / sizeof(int)) & mask) == mask ;
}