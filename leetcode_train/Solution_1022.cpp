#include"TreeNode.h"

//给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
//
//对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
//
//以 10 ^ 9 + 7 为模，返回这些数字之和。


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	int sumRootToLeaf(TreeNode* root) {
		if (root == nullptr)
			return 0;
		return dfs(root, 0);
	}
	int dfs(TreeNode *node, int cur_val) {
		if (node == nullptr) {
			return 0;
		}
		int val = 2 * cur_val + node->val;
		if (node->left == nullptr && node->right == nullptr) {
			return val;
		}
		int rs = 0;
		rs += dfs(node->left, val);
		rs += dfs(node->right, val);
		return rs;
	}
};