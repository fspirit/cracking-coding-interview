#include <memory>
#include <algorithm>
#include <iostream>

class NodeWithMin
{
public:
	int value;
	int currentMin;
	std::shared_ptr<NodeWithMin> next;

	NodeWithMin(int value, int currentMin): value(value), currentMin(currentMin), next(nullptr) {};
};

class StackWithMin
{
	std::shared_ptr<NodeWithMin> top;

public:

	void Pop()
	{
		if (top != nullptr)
		{
			top = top->next;
		}
	}

	int Top()
	{
		if (top != nullptr)
		{
			return top->value;
		}
		return 0;
	}

	void Push(int value)
	{
		if (top == nullptr)
		{
			top = std::make_shared<NodeWithMin>(value, value);
		}
		else
		{
			auto item = std::make_shared<NodeWithMin>(value, std::min(top->currentMin, value));
			item->next = top;
			top = item;
		}
	}

	int Min()
	{
		if (!top)
			return 0;

		return top->currentMin;
	}
};

int main()
{
	auto stack = StackWithMin();
	stack.Push(3);
	stack.Push(20);
	stack.Push(1);

	std::cout << stack.Min() << std::endl;
	stack.Pop();
	std::cout << stack.Min() << std::endl;
	stack.Pop();
	std::cout << stack.Min() << std::endl;

	return 0;
}

