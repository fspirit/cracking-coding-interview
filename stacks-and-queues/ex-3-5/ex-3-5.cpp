#include "../stack.h"

#include <iostream>

class StackBasedQueue
{
	Stack normal;
	Stack reversed;

public:
	void Enqueue(int value)
	{
		normal.Push(value);
	}

	int Dequeue()
	{
		while (!normal.IsEmpty())
		{
			reversed.Push(normal.Top());
			normal.Pop();
		}
		int value = reversed.Top();
		reversed.Pop();
		while (!reversed.IsEmpty())
		{
			normal.Push(reversed.Top());
			reversed.Pop();
		}
		return value;
	}
};

int main(int argc, char const *argv[])
{
	StackBasedQueue q;

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);

	std::cout << q.Dequeue() << std::endl;
	std::cout << q.Dequeue() << std::endl;
	std::cout << q.Dequeue() << std::endl;

	return 0;
}