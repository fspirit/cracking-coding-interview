#include "../list.h"


void partitionAroundValue(List& list, int value)
{
	auto current = list.head;
	while (current != nullptr)
	{
		auto next = current->next;
		if (current->value < value && current != list.head)
		{
			list.Delete(current);
			current->next = list.head;
			list.head = current;
		}
		current = next;
	}
}

int main()
{
	Node a(10);
	Node b(2);
	Node c(6);
	Node d(1);
	Node e(3);
	Node f(10);

	List list;
	list.Add(&a);
	list.Add(&b);
	list.Add(&c);
	list.Add(&d);
	list.Add(&e);
	list.Add(&f);

	std::cout << "Created list" << std::endl;

	list.Print();

	partitionAroundValue(list, 6);

	list.Print();

	return 0;
}