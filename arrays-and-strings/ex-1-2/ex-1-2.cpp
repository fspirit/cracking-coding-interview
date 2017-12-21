#include <cmath>
#include <string>
#include <iostream>

const char* reverse(const char * str)
{
	std::string s(str);
	int halflen = floor(s.size() / 2.0);

	for (int i = 0; i < halflen; i++)
	{
		char temp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = temp;
	}

	return s.c_str();
}

int main()
{
	const char * str = "qwePrty";
	std::cout << str << std::endl;
	std::cout << reverse(str) << std::endl;

	return 0;
}

