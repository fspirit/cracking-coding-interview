#include <vector>
#include <iostream>


void rotate(std::vector<std::vector<int>>& m)
{
	int mSize = m.size();
	for (int i = 0; i < mSize; i++)
	{
		for (int j = i + 1; j < mSize; j++)
		{
			int temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
	}
}

void print(std::vector<std::vector<int>>& m)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
			std::cout << m[i][j]; 
		std::cout << std::endl;
	}
}	

int main()
{
	std::vector<std::vector<int>> m = {
		{3 ,3, 3},
		{2, 2, 2},
		{1, 1, 1}
	};

	print(m);
	rotate(m);
	print(m);

	return 0;
}