#include <string>
#include <iostream>

bool CompareEqualLengths(std::string& a, std::string& b) {
	int diffCount = 0;
	for (int i =0; i < a.size(); i++) {
		if (a[i] != b[i])
			diffCount++;
	}
	return (diffCount <= 1);
}

bool CompareNonEqualLengths(std::string& longer, std::string& shorter) {
	bool diffFound = false;
	int j = 0;
	for (auto& c : longer) {
		if (c != shorter[j]) {
			if (diffFound)
				return false;
			diffFound = true;
		} else {
			j++;
		}
	}
	return true;
}

bool IsOneAway(std::string a, std::string b) {
	if (a.size() == b.size()) {
		return CompareEqualLengths(a, b);
	} else {
		if (a.size() > b.size()) {
			return CompareNonEqualLengths(a, b);
		} else {
			return CompareNonEqualLengths(b, a);
		}
	}
}


int main(int argc, char const *argv[])
{
	std::cout << IsOneAway("pale", "ple") << std::endl;
	std::cout << IsOneAway("pales", "pale") << std::endl;
	std::cout << IsOneAway("pale", "bale") << std::endl;
	std::cout << IsOneAway("pale", "bake") << std::endl;	

	return 0;
}