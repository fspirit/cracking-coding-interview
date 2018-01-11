#include <string>
#include <vector>
#include <iostream>


int Find(std::vector<std::string>& ss, std::string m, int from, int to) {
	if (from == to) {
		if (ss[from] == m) {
			return from;
		}
		return -1;
	}

	int mid = from + (to - from) / 2;

	while (mid != from && ss[mid] == "") {
		mid--;
	}
	while (mid != to && ss[mid] == "") {
		mid++;
	}
	if (ss[mid] == "") {
		return -1;
	}

	if (ss[mid] == m) {
		return mid;
	}

	if (m < ss[mid]) {
		return Find(ss, m, from, mid);
	} else {
		return Find(ss, m, mid + 1, to);	
	}
}


int main(int argc, char const *argv[])
{
	std::vector<std::string> ss {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};

	std::cout << Find(ss, "ball", 0, ss.size()) << std::endl;

	return 0;
}
