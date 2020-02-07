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


//dfs遍历整棵树
//保存部分结果时，注意int与char的转换


class Solution {
public:
	int sumNumbers(TreeNode* root) {
		string cur_sum;
		int rs = 0;
		help(root, rs, cur_sum);
		return rs;
	}
	void help(TreeNode*node, int &rs, string &cur_sum) {
		if (node == nullptr)
			return;
		cur_sum.push_back(node->val + '0');
		if (node->left == nullptr&&node->right == nullptr) {
			rs += stoi(cur_sum);
			cur_sum.pop_back();
			return;
		}
		help(node->left, rs, cur_sum);
		help(node->right, rs, cur_sum);
		cur_sum.pop_back();


	}
};