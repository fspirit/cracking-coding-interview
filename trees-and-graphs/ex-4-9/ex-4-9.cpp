/*
You are given a binary tree in which each node contains a value. Design an algo- rithm to print all paths which sum to a given value. 
The path does not need to start or end at the root or a leaf.
*/

#include "../binary-tree-node.h"

#include <vector>
#include <iostream>

const int TargetSum = 10;

void PrintPaths(BinaryTreeNode * node, std::vector<BinaryTreeNode> currentSums)
{
	if (node == nullptr)
		return;

	std::vector<BinaryTreeNode> newSums;
	for (int i = 0; i < currentSums.size(); i++)
	{
		auto& n = currentSums[i];
		n.value = n.value + node->value;
		if (n.value == TargetSum)
		{
			for (int j = i; j < currentSums.size(); j++)
				std::cout << currentSums[j].index << " ";
			std::cout << node->index << std::endl;
		}		
		newSums.push_back(n);
	}

	if (node->value == TargetSum)
		std::cout << node->index << std::endl;
	newSums.push_back(*node);

	PrintPaths(node->left.get(), newSums);
	PrintPaths(node->right.get(), newSums);
}

int main(int argc, char const *argv[])
{
	auto n1 = std::make_shared<BinaryTreeNode>(0, 5);
	auto n2 = std::make_shared<BinaryTreeNode>(1, 0);
	auto n3 = std::make_shared<BinaryTreeNode>(2, 5);	
	auto n4 = std::make_shared<BinaryTreeNode>(3, 5);
	auto n5 = std::make_shared<BinaryTreeNode>(4, 5);
	auto n6 = std::make_shared<BinaryTreeNode>(5, 5);	

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

	std::vector<BinaryTreeNode> sums;
	PrintPaths(n1.get(), sums);

	return 0;
}