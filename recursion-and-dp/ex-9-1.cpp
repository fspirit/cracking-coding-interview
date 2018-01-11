#include <iostream>
#include <vector>


int CountSteps(int n)
{
	std::vector<int> counts(n+1);

	for (auto& i: counts) {
		i = 0;
	}

	if (n <= 0)
		return 0;

	counts[0] = 1;
	if (n > 1)
		counts[1] = 1;
	if (n > 2)
		counts[2] = 1;

	for (int i = 0; i < n+1; i++) {
		if (i-3 >= 0) {
			counts[i] += counts[i-3];
		}
		if (i-2 >= 0) {
			counts[i] += counts[i-2];
		}
		if (i-1 >= 0) {
			counts[i] += counts[i-1];
		}		
	}

	return counts[n];
}

int main(int argc, char const *argv[])
{
	std::cout << CountSteps(2) << std::endl;
	std::cout << CountSteps(3) << std::endl;
	std::cout << CountSteps(4) << std::endl;
	return 0;
}