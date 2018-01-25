#include<vector>
#include<set>
#include <iostream>


std::vector<std::set<int>> AllSubsets(std::set<int>& set) {
	std::vector<std::set<int>> subsets;
	subsets.push_back(std::set<int>());

	for (auto& item : set) {
		std::vector<std::set<int>> newSubsets;	
		for (auto s : subsets) {
			s.insert(item);
			newSubsets.push_back(s);
		}
		std::copy(newSubsets.begin(), newSubsets.end(), std::back_inserter(subsets));
	}

	return subsets;
}

int main(int argc, char const *argv[])
{	
	std::set<int> set {1, 2, 3, 4};

	auto subsets = AllSubsets(set);

	for (auto& subset : subsets) {
		for (auto& item : subset) {
			std::cout << item;
		}
		std::cout << std::endl;
	}

	return 0;
}



