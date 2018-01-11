#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

std::vector<std::string> GroupAnagrams(std::vector<std::string>& strings) {
	std::map<std::string, std::list<std::string>> buckets;

	for (auto& s : strings) {
		std::string sorted = s;
		std::sort(sorted.begin(), sorted.end());
		if (buckets.count(sorted) == 0) {
			buckets[sorted] = std::list<std::string>();
		}
		buckets[sorted].push_front(s);
	}

	std::vector<std::string> result;
	for (auto& kv: buckets) {
		auto list = kv.second;
		std::copy(list.begin(), list.end(), std::back_inserter(result));
	}

	return result;
}

int main(int argc, char const *argv[])
{
	std::vector<std::string> strings{ "bnb", "aaa", "bbn", "ccc", "nbb"};

	auto result = GroupAnagrams(strings);

	for (auto& s: result) {
		std::cout << s << std::endl;
	}

	return 0;
}


