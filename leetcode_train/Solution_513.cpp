#include<vector>
#include"TreeNode.h"

using namespace std;
//
//Given a binary tree, find the leftmost value in the last row of the tree.
//
//Example 1:
//Input:
//
//2
/// \
//1   3
//
//Output:
//1


//dfs  第一次到达新的层时，保存结果

class Solution_513 {
public:
	int findBottomLeftValue(TreeNode* root) {
		int level_size = 0;
		int rs_val = 0;
		dfs(0, level_size, rs_val, root);
		return rs_val;

	}
	void dfs(int current_level, int &level_size, int &rs_val, TreeNode*x) {
		if (current_level == level_size) {
			level_size++;
			rs_val = x->val;
		}
		if (x->left)
			dfs(current_level + 1, level_size, rs_val, x->left);
		if (x->right)
			dfs(current_level + 1, level_size, rs_val, x->right);
	}
};