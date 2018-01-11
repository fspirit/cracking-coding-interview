#include <iostream>
#include <vector>

int Find(std::vector<int>& n, int m, int from, int to) {

	std::cout << from << "  " << to << std::endl;
	if (from == to) {
		if (n[from] == m)
			return from;
		return -1;
	}

	bool rotated = (n[from] > n[to]);
	int middle = from + (to - from) / 2;
	auto middleItem = n[middle];

	if (m == middleItem)
		return middle;

	if (!rotated) {
		if (m < middleItem)
			return Find(n, m, from, middle);
		return Find(n, m, middle + 1, to);
	}
	else {
		if (m < middleItem || m > n[to])
			return Find(n, m, from, middle);
		return Find(n, m, middle + 1, to);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> n { 7, 9, 1, 2, 3, 4, 5, 6};

	std::cout << Find(n, 9, 0, n.size()) << std::endl;
	return 0;
}