#include <iostream>
#include <vector>
#include <algorithm>

int LongestTower(std::vector<std::pair<int, int>>& ppl)
{
	std::sort(ppl.begin(), ppl.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.first < b.first;
	});

	std::vector<int> lt(ppl.size());
	int max = 0;
	for (int i = 0; i < ppl.size(); i++) {
		lt[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (ppl[i].first > ppl[j].first && 
				ppl[i].second > ppl[j].second) {
				lt[i] = std::max(lt[i], 1 + lt[j]);
				if (lt[i] > max) {
					max = lt[i];
				}
			}
		}
	}

	return max;
}


int main(int argc, char const *argv[])
{
	std::vector<std::pair<int, int>> ppl { {65, 100}, {70, 150}, {56, 90}, {75, 190}, {66, 95}, {68, 110} };

	std::cout << LongestTower(ppl) << std::endl;
	
	return 0;
}