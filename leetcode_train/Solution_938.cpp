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
	int rangeSumBST(TreeNode* root, int L, int R) {
		int rs = 0;
		dfs(rs, root, L, R);
		return rs;
	}
	void dfs(int &rs, TreeNode*node, int L, int R) {
		if (node == nullptr)
			return;
		if (node->val >= L&&node->val <= R) {
			rs += node->val;
		}
		if (node->val<L) {
			dfs(rs, node->right, L, R);
			return;
		}
		if (node->val>R) {
			dfs(rs, node->left, L, R);
			return;
		}
		dfs(rs, node->left, L, R);
		dfs(rs, node->right, L, R);
	}
};