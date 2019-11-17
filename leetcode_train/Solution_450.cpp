#include"TreeNode.h"


//
//Given a root node reference of a BST and a key, delete the node with the given key in the BST.Return the root node reference(possibly updated) of the BST.
//
//Basically, the deletion can be divided into two stages :
//
//Search for a node to remove.
//If the node is found, delete the node.
//Note : Time complexity should be O(height of tree).

//ɾ��������������ָ���ڵ�

//�����ҵ�Ҫɾ���Ľڵ㣬��ɾ���ڵ�ĸ��׽ڵ�

//�����ڵ�Ϊ�գ�����Ҫ���Ǹ��׽ڵ�

//����дһ��������ɾ���������ĸ��ڵ�
//�������������������ֻ��һ���ӽڵ㣬ֱ�ӷ����ӽڵ�
//�������Ҳ������У�����С�Ľڵ�
//������������Ƿ�Ϊֱ���������ҽڵ�


class Solution {
	TreeNode *father = nullptr;
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		auto key_node = find_key_node(root, key);
		if (key_node == nullptr)
			return root;
		//ɾ�����ڵ�
		if (father == nullptr)
			return del(root);
		if (father->left&&father->left->val == key)
			father->left = del(key_node);
		else
			father->right = del(key_node);
		return root;
	}
	TreeNode *del(TreeNode *node) {
		if (node == nullptr)
			return nullptr;
		if (node->right == nullptr)
			return node->left;
		if (node->left == nullptr)
			return node->right;

		TreeNode *max_left = node->right;
		auto pre = node;
		//�ҵ����Ҳ�Ľڵ�
		while (max_left->left) {
			pre = max_left;
			max_left = max_left->left;
		}
		//�ж��Ƿ���ֱ������
		if (node->right != max_left) {
			pre->left = max_left->right;
			max_left->left = node->left;
			max_left->right = node->right;
		}
		//��ֱ������
		else {
			max_left->left = pre->left;
		}
		return max_left;
	}
	TreeNode *find_key_node(TreeNode*root, int key) {
		if (root == nullptr)
			return nullptr;
		if (root->val == key)
			return root;
		father = root;
		if (root->val>key)
			return find_key_node(root->left, key);
		else
			return find_key_node(root->right, key);
	}
};