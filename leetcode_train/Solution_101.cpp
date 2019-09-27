#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;


//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//
//
//But the following[1, 2, 2, null, 3, null, 3] is not:
//
//1
/// \
//2   2
//\   \
//3    3

class Solution_101 {
public:

	//层次遍历
	//left每一次层从左开始遍历
	//right每一层从右开始遍历
	//如果是对称的
	//左右遍历每次的结果是相同的
	bool isSymmetric_1(TreeNode* root) {
		queue<TreeNode *>left;
		queue<TreeNode*>right;
		left.push(root);
		right.push(root);
		while (!left.empty() && !right.empty()) {
			auto t = left.front();
			left.pop();
			auto t1 = right.front();
			right.pop();
			if (t == NULL&&t1 == NULL)
				continue;
			if (t == NULL || t1 == NULL)
				return false;
			if (t1->val != t->val)
				return false;
			left.push(t->left);
			left.push(t->right);
			right.push(t1->right);
			right.push(t1->left);
		}
		return true;

	}


	//递归
	//最开始判断root==root
	//p1->left？p2->right
	//p1->right?p2->left
	//有两个节点n1, n2，
	//需要比较n1的左子节点的值和n2的右子节点的值是否相等，
	//同时还要比较n1的右子节点的值和n2的左子结点的值是否相等
	bool isSymmetric(TreeNode* root) {
		return help(root, root);
	}
	bool help(TreeNode *left, TreeNode*right) {
		if (left == NULL&&right == NULL)
			return true;
		if (left == NULL || right == NULL)
			return false;
		if (left->val != right->val)
			return false;
		return help(left->left, right->right) && help(left->right, right->left);


	}
};