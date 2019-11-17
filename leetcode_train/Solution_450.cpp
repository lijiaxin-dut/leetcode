#include"TreeNode.h"


//
//Given a root node reference of a BST and a key, delete the node with the given key in the BST.Return the root node reference(possibly updated) of the BST.
//
//Basically, the deletion can be divided into two stages :
//
//Search for a node to remove.
//If the node is found, delete the node.
//Note : Time complexity should be O(height of tree).

//删除二叉搜索树的指定节点

//首先找到要删除的节点，和删除节点的父亲节点

//若父节点为空，不需要考虑父亲节点

//单独写一个函数，删除二叉树的根节点
//考虑两种特殊情况，即只有一个子节点，直接返回子节点
//否则，在右侧子树中，找最小的节点
//分两种情况，是否为直接相连的右节点


class Solution {
	TreeNode *father = nullptr;
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		auto key_node = find_key_node(root, key);
		if (key_node == nullptr)
			return root;
		//删除根节点
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
		//找到最右侧的节点
		while (max_left->left) {
			pre = max_left;
			max_left = max_left->left;
		}
		//判断是否是直接相连
		if (node->right != max_left) {
			pre->left = max_left->right;
			max_left->left = node->left;
			max_left->right = node->right;
		}
		//是直接相连
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