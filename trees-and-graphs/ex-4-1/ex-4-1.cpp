#include "../binary-tree-node.h"

#include <iostream>
#include <cmath>
#include <algorithm>

struct Result
{
	int height;
	bool isBalanced;

	Result() {};
	Result(int height, bool isBalanced) : height(height), isBalanced(isBalanced) {};
};

Result Traverse(std::shared_ptr<BinaryTreeNode> node)
{
	if (node == nullptr)
		return { 0, true };

	auto left = Traverse(node->left);

	if (!left.isBalanced)
		return { -1, false };

	auto right = Traverse(node->right);

	if (!right.isBalanced)
		return { -1, false };

	Result result;
	result.isBalanced = std::abs(left.height - right.height) <= 1;
	result.height = 1 + std::max(left.height, right.height);

	return result;
}

int main()
{
	auto a = std::make_shared<BinaryTreeNode>(2);
	auto b = std::make_shared<BinaryTreeNode>(33);
	auto c = std::make_shared<BinaryTreeNode>(21);	

	// a->left = b;
	// b->left = c;

	a->left = b;
	a->right = c;

	auto result = Traverse(a);

	std::cout << result.isBalanced << " " << result.height << std::endl;
}

