#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
#include<sstream>
#include"TreeNode.h"

using namespace std;
//
//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

//递归的判断
//对于每一个节点，记录合法的范围，
//(lower,upper)之间是合法的

//向左子树递归，更新上界，当前值作为上界
//向右子树递归，更新下界，当前值作为下界



//或者使用中序遍历判断

class Solution_98 {
public:
	bool isValidBST(TreeNode* root) {
		return help(root, LONG_MIN, LONG_MAX);
	}
	bool help(TreeNode* root, long lower, long upper) {
		if (root == NULL)
			return true;
		if (root->val <= lower || root->val >= upper)
			return false;
		return help(root->left, lower, root->val) && help(root->right, root->val, upper);

	}
};