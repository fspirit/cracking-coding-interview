#include <vector>
#include <iostream>

int CountWays(int x, int y) {
	std::vector<std::vector<int>> grid(y);
	for (auto& row: grid) {
		row = std::vector<int>(x);
		for (auto& i: row) {
			i = 0;
		}
	}	

	grid[0][0] = 1;

	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			if (j > 0) {
				grid[j][i] += grid[j-1][i];
			}
			if (i > 0) {
				grid[j][i] += grid[j][i-1];
			}
		}
	}

	return grid[y-1][x-1];
}

int main(int argc, char const *argv[])
{
	std::cout << CountWays(2, 2) << std::endl;
	std::cout << CountWays(3, 3) << std::endl;
	std::cout << CountWays(4, 4) << std::endl;
	return 0;
}