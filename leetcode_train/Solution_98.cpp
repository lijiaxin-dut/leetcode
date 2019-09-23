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

//�ݹ���ж�
//����ÿһ���ڵ㣬��¼�Ϸ��ķ�Χ��
//(lower,upper)֮���ǺϷ���

//���������ݹ飬�����Ͻ磬��ǰֵ��Ϊ�Ͻ�
//���������ݹ飬�����½磬��ǰֵ��Ϊ�½�



//����ʹ����������ж�

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