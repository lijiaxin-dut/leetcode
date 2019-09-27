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

	//��α���
	//leftÿһ�β����ʼ����
	//rightÿһ����ҿ�ʼ����
	//����ǶԳƵ�
	//���ұ���ÿ�εĽ������ͬ��
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


	//�ݹ�
	//�ʼ�ж�root==root
	//p1->left��p2->right
	//p1->right?p2->left
	//�������ڵ�n1, n2��
	//��Ҫ�Ƚ�n1�����ӽڵ��ֵ��n2�����ӽڵ��ֵ�Ƿ���ȣ�
	//ͬʱ��Ҫ�Ƚ�n1�����ӽڵ��ֵ��n2�����ӽ���ֵ�Ƿ����
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