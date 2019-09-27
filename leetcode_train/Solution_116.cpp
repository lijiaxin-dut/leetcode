#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include"Node.h"

using namespace std;
//
//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.The binary tree has the following definition :
//
//struct Node {
//	int val;
//	Node *left;
//	Node *right;
//	Node *next;
//}
//Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.


//��α���
//ÿ���� queue ��ȡ��һ��Ԫ��ʱ������ next ָ��ָ�� queue ����һ���ڵ㼴��

//�ݹ�
//����ȫ���������������ڵ�����ӽ����ڵĻ��������ӽڵ�ض����ڣ�
//���ӽ��� next ָ�����ֱ��ָ�������ӽڵ㣬
//���������ӽڵ�Ĵ������ǣ��ж��丸�ڵ�� next �Ƿ�Ϊ�գ�����Ϊ�գ�
//��ָ���� next ָ��ָ��Ľڵ�����ӽ�㣬��Ϊ����ָ�� NULL

class Solution_116 {
public:
	Node* connect_1(Node* root) {
		queue<Node*>childs;
		if (root == NULL)
			return root;
		Node*rs = root;
		childs.push(root);
		while (!childs.empty()) {
			int level_size = childs.size();
			while (level_size>0) {
				level_size--;
				root = childs.front();
				childs.pop();
				if (level_size>0)
					root->next = childs.front();
				if (root->left != NULL)
					childs.push(root->left);
				if (root->right != NULL)
					childs.push(root->right);
			}
		}
		return rs;
	}

	Node* connect(Node* root) {
		if (root == NULL)
			return NULL;
		if (root->left) {
			root->left->next = root->right;
		}
		if (root->right)
		{
			if (root->next)
				root->right->next = root->next->left;
		}
		connect(root->left);
		connect(root->right);
		return root;

	}
};