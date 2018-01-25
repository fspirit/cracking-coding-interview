#include <iostream>
#include <set>
#include <string>
#include <algorithm>


std::set<std::string> GetPPermutations(int n) {
	std::set<std::string> result;

	if (n == 1) {
		result.insert(std::string("()"));
		return result;
	}

	auto pp = GetPPermutations(n - 1);
	for (auto& p: pp) {
		result.insert("(" + p + ")");
		result.insert("()" + p);		
		result.insert(p + "()");		
	}

	return result;
}

int main(int argc, char const *argv[])
{
	auto pp = GetPPermutations(3);
	for (auto& p: pp) {
		std::cout << p << std::endl;
	}
	return 0;
}