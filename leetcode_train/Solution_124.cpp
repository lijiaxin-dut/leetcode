#include"TreeNode.h"
#include<algorithm>
#include<unordered_map>

using namespace std;

//自底向上递归，当sum求和小于0时，返回0

//在递归的过程中，更新结果

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
	int rs;
public:
	int maxPathSum(TreeNode* root) {
		rs = INT_MIN;
		help(root);
		return rs;
	}
	int help(TreeNode*node) {
		if (node == nullptr)
			return 0;
		int left = max(help(node->left), 0);
		int right = max(help(node->right), 0);
		rs = max(rs, left + right + node->val);
		return max(left, right) + node->val;

	}
};