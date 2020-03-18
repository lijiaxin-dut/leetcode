#include"TreeNode.h"
#include<algorithm>
#include<vector>
using namespace std;

//Given a binary tree root, a ZigZag path for a binary tree is defined as follow :
//
//Choose any node in the binary tree and a direction(right or left).
//If the current direction is right then move to the right child of the current node otherwise move to the left child.
//Change the direction from right to left or right to left.
//Repeat the second and third step until you can't move in the tree.
//Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
//
//Return the longest ZigZag path contained in that tree.

//1.自定向下递归
//2.
// Recursive return [left, right, result], where:
// left is the maximum length in direction of root.left
// right is the maximum length in direction of root.right
// result is the maximum length in the whole sub tree.
class Solution {
public:
	int longestZigZag_2(TreeNode* root) {
		return dfs_2(root)[2];
	}
	vector<int>dfs_2(TreeNode*node) {
		if (node == nullptr)
			return{ -1,-1,-1 };
		auto left = dfs_2(node->left);
		auto right = dfs_2(node->right);
		int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
		//左子树的右子树结果+1，右子树的左子树结果+1
		return{ left[1] + 1, right[0] + 1, res };
	}
	/////////////////////////////TLE
	int longestZigZag(TreeNode* root) {
		if (root == nullptr)
			return 0;
		return max(dfs(root, nullptr), max(longestZigZag(root->left), longestZigZag(root->right)));
	}
	//dfs返回包含节点node的最长路径
	int dfs(TreeNode*node, TreeNode*pre) {
		if (node == nullptr)
			return 0;
		if (pre == nullptr) 
			return max(dfs(node->left, node), dfs(node->right, node));
		else {
			if (pre->left == node)
				return dfs(node->right, node) + 1;
			else
				return dfs(node->left, node) + 1;
		}
	}
};