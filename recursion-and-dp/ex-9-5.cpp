#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> GetPermutations(std::string& s) {
	std::vector<std::string> result;

	if (s.size() == 1) {
		result.push_back(s);
		return result;
	}

	for (int i = 0; i < s.size(); i++) {
		std::string copy = s;
		copy.erase(i, 1);		
		auto permutations = GetPermutations(copy);
		for (auto& p: permutations) {			
			result.push_back(std::string(1, s[i]) + p);
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{
	std::string s {"abc"};
	auto ps = GetPermutations(s);
	for (auto p : ps) {
		std::cout << p << std::endl;
	}

	return 0;
}