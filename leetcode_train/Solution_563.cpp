#include"TreeNode.h"
#include<algorithm>

using namespace std;

//Given a binary tree, return the tilt of the whole tree.
//
//The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values.Null node has tilt 0.
//
//The tilt of the whole tree is defined as the sum of all nodes' tilt.
//
//Example:
//Input:
//1
/// \
//2     3
//Output: 1
//	Explanation :
//	Tilt of node 2 : 0
//	Tilt of node 3 : 0
//	Tilt of node 1 : | 2 - 3 | = 1
//	Tilt of binary tree : 0 + 0 + 1 = 1


//dfs

class Solution_563 {
public:
	int findTilt(TreeNode* root) {
		int sum = 0;
		dfs(root, sum);
		return sum;
	}
	int dfs(TreeNode *node, int &sum) {
		if (node == nullptr)
			return 0;
		int left = dfs(node->left, sum);
		int right = dfs(node->right, sum);
		sum += abs(left - right);
		return left + right + node->val;

	}
};