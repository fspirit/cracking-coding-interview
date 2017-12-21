#include <memory>

class BinaryTreeNode
{
public:
	int value;
	std::shared_ptr<BinaryTreeNode> left;
	std::shared_ptr<BinaryTreeNode> right;
	BinaryTreeNode(int value): value(value), left(nullptr), right(nullptr) {};
};