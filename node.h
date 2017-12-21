#include <memory>

struct Node
{
	int value;
	std::shared_ptr<Node> next;

	Node(int value): value(value), next(nullptr) {};	
};