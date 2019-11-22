#include"TreeNode.h"
#include<algorithm>
using namespace std;

//Given a Binary Search Tree(BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
//
//Example :
//
//Input: root = [4, 2, 6, 1, 3, null, null]
//	Output : 1
//	Explanation :
//	Note that root is a TreeNode object, not an array.
//
//	The given tree[4, 2, 6, 1, 3, null, null] is represented by the following diagram :
//
//	   4
//		   / \
//		   2      6
//		   / \
//		   1   3
//
//		   while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.

//ÖÐÐò±éÀú¼´¿É


class Solution_783 {
public:
	int minDiffInBST(TreeNode* root) {
		int cur_min_val = INT_MAX;
		TreeNode*pre = nullptr;
		dfs(root, pre, cur_min_val);
		return cur_min_val;
	}
	void dfs(TreeNode *node, TreeNode *&pre, int &cur_min_val) {
		if (node == nullptr)
			return;
		dfs(node->left, pre, cur_min_val);
		if (pre != nullptr)
			cur_min_val = min(cur_min_val, node->val - pre->val);
		pre = node;
		dfs(node->right, pre, cur_min_val);
	}
};