/* 
Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth 
(e.g., if you have a tree with depth D, you'll have D linked lists).
*/

#include "../tree-traversal.h"

#include <vector>
#include <list>


void TreeToLists(std::vector<std::list<int>>& lists, int level, BinaryTreeNode * node)
{
	if (node == nullptr)
		return;

	while (lists.size() != level)
		lists.emplace_back();

	auto list = lists[level];
	list.push_back(node->value);
	TreeToLists(lists, level + 1, node->left.get());
	TreeToLists(lists, level + 1, node->right.get());
}

int main()
{
	auto n1 = std::make_shared<BinaryTreeNode>(1);
	auto n2 = std::make_shared<BinaryTreeNode>(2);
	auto n3 = std::make_shared<BinaryTreeNode>(3);	
	auto n4 = std::make_shared<BinaryTreeNode>(4);
	auto n5 = std::make_shared<BinaryTreeNode>(5);
	auto n6 = std::make_shared<BinaryTreeNode>(6);	

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;

	std::vector<std::list<int>> lists;

	TreeToLists(lists, 0, n1.get());

	for (auto& l: lists)
	{
		for (auto& item: l)
		{
			std::cout << item;
		}
		std::cout << std::endl;
	}

}