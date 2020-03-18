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


class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr&&t == nullptr)
			return true;
		if (s == nullptr || t == nullptr)
			return false;
		return help(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);

	}
	bool help(TreeNode*p, TreeNode*q) {
		if (p == nullptr&&q == nullptr)
			return true;
		if (p == nullptr || q == nullptr)
			return false;
		if (p->val != q->val)
			return false;
		return help(p->left, q->left) && help(p->right, q->right);
	}
};