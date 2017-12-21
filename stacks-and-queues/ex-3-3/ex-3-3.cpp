#include <stack>
#include <memory>
#include <iostream>

const int SizeLimit = 2;

class NodeWithStack
{
public:
	std::stack<int> stack;
	std::shared_ptr<NodeWithStack> next;
};

class StackOfStacks
{
	std::shared_ptr<NodeWithStack> top;

public:
	void Push(int value)
	{
		if (top == nullptr)
		{
			top = std::make_shared<NodeWithStack>();
		}
		else if (top->stack.size() == SizeLimit)
		{
			auto item = std::make_shared<NodeWithStack>();
			item->next = top;
			top = item;
		}
		top->stack.push(value);
	}

	int Top()
	{
		if (top)
			return top->stack.top();
		return 0;
	}

	void Pop()
	{
		if (top && top->stack.size() != 0)
		{
			top->stack.pop();
		}
		if (top->stack.size() == 0 && top->next != nullptr)
		{
			top = top->next;
		}
	}
};

int main()
{
	auto stack = StackOfStacks();
	stack.Push(3);
	stack.Push(20);
	stack.Push(1);

	std::cout << stack.Top() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;

	return 0;
}
