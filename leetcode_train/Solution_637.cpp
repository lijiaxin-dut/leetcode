#include"TreeNode.h"
#include<vector>

using namespace std;


//Given a non - empty binary tree, return the average value of the nodes on each level in the form of an array.
//Example 1:
//Input:
//3
/// \
//9  20
/// \
//15   7
//Output: [3, 14.5, 11]
//	Explanation :
//	The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11. Hence return[3, 14.5, 11].
//




class Solution_637 {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double>level_sum;
		vector<int>level_size;
		dfs(root, level_sum, level_size, 0);
		for (int i = 0; i<level_sum.size(); i++) {
			level_sum[i] = level_sum[i] / level_size[i];
		}
		return level_sum;
	}
	void dfs(TreeNode *node, vector<double>&level_sum, vector<int>&level_size, int cur_level) {
		if (node == nullptr)
			return;
		if (level_sum.size() == cur_level) {
			level_sum.push_back(node->val);
			level_size.push_back(1);
		}
		else {
			level_sum[cur_level] += node->val;
			level_size[cur_level]++;
		}
		dfs(node->left, level_sum, level_size, cur_level + 1);
		dfs(node->right, level_sum, level_size, cur_level + 1);
	}
};