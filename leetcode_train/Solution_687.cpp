#include"TreeNode.h"	
#include<algorithm>

using namespace std;

//dfs穷举所有的可能

//自底向上dfs

class Solution_687 {
	int rs = 0;
public:
	int longestUnivaluePath_2(TreeNode* root) {
		if (root == nullptr)
			return 0;
		dfs(root);
		return rs;
	}
	int dfs_2(TreeNode*node) {
		if (node == nullptr)
			return 0;
		int left = dfs(node->left);
		int right = dfs(node->right);
		int new_left = 0;
		int new_right = 0;
		if (node->left != nullptr&&node->left->val == node->val)
			new_left = left + 1;
		if (node->right != nullptr&&node->right->val == node->val)
			new_right = right + 1;
		rs = max(rs, new_left + new_right);
		return max(new_left, new_right);//返回最大的一侧
	}


public:
	int longestUnivaluePath(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left = 0;
		int right = 0;
		if (root->left&&root->left->val == root->val)
			left = dfs(root->left) + 1;
		if (root->right&&root->right->val == root->val)
			right = dfs(root->right) + 1;
		return max(left + right, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
	}
	int dfs(TreeNode*node) {
		if (node == nullptr)
			return 0;
		if (node->left != nullptr&&node->left->val == node->val&&node->right != nullptr&&node->right->val == node->val)
			return max(dfs(node->left), dfs(node->right)) + 1;
		if (node->left != nullptr&&node->left->val == node->val)
			return dfs(node->left) + 1;
		if (node->right != nullptr&&node->right->val == node->val)
			return dfs(node->right) + 1;
		return 0;
	}
};