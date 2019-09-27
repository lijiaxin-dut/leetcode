#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;

//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as :
//
//a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example 1 :
//
//	Given the following tree[3, 9, 20, null, null, 15, 7] :
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//	Return true.
//
//	Example 2:
//
//Given the following tree[1, 2, 2, 3, 3, null, null, 4, 4] :
//
//	1
//	/ \
//	2   2
//	/ \
//	3   3
//	/ \
//	4   4
//


//计算左子树最大的高度
//计算右子树最大的高度
//高度差<=1,递归调用左右子树

class Solution_110 {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int left = get_height(root->left);
		int right = get_height(root->right);
		if (abs(left - right) <= 1) {
			return isBalanced(root->left) && isBalanced(root->right);
		}
		return false;
	}
	int get_height(TreeNode*root)
	{
		if (root == NULL)
			return 0;
		return 1 + max(get_height(root->left), get_height(root->right));
	}
};
