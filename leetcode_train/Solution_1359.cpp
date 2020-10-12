#include"TreeNode.h"
#include<algorithm>
using namespace std;
//给你一棵二叉树，它的根为 root 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。
//
//由于答案可能会很大，请你将结果对 10 ^ 9 + 7 取模后再返回。

//If we know the sum of a subtree, the answer is max((total_sum - subtree_sum) * subtree_sum) in each node.


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
	const long MOD = 1e9 + 7;
	void dfs(TreeNode*node, long &sum) {
		if (node == nullptr)
			return;
		sum += node->val;
		dfs(node->left, sum);
		dfs(node->right, sum);
	}
public:
	long dfs_2(TreeNode*node, long &rs, long sum) {
		if (node == nullptr)
			return 0;
		long left = dfs_2(node->left, rs, sum);
		long right = dfs_2(node->right, rs, sum);
		rs = max(rs, max(((sum - left)*(left)), ((sum - right)*(right))));
		return node->val + left + right;

	}
	int maxProduct(TreeNode* root) {
		long sum = 0;
		dfs(root, sum);
		long rs = 0;
		dfs_2(root, rs, sum);
		return rs%MOD;
	}
};