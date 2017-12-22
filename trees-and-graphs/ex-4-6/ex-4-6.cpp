/*
Write an algorithm to find the'next'node (i.e., in-order successor) of a given node in a binary search tree. 
You may assume that each node has a link to its parent.
*/
#include "../binary-tree-node.h"

#include <iostream>

BinaryTreeNode * GetLeftmostChild(BinaryTreeNode * current)
{	
	if (!current->left)
		return current;
	else
		return GetLeftmostChild(current->left.get());
}

BinaryTreeNode * GetFirstLeftParent(BinaryTreeNode * current)
{
	if (!current->parent.get())
		return nullptr;

	if (current == current->parent->left.get())
		return current->parent.get();
	else
		return GetFirstLeftParent(current->parent.get());
}

BinaryTreeNode * GetNextInOrder(BinaryTreeNode * current)
{
	if (!current)
		return nullptr;

	if (current->right)
		return GetLeftmostChild(current->right.get());
	else if (!current->parent)
		return current;
	else if (current == current->parent->left.get())
		return current->parent.get();
	else if (current == current->parent->right.get())
		return GetFirstLeftParent(current->parent.get());
	else
		return nullptr;
}

void PrintNextInOrder(BinaryTreeNode * node)
{
	std::cout << node->value << " ";
	auto result = GetNextInOrder(node);
	if (result)
	{
		std::cout << result->value << std::endl;
	}
	else
	{
		std::cout << 0 << std::endl;
	}
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
	n2->parent = n1;

	n1->right = n3;
	n3->parent = n1;

	n2->left = n4;
	n4->parent = n2;

	n2->right = n5;
	n5->parent = n2;

	n3->left = n6;
	n6->parent = n3;

	PrintNextInOrder(n1.get());
	PrintNextInOrder(n2.get());
	PrintNextInOrder(n3.get());
	PrintNextInOrder(n4.get());
	PrintNextInOrder(n5.get());
	PrintNextInOrder(n6.get());
	
	return 0;
}




