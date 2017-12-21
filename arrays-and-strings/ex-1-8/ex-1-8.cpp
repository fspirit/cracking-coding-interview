#include <string>
#include <iostream>

bool isRotation(std::string s1, std::string s2)
{
	if (s1.size() != s2.size())
		return false;

	int k = -1;

	for (int i = 0; i < s1.size(); i++)
	{
		bool equals = true;
		int j = s2.size() - 1 - i;
		for (int n = 0; n <= i; n++)
		{
			if (s1[n] != s2[j++])
			{
				equals = false;
				break;
			}
		}
		if (equals == true)
			k = i;
	}

	std::cout << k << std::endl;

	if (k == -1)
		return false;
	if (k == s1.size() - 1)
		return true;

	std::string t1(s1.begin() + k + 1, s1.end());
	std::string t2(s2.begin(), s2.end() - 1 - k);

	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;

	return t1.compare(t2) == 0;
}

int main()
{
	std::string s1("waterbottle");
	std::string s2("erbottlewat");

	std::cout << isRotation(s1, s2) << std::endl;

	return 0;
}