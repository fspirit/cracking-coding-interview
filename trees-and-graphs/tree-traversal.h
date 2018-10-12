#include "binary-tree-node.h"

#include <iostream>

void TraverseInOrder(BinaryTreeNode * node)
{
	if (node == nullptr)
		return;
	TraverseInOrder(node->left.get());
	std::cout << node->value << std::endl;
	TraverseInOrder(node->right.get());
}

void TraversePreOrder(BinaryTreeNode * node)
{
	if (node == nullptr)
		return;	
	std::cout << node->value << std::endl;
	TraversePreOrder(node->left.get());
	TraversePreOrder(node->right.get());
}

void TraversePostOrder(BinaryTreeNode * node)
{
	if (node == nullptr)
		return;	
	TraversePostOrder(node->left.get());
	TraversePostOrder(node->right.get());
	std::cout << node->value << std::endl;
}