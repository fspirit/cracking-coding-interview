#include <memory>

struct BinaryTreeNode
{
	int index;
	int value;
	std::shared_ptr<BinaryTreeNode> left;
	std::shared_ptr<BinaryTreeNode> right;
	std::shared_ptr<BinaryTreeNode> parent;
	BinaryTreeNode(int value): value(value), left(nullptr), right(nullptr), parent(nullptr) {};
	BinaryTreeNode(int index, int value): index(index), value(value), left(nullptr), right(nullptr), parent(nullptr) {};
};