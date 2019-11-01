#include<vector>
#include"TreeNode.h"
#include<algorithm>
using namespace std;

//You need to find the largest value in each row of a binary tree.
//
//Example:
//Input:
//
//1
/// \
//3   2
/// \   \
//5   3   9
//
//Output: [1, 3, 9]
//

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


class Solution_515 {
public:
	vector<int> largestValues(TreeNode* root) {
		if (root == NULL)
			return{};
		vector<int>rs;
		dfs(0, rs, root);
		return rs;
	}
	void dfs(int current_level, vector<int>&rs, TreeNode *x) {

		if (current_level == rs.size())
			rs.push_back(x->val);
		else
			rs[current_level] = max(rs[current_level], x->val);

		if (x->left)
			dfs(current_level + 1, rs, x->left);
		if (x->right)
			dfs(current_level + 1, rs, x->right);
	}
};