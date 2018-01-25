#include <iostream>
#include <vector>
#include <cmath>


const int Size = 8;


bool IsValid(std::vector<int>& currentVariant,  int currentRow, int column) {
	for (int i = 0; i < currentRow; i++) {
		if (currentVariant[i] == column) {
			return false;
		}

		if ((currentRow - i) == std::abs(column - currentVariant[i])) {
			return false;
		}
	}

	return true;
}

void BuildVariants(std::vector<std::vector<int>>& results, std::vector<int> currentVariant,  int currentRow) {
	if (currentRow == Size) {
		results.push_back(currentVariant);
	} else {
		for (int column = 0; column < Size; column++) {
			if (IsValid(currentVariant, currentRow, column)) {
				currentVariant[currentRow] = column;
				BuildVariants(results, currentVariant, currentRow + 1);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> results;
	BuildVariants(results, {}, 0);

	for (auto& var : results) {

	}

	return 0;
}