#include"TreeNode.h"
#include<map>
#include<iostream>
#include<queue>
#include<sstream>
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
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//dfs 自底向上递归
//左右节点高度相同时，返回当前节点
//高度不相同时，返回最深的叶子节点即可


class Solution {
public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		return help(root).first;
	}
	pair<TreeNode*, int> help(TreeNode*node) {
		if (node == nullptr) {
			return{ nullptr,0 };
		}
		auto left = help(node->left);
		auto right = help(node->right);
		if (left.second == right.second) {
			return{ node,left.second + 1 };
		}
		else if (left.second>right.second) {
			return{ left.first,left.second + 1 };
		}
		else {
			return{ right.first,right.second + 1 };
		}

	}
};