#include <iostream>

int NumberOfBitsToFlip(int n, int m)
{
	int diff = n ^ m;
	int count = 0;
	for (int i = 0; i < sizeof(diff); i ++)
	{
		if ((diff & (1 << i)) != 0)
			count++;
	}

	return count;
}

int main(int argc, char const *argv[])
{
	std::cout << NumberOfBitsToFlip(3, 1) << std::endl;
	std::cout << NumberOfBitsToFlip(4, 3) << std::endl;

	return 0;
}