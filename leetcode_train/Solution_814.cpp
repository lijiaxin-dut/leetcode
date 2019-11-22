#include"TreeNode.h"



//We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
//
//Return the same tree where every subtree(of the given tree) not containing a 1 has been removed.
//
//(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
//
//Example 1:
//Input: [1, null, 0, 0, 1]
//	Output : [1, null, 0, null, 1]
//
//	Explanation :
//	Only the red nodes satisfy the property "every subtree not containing a 1".
//	The diagram on the right represents the answer.

//自底向上dfs
//返回每一棵子树1的数目




class Solution_814 {
public:
	TreeNode* pruneTree(TreeNode* root) {
		int root_val = dfs(root);
		return root_val == 0 ? nullptr : root;
	}
	int dfs(TreeNode*node) {
		if (node == nullptr)
			return 0;
		if (node->left == nullptr&&node->right == nullptr) {
			if (node->val == 1)
				return 1;
			else
				return 0;
		}
		int left = dfs(node->left);
		int right = dfs(node->right);
		if (left == 0)
			node->left = nullptr;
		if (right == 0)
			node->right = nullptr;
		int cur = 0;
		if (node->val == 1)
			cur = 1;
		return cur + left + right;
	}
};