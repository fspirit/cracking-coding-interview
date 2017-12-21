#include <memory>

#include "../node.h"

class Queue
{
	Queue(): first(nullptr), last(nullptr) {};

	std::shared_ptr<Node> first;
	std::shared_ptr<Node> last;

	void Enqueue(value)
	{
		if (first == nullptr)
		{
			first = std::make_shared<Node>(value);
			last = first;
		}
		else
		{
			last->next = std::make_shared<Node>(value);
			last = last->next;
		}
	}

	int Dequeue()
	{
		if (first == nullptr)
			return 0;

		int value = first->value;
		first = first->next;

		if (first == nullptr)
			last = nullptr;

		return value;
	}

}