#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"TreeNode.h"

using namespace std;


//判断两棵树是否相同
//Given two binary trees, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


class Solution_100 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL&&q == NULL)
			return true;
		if (p == NULL || q == NULL)
			return false;
		if (p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};