#include <string>
#include <iostream>

std::string compress(std::string& s)
{
	std::string result = "";
	auto current = s[0];
	auto currentCount = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == current)
		{
			currentCount++;
		}
		else
		{
			result.append(1, current);
			result.append(std::to_string(currentCount));
			current = s[i];
			currentCount = 1;
		}
	}	
	result.append(1, current);
	result.append(std::to_string(currentCount));

	if (result.size() > s.size())
		return s;

	return result;
}

int main()
{
	std::string s = "aabccccaaa";

	std::cout << compress(s) << std::endl;

	return 0;
}

