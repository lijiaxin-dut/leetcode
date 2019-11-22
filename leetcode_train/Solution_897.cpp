#include"TreeNode.h"


//Given a binary search tree, rearrange the tree in in - order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.
//
//Example 1:
//Input: [5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]
//

//Example 1:
//Input: [5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]
//
//	5
//	/ \
//	3    6
//	/ \    \
//	2   4    8
//	/ / \
//	1        7   9
//
//	Output: [1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9]
//
//	1
//	\
//	2
//	\
//	3
//	\
//	4
//	\
//	5
//	\
//	6
//	\
//	7
//	\
//	8
//	\
//	9

//把二叉树按照中序遍历，拉成一条直线

//result = inorder(root.left) + root + inorder(root.right)

////https://leetcode.com/problems/increasing-order-search-tree/discuss/165885/C%2B%2BJavaPython-Self-Explained-5-line-O(N)

//next 为下一个在中序遍历中的节点
//increasingBST(TreeNode root, TreeNode tail)
//如果root为空，返回下一个节点即可
//call increasingBST(root.left, root),
//change left subtree into the linked list + current node.

//we recursively call increasingBST(root.right, tail),
//change right subtree into the linked list + tail.




class Solution_897 {
public:
	TreeNode* increasingBST(TreeNode* root) {
		return dfs(root, nullptr);

	}
	TreeNode *dfs(TreeNode* node, TreeNode* next) {
		if (node == nullptr)
			return next;
		TreeNode *res = dfs(node->left, node);
		TreeNode *temp = dfs(node->right, next);
		node->left = nullptr;
		node->right = temp;
		return res;

	}
};