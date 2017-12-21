#include <string>
#include <algorithm>
#include <iostream>

bool hasDuplicates(std::string s)
{
	std::sort(s.begin(), s.end());
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i-1])
			return true;
	}
	return false;
}


int main()
{
	std::cout << hasDuplicates("adbkc") << std::endl;
	std::cout << hasDuplicates("fvbhuiioopp") << std::endl;

	return 0;
}