#include "bits.h"

#include <iostream>

int NextMin(int number)
{
	int result = number;
	bool zeroFlipped = false;
	for (int i = 0; i < sizeof(result); i++)
	{
		if (!GetBit(result, i) && !zeroFlipped)
		{
			result = SetBit(result, i);
			zeroFlipped = true;
			continue;
		}
		if (GetBit(result, i) && zeroFlipped)
		{
			result = ClearBit(result, i);
			break;
		}
	}
	return result;
}

int NextMax(int number)
{
	int result = number;
	bool oneFlipped = false;
	for (int i = 0; i < sizeof(result); i++)
	{
		if (GetBit(result, i) && !oneFlipped)
		{
			result = ClearBit(result, i);
			oneFlipped = true;
			continue;
		}
		if (!GetBit(result, i) && oneFlipped)
		{
			result = SetBit(result, i);
			break;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int number = 5;

	std::cout << NextMin(number) << std::endl;
	std::cout << NextMax(number) << std::endl;

	return 0;
}