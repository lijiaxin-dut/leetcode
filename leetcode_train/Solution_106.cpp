#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"TreeNode.h"

using namespace std;

//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9, 3, 15, 20, 7]
//postorder = [9, 15, 7, 20, 3]
//Return the following binary tree :
//
//3
/// \
//9  20
/// \
//15   7

//后序遍历：左-右-根
//中序遍历：左-根-右
//后序遍历的最后一个节点为根节点，找到中序根节点所在的位置
//递归的进行下去



class Solution_106 {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return help(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
	TreeNode *help(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder, int p_start, int p_end) {
		if (i_start == i_end)
			return NULL;
		TreeNode *root = new TreeNode(postorder[p_end - 1]);
		int length = 0;
		for (int i = i_start; i<i_end; i++) {
			if (inorder[i] == postorder[p_end - 1])
				break;
			length++;
		}
		root->left = help(inorder, i_start, i_start + length, postorder, p_start, p_start + length);
		root->right = help(inorder, i_start + length + 1, i_end, postorder, p_start + length, p_end - 1);
		return root;


	}
};