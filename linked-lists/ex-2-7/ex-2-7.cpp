#include "../list.h"
#include <stack>

bool isPalindrome(List& list)
{
	std::stack<int> stack;
	int middle = list.Size() / 2;
	auto p = list.head;

	for (int i = 0; i < middle; i++)
	{
		stack.push(p->value);
		p = p->next;
	}

	if (list.Size() % 2 != 0)
		p = p->next;

	while (p != nullptr)
	{
		if (stack.top() != p->value)
			return false;
		stack.pop();
		p = p->next;
	}

	return true;
}

int main()
{
	Node a(1);
	Node b(2);
	Node c(3);
	Node d(1);
	// Node e(4);	

	List list;
	list.Add(&a);
	list.Add(&b);
	list.Add(&c);
	list.Add(&d);
	// list.Add(&e);	

	std::cout << "Created list" << std::endl;
	std::cout << isPalindrome(list) << std::endl;	

	return 0;
}