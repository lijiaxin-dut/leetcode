#include<iostream>
#include<algorithm>
#include"TreeNode.h"

using namespace std;


//Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = | A.val - B.val | and A is an ancestor of B.
//
//(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

//×Ô¶¥ÏòÏÂµÝ¹é


class Solution_1026 {
public:
	int maxAncestorDiff(TreeNode* root) {
		int rs = 0;
		dfs(INT_MAX, INT_MIN, rs, root);
		return rs;
	}
	void dfs(int current_min, int current_max, int &rs, TreeNode *x) {
		int new_min = min(x->val, current_min);
		int new_max = max(x->val, current_max);
		rs = max(rs, new_max - new_min);
		if (x->left) {
			dfs(new_min, new_max, rs, x->left);
		}
		if (x->right) {
			dfs(new_min, new_max, rs, x->right);
		}

	}
};