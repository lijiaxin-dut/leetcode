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


//层次遍历
//每当从 queue 中取出一个元素时，将其 next 指针指向 queue 中下一个节点即可

//使用常数空间
//遍历一层，然后连下一层的next，
//使用dumy指针作为每一层的虚拟节点
//遍历当前层，然后链接下一层


//dumy->next始终指向下一层的头节点
//一层结束后，更新root=dumy->next

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