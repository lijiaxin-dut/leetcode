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

//dfs �Ե����ϵݹ�
//���ҽڵ�߶���ͬʱ�����ص�ǰ�ڵ�
//�߶Ȳ���ͬʱ�����������Ҷ�ӽڵ㼴��


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