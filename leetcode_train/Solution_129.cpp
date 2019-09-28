#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>
#include<queue>
#include<unordered_set>
#include"TreeNode.h"

using namespace std;


//Given a binary tree containing digits from 0 - 9 only, each root - to - leaf path could represent a number.
//
//An example is the root - to - leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root - to - leaf numbers.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Input : [1, 2, 3]
//	1
//	/ \
//	2   3
//	Output: 25
//	Explanation :
//	The root - to - leaf path 1->2 represents the number 12.
//	The root - to - leaf path 1->3 represents the number 13.
//	Therefore, sum = 12 + 13 = 25.


//dfs±éÀúÕû¿ÃÊ÷



class Solution {
public:
	int sumNumbers(TreeNode* root) {
		vector<vector<int>>all_path_sum;
		if (root == NULL)
			return 0;
		vector<int>partial_rs{ root->val };
		help(root, all_path_sum, partial_rs);
		int rs = 0;
		for (int i = 0; i<all_path_sum.size(); i++)
		{
			int current_num = 0;
			for (auto &one_num : all_path_sum[i]) {
				current_num *= 10;
				current_num += one_num;
			}
			rs += current_num;
		}
		return rs;
	}
	void help(TreeNode *root, vector<vector<int>>&all_path_sum, vector<int>&current_sum) {
		if (root->left == NULL&&root->right == NULL) {
			all_path_sum.push_back(current_sum);
			return;
		}
		if (root->left) {
			current_sum.push_back(root->left->val);
			help(root->left, all_path_sum, current_sum);
			current_sum.pop_back();
		}
		if (root->right) {
			current_sum.push_back(root->right->val);
			help(root->right, all_path_sum, current_sum);
			current_sum.pop_back();
		}


	}
};