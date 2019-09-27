#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;

//
//Given a binary tree, return the level order traversal of its nodes' values. 
//(ie, from left to right, level by level).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]

//层次遍历即可
//记录每一层的元素个数


class Solution_102 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>rs;
		if (root == NULL)
			return rs;
		queue<TreeNode*>childs;
		childs.push(root);
		while (!childs.empty()) {
			int current_size = childs.size();
			vector<int>one_level;
			while (current_size>0) {
				root = childs.front();
				childs.pop();
				current_size--;
				one_level.push_back(root->val);
				if (root->left != NULL)
					childs.push(root->left);
				if (root->right != NULL)
					childs.push(root->right);
			}
			rs.push_back(one_level);
		}
		return rs;
	}
};