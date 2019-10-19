#include"TreeNode.h"
#include<vector>
#include<string>

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

//Given a binary tree, return all root - to - leaf paths.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Input :
//
//	1
//	/ \
//	2     3
//	\
//	5
//
//	Output: ["1->2->5", "1->3"]
//
//	Explanation : All root - to - leaf paths are : 1->2->5, 1->3

//dfs


class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<vector<int>>rs;
		vector<int>cus_path;
		if (root != NULL) {
			dfs(rs, cus_path, root);
		}
		vector<string>string_rs;
		for (auto &one_rs : rs) {
			string temp;
			for (auto &one_node : one_rs) {
				temp += to_string(one_node);
				temp += "->";
			}
			temp.pop_back();
			temp.pop_back();
			string_rs.push_back(temp);
		}
		return string_rs;
	}
	void dfs(vector<vector<int>>&rs, vector<int>&cus_path, TreeNode *node) {
		if (node == NULL) {
			return;
		}
		if (node->left == NULL&&node->right == NULL) {
			cus_path.push_back(node->val);
			rs.push_back(cus_path);
			cus_path.pop_back();
			return;
		}
		cus_path.push_back(node->val);
		dfs(rs, cus_path, node->left);
		dfs(rs, cus_path, node->right);
		cus_path.pop_back();

	}
};