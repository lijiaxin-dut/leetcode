#include<vector>
#include"TreeNode.h"
using namespace std;

//Given two binary search trees root1 and root2.
//
//Return a list containing all the integers from both trees sorted in ascending order.

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
	void in_order(TreeNode*node, vector<int>&rs) {
		if (node == nullptr)
			return;
		in_order(node->left, rs);
		rs.push_back(node->val);
		in_order(node->right, rs);

	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int>rs;
		vector<int>v1;
		vector<int>v2;
		in_order(root1, v1);
		in_order(root2, v2);

		int v1_index = 0;
		int v2_index = 0;
		while (v1_index != v1.size() || v2_index != v2.size()) {
			if (v1_index == v1.size())
				rs.push_back(v2[v2_index++]);
			else if (v2_index == v2.size())
				rs.push_back(v1[v1_index++]);
			else if (v2[v2_index]<v1[v1_index])
				rs.push_back(v2[v2_index++]);
			else
				rs.push_back(v1[v1_index++]);
		}
		return rs;


	}
};