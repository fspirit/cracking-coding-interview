/*
Implement a function to check if a binary tree is a binary search tree.
*/

#include "../binary-tree-node.h"

#include <iostream>

bool CheckIfBinary(BinaryTreeNode * node)
{
	if (node == nullptr)
		return true;
	if (node->left && node->left->value > node->value)
		return false;
	if (node->right && node->right->value < node->value)
		return false;
	return CheckIfBinary(node->left.get()) && CheckIfBinary(node->right.get());
}

int main(int argc, char const *argv[])
{
	auto n1 = std::make_shared<BinaryTreeNode>(10);
	auto n2 = std::make_shared<BinaryTreeNode>(5);
	auto n3 = std::make_shared<BinaryTreeNode>(15);	
	auto n4 = std::make_shared<BinaryTreeNode>(1);
	auto n5 = std::make_shared<BinaryTreeNode>(7);
	auto n6 = std::make_shared<BinaryTreeNode>(12);	

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;

	std::cout << CheckIfBinary(n1.get()) << std::endl;

	return 0;
}