#include "../stack.h"

#include <iostream>

void SortInAscendingOrder(Stack& source, Stack& target)
{
	while (!source.IsEmpty())
	{
		auto item = source.Top();
		source.Pop();

		while (!target.IsEmpty())
		{
			auto t = target.Top();
			if (t < item)
			{
				break;
			}
			else
			{
				source.Push(t);
				target.Pop();
			}
		}
		target.Push(item);
	}
}

int main()
{
	Stack source;
	Stack target;

	source.Push(10);
	source.Push(1);
	source.Push(20);
	source.Push(5);
	source.Push(2000);

	SortInAscendingOrder(source, target);

	while (!target.IsEmpty())
	{
		std::cout << target.Top() << std::endl;
		target.Pop();
	}

	return 0;
}