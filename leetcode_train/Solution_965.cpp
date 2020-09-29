#include"TreeNode.h"
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr)
			return true;
		int val = root->val;
		return dfs(root, val);
	}
	bool dfs(TreeNode *node, int val) {
		if (node == nullptr)
			return true;
		if (node->val != val)
			return false;
		return dfs(node->left, val) && dfs(node->right, val);
	}
};