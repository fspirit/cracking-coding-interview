#include <vector>
#include  <iostream>


void zerofy(std::vector<std::vector<int>>& m)
{
	std::vector<bool> zRows(m.size(), false);
	std::vector<bool> zCols(m[0].size(), false);

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m[0].size(); j++)
			if (m[i][j] == 0)
			{
				zRows[i] = true;
				zCols[j] = true;
			}

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m[0].size(); j++)
			if (zRows[i] or zCols[j])
				m[i][j] = 0;
}

void print(std::vector<std::vector<int>>& m)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[0].size(); j++)
			std::cout << m[i][j]; 
		std::cout << std::endl;
	}
}	

int main()
{
	std::vector<std::vector<int>> m = {
		{3 ,3, 3},
		{2, 2, 0},
		{1, 1, 1}
	};

	print(m);
	zerofy(m);
	print(m);

	return 0;
}