#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include"Node.h"

using namespace std;

//Given a binary tree
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

//ʹ�ó����ռ�
//����һ�㣬Ȼ������һ���next��
//ʹ��dumyָ����Ϊÿһ�������ڵ�
//������ǰ�㣬Ȼ��������һ��


//dumy->nextʼ��ָ����һ���ͷ�ڵ�
//һ������󣬸���root=dumy->next

class Solution_117 {
public:
	Node* connect(Node* root) {
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

	Node* connect_1(Node* root) {
		Node *dumy = new Node(0, NULL, NULL, NULL);
		Node *cur = dumy;
		Node *head = root;
		while (root) {
			if (root->left)
			{
				cur->next = root->left;
				cur = cur->next;
			}
			if (root->right) {
				cur->next = root->right;
				cur = cur->next;
			}
			root = root->next;
			if (root == NULL) {
				cur = dumy;
				root = dumy->next;
				dumy->next = NULL;
			}
		}
		return head;

	}
};