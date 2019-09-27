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


//层次遍历
//每当从 queue 中取出一个元素时，将其 next 指针指向 queue 中下一个节点即可

//递归
//是完全二叉树，所以若节点的左子结点存在的话，其右子节点必定存在，
//左子结点的 next 指针可以直接指向其右子节点，
//对于其右子节点的处理方法是，判断其父节点的 next 是否为空，若不为空，
//则指向其 next 指针指向的节点的左子结点，若为空则指向 NULL

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