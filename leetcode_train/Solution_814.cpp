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




class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		int root_count = dfs(root);
		return root_count == 0 ? nullptr : root;
	}
	int dfs(TreeNode* node) {
		if (node == nullptr) return 0;
		int rs = 0;
		if (node->val == 1) rs++;
		int left = dfs(node->left);
		if (left == 0) node->left = nullptr;
		int right = dfs(node->right);
		if (right == 0)  node->right = nullptr;
		return rs + left + right;
	}
};