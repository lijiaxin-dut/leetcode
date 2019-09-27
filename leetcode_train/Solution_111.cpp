#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;

//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//	return its minimum depth = 2.

//层次遍历
//找到第一个左右节点都为空的节点
//所在的层即为答案

//递归
//单独处理
//左子树为空
//或者
//右子树为空


class Solution_111 {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*>childs;
		childs.push(root);
		int current_level = 0;
		while (!childs.empty()) {
			int current_level_size = childs.size();
			current_level++;
			while (current_level_size>0) {
				current_level_size--;
				root = childs.front();
				childs.pop();
				if (root->left == NULL&&root->right == NULL)
					return current_level;
				if (root->left != NULL)
					childs.push(root->left);
				if (root->right != NULL)
					childs.push(root->right);
			}
		}
		return current_level;
	}
	int minDepth_1(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL&&root->right == NULL)
			return 1;
		if (root->right == NULL)
			return minDepth(root->left) + 1;
		if (root->left == NULL)
			return minDepth(root->right) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};