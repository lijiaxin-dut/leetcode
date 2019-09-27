#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;


//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its zigzag level order traversal as :
//[
//	[3],
//	[20, 9],
//	[15, 7]
//]


//层次遍历即可
//记录每一层的元素个数
//记录当前是第几层



class Solution_103 {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>>rs;
		if (root == NULL)
			return rs;
		queue<TreeNode*>childs;
		childs.push(root);
		int current_level = 0;
		while (!childs.empty()) {
			int current_level_size = childs.size();
			vector<int>current_level_rs;
			while (current_level_size>0) {
				current_level_size--;
				root = childs.front();
				childs.pop();
				current_level_rs.push_back(root -> val);
				if (root->left != NULL)
					childs.push(root->left);
				if (root->right != NULL)
					childs.push(root->right);
			}
			if (current_level % 2 != 0)
				reverse(current_level_rs.begin(), current_level_rs.end());
			rs.push_back(current_level_rs);
			current_level++;
		}
		return rs;
	}
};