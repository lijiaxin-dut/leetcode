#include<iostream>
#include"TreeNode.h"

using namespace std;
//Find the sum of all left leaves in a given binary tree.
//
//Example:
//
//3
/// \
//9  20
/// \
//15   7
//
//There are two left leaves in the binary tree, with values 9 and 15 respectively.Return 24.

//×Ôµ×ÏòÉÏµÝ¹é

class Solution_404 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		return help(root, nullptr);
	}
	int help(TreeNode*node, TreeNode*pre) {
		if (node == nullptr)
			return 0;
		if (node->left == nullptr&&node->right == nullptr&&pre != nullptr&&pre->left == node)
			return node->val;
		return help(node->left, node) + help(node->right, node);

	}
};

