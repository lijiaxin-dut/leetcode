#include"TreeNode.h"

//Given two non - empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s.A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
//Example 1:
//Given tree s :
//
//3
/// \
//4   5
/// \
//1   2
//Given tree t :
//4
/// \
//1   2

//dfsÒÀ´ÎÅÐ¶Ï


class Solution_572 {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		bool find = false;
		dfs(s, t, find);
		return find;
	}

	void dfs(TreeNode *x, TreeNode *t, bool &find) {
		if (find == true || x == nullptr)
			return;
		if (x->val == t->val) {
			find = help(x, t);
		}
		dfs(x->left, t, find);
		dfs(x->right, t, find);
	}

	bool help(TreeNode*x, TreeNode *y) {
		if (x == nullptr&&y == nullptr)
			return true;
		if (x == nullptr || y == nullptr)
			return false;
		if (x->val != y->val)
			return false;
		return help(x->left, y->left) && help(x->right, y->right);

	}
};