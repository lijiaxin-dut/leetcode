#include"TreeNode.h"
#include<algorithm>
#include<unordered_map>

using namespace std;

//Given a binary tree, you need to compute the length of the diameter of the tree.The diameter of a binary tree is the length of the longest path between any two nodes in a tree.This path may or may not pass through the root.
//
//Example:
//Given a binary tree
//1
/// \
//2   3
/// \
//4   5
//Return 3, which is the length of the path[4, 2, 1, 3] or [5, 2, 1, 3].


//找到左右高度求和最大的一个节点


class Solution {
public:
	unordered_map<TreeNode*, int>hash_map;
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left = max_depth(root->left);
		int right = max_depth(root->right);
		return max(left + right, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));

	}
	int max_depth(TreeNode *x) {
		if (hash_map.find(x) != hash_map.end())
			return hash_map[x];
		if (x == NULL)
			return 0;
		int dep = 1 + max(max_depth(x->left), max_depth(x->right));
		hash_map[x] = dep;
		return dep;
	}
};