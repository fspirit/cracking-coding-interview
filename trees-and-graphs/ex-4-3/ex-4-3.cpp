/*
Given a sorted (increasingorder) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
*/

#include "../tree-traversal.h"

#include <vector>

std::shared_ptr<BinaryTreeNode> createMinBST(std::vector<int>& items, int from, int to)
{
	if (from > to)
		return nullptr;

	if (from == to)
		return std::make_shared<BinaryTreeNode>(items[from]);

	int middle = (to - from) / 2 + from;
	auto node = std::make_shared<BinaryTreeNode>(items[middle]);
	node->left = createMinBST(items, from, middle - 1);
	node->right = createMinBST(items, middle + 1, to);
	return node;
}

int main()
{
	std::vector<int> items = { 1, 2, 3, 4, 5, 6, 7};

	auto root = createMinBST(items, 0, items.size());

	TraverseInOrder(root.get());

	return 0;
}