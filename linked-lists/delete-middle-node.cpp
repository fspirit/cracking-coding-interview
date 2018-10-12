#include "list.h"


Node * DeleteNode(Node * node) {
	auto current = node;
	while (current->next != nullptr) {
		current->value = current->next->value;
		current = current->next;
	}
	return current;
}

int main(int argc, char const *argv[])
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

	list.Print();

	auto nodeToDelete = DeleteNode(&c);
	list.Delete(nodeToDelete);

	list.Print();

	return 0;
}