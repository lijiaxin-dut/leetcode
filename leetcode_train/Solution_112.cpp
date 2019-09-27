#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;


//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that adding up all the values along the path equals the given sum.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given the below binary tree and sum = 22,
//
//	5
//	/ \
//	4   8
//	/ / \
//	11  13  4
//	/ \      \
//	7    2      1
//	return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.


//是否存在一条到叶子节点的路径，路径和为给定的值

//dfs
//到达叶子节点时判断是否==sum

class Solution_112 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		bool is_true = false;
		help(root, sum, 0, is_true);
		return is_true;
	}
	void help(TreeNode*root, int sum, int current_sum, bool &is_true) {
		if (root == NULL || is_true == true)
			return;
		current_sum += root->val;
		if (current_sum == sum&&root->left == NULL&&root->right == NULL) {
			is_true = true;
			return;
		}
		help(root->left, sum, current_sum, is_true);
		help(root->right, sum, current_sum, is_true);
	}
};


