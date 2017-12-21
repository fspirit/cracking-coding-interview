#include <string>
#include <algorithm>
#include <iostream>

bool isPermutation(std::string a, std::string b)
{
	if (a.size() != b.size())
		return false;

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}

	return true;
}

int main()
{
	auto a = "qwerty";
	auto b = "ytrewF";

	std::cout << isPermutation(a, b) << std::endl;

	return 0;
}