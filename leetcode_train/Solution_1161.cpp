#include<iostream>
#include<vector>
#include"TreeNode.h"

using namespace std;

//
//Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
//
//Return the smallest level X such that the sum of all the values of nodes at level X is maximal.
//
//
//
//Example 1:
//
//
//
//Input: [1, 7, 0, 7, -8, null, null]
//	Output : 2
//	Explanation :
//	Level 1 sum = 1.
//	Level 2 sum = 7 + 0 = 7.
//	Level 3 sum = 7 + -8 = -1.
//	So we return the level with the maximum sum which is level 2.
//

//dfs记录每层的求和

class Solution_1161 {
public:
	int maxLevelSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		vector<int>level_sum;
		dfs(level_sum, root, 0);
		int rs = 0;
		int max_val = INT_MIN;
		for (int i = 0; i<level_sum.size(); i++) {
			if (level_sum[i]>max_val) {
				max_val = level_sum[i];
				rs = i + 1;
			}
		}
		return rs;
	}
	void dfs(vector<int>&level_sum, TreeNode *x, int current_level) {
		if (current_level == level_sum.size())
			level_sum.push_back(x->val);
		else
			level_sum[current_level] += x->val;
		if (x->left)
			dfs(level_sum, x->left, current_level + 1);
		if (x->right)
			dfs(level_sum, x->right, current_level + 1);
	}
};