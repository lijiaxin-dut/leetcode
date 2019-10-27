#include"TreeNode.h"
#include<iostream>
using namespace std;


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
//
//You need to merge them into a new binary tree.The merge rule is that if two nodes overlap, 
//then sum node values up as the new value of the merged node.Otherwise, 
//the NOT null node will be used as the node of new tree.


//合并两棵二叉树
//递归，不断的生成节点



class Solution_617 {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL&&t2 == NULL)
			return NULL;
		TreeNode *new_node = new TreeNode(0);
		if (t1 == NULL) {
			new_node->val += t2->val;
			new_node->left = mergeTrees(NULL, t2->left);
			new_node->right = mergeTrees(NULL, t2->right);
			return new_node;
		}
		if (t2 == NULL) {
			new_node->val += t1->val;
			new_node->left = mergeTrees(t1->left, NULL);
			new_node->right = mergeTrees(t1->right, NULL);
			return new_node;
		}
		new_node->val += t1->val;
		new_node->val += t2->val;
		new_node->left = mergeTrees(t1->left, t2->left);
		new_node->right = mergeTrees(t1->right, t2->right);
		return new_node;

	}
};