#include <string>
#include <iostream>

void replaceSpace(std::string& s, std::string& r)
{
	int move = r.size() - 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			for (int j = s.size() - 1; j > i + move; j--)
				s[j] = s[j - move];
			for (int k = 0; k < r.size(); k++)
				s[i + k] = r[k];
		}
		// std::cout << s << std::endl;
	}

}

int main()
{
	std::string s = "Mr John Smith    ";
	std::string r = "%20";
	std::cout << s << std::endl;

	replaceSpace(s, r);
	std::cout << s << std::endl;

	return 0;
}