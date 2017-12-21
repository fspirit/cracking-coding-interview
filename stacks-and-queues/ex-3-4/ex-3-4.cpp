#include "../stack.h"

#include <vector>
#include <iostream>

void moveTop(std::vector<Stack>& stacks, int from, int to)
{
	stacks[to].Push(stacks[from].Top());
	stacks[from].Pop();
}

void move(std::vector<Stack>& stacks, int n, int from, int to, int buffer)
{
	if (n <= 0)
		return;

	move(stacks, n - 1, from, buffer, to);
	moveTop(stacks, from, to);
	move(stacks, n - 1, buffer, to, from);
}

int main()
{
	std::vector<Stack> v;
	v.emplace_back();
	v.emplace_back();
	v.emplace_back();

	v[0].Push(3);
	v[0].Push(2);
	v[0].Push(1);

	move(v, 3, 0, 2, 1);

	std::cout << v[2].Top() << std::endl;
	v[2].Pop();
	std::cout << v[2].Top() << std::endl;
	v[2].Pop();
	std::cout << v[2].Top() << std::endl;

	return 0;
}