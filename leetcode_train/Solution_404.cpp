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

//µÝ¹é±éÀú

class Solution_404 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
			return 0;
		int rs = 0;
		dfs(root->left, root, rs);
		dfs(root->right, root, rs);
		return rs;
	}
	void dfs(TreeNode *x, TreeNode*pre, int &rs) {
		if (x == NULL)
			return;
		if (x->left == NULL&&x->right == NULL) {
			if (pre->left == x)
				rs += x->val;
			return;
		}
		dfs(x->left, x, rs);
		dfs(x->right, x, rs);
	}
};

