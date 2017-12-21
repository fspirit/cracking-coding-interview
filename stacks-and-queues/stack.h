#include "../node.h"

class Stack
{
	std::shared_ptr<Node> top;
public:
	Stack() : top(nullptr) {};
	
	int Pop()
	{
		if (top != nullptr)
		{
			int value = top->value;
			top = top->next;
			return value;
		}
		return 0;
	}

	void Push(int value)
	{
		auto t = std::make_shared<Node>(value);
		t->next = top;
		top = t;
	}

	int Top()
	{
		if (top != nullptr)
		{
			return top->value;
		}
		return 0;
	}

	bool IsEmpty()
	{
		return top == nullptr;
	}
};