#include "../list.h"

void removeDuplicates(List& list)
{
	auto p1 = list.head;
	if (!p1)
		return;

	while (p1->next != nullptr)
	{
		auto p2 = p1->next;
		while (p2 != nullptr)
		{
			if (p2->value == p1->value)											
				list.Delete(p2->value);			
			p2 = p2->next;
		}
		p1 = p1->next;
	}	
}

int main()
{
	Node a(10);
	Node b(2);
	Node c(10);
	Node d(1);
	Node e(1);
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

	removeDuplicates(list);

	list.Print();

	return 0;
}