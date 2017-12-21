#include "../list.h"
#include <map>

Node* findLoop(List& list)
{
	std::map<int, bool> map;
	auto current = list.head;
	while (current != nullptr)
	{
		if (map.count(current->value) != 0)		
			return current;
		map[current->value] = true;
		current = current->next;		
	}
	return nullptr;
}

int main()
{
	Node a(10);
	Node b(2);
	Node c(6);
	Node d(1);
	Node e(3);	

	List list;
	list.Add(&a);
	list.Add(&b);
	list.Add(&c);
	list.Add(&d);
	list.Add(&e);
	list.Add(&c);

	std::cout << "Created list" << std::endl;

	// list.Print();

	Node *loopStarter = findLoop(list);

	if (loopStarter)
		std::cout << loopStarter->value << std::endl;
	else
		std::cout << "Not found" << std::endl;
}