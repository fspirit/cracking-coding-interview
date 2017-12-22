/*

You have two very large binary trees: Tl, with millions of nodes, and T2, with hundredsofnodes.Create an algorithm to decide if T2 
is a subtree of Tl.
A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2. That is, if you cut off the 
tree at node n, the two trees would be identical.
*/

#include "../binary-tree-node.h"

bool Compare(BinaryTreeNode * t1, BinaryTreeNode * t2)
{
	if (t1 != t2)
		return false;

	if (!t1)
		return true;

	return Compare(t1->left.get(), t2->left.get()) && Compare(t1->right.get(), t2->right.get());
}

bool IsSubtree(BinaryTreeNode * t1, BinaryTreeNode * t2)
{
	if (!t1)
		return false;

	if (t1 == t2 && Compare(t1, t2))
		return true;
	
	return IsSubtree(t1->left.get(), t2) || IsSubtree(t1->right.get(), t2);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
