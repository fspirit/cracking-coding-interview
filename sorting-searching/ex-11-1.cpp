#include <vector>
#include <iostream>


void MergeInto(std::vector<int>& a, std::vector<int>& b)
{
	for (auto& bb: b)
	{
		if (bb > a[a.size() - 1])
			a.push_back(bb);
		else
		{
			a.push_back(0);
			int k = 0;
			while (a[k] < bb) k++;

			int l = a.size() - 1;
			while (l > k)
			{
				a[l] = a[l -1];
				l--;
			}
			a[k] = bb;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> a { 4, 6, 7, 9, 10 };
	std::vector<int> b { 1, 3, 8, 11};


	MergeInto(a, b);

	for (auto& aa: a)
	{
		std::cout << aa << " ";
	}
	std::cout << std::endl;

	return 0;
}