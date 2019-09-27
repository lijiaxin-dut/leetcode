#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;
//
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
//	return its depth = 3.


//²ã´Î±éÀú


//µÝ¹é
//1+max(root->left,root->right);

class Solution_104 {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*>childs;
		childs.push(root);
		int current_level = 0;
		while (!childs.empty()) {
			int current_level_size = childs.size();
			while (current_level_size>0) {
				current_level_size--;
				root = childs.front();
				childs.pop();
				if (root->left != NULL)
					childs.push(root->left);
				if (root->right != NULL)
					childs.push(root->right);
			}
			current_level++;
		}
		return current_level;
	}

	int maxDepth_1(TreeNode* root) {
		if (root == NULL)
			return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}


};