#include"TreeNode.h"


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/

//出最大树的根节点 root。
//
//就像之前的问题那样，给定的树是从表 A（root = Construct(A)）递归地使用下述 Construct(A) 例程构造的：
//
//如果 A 为空，返回 null
//否则，令 A[i] 作为 A 的最大元素。创建一个值为 A[i] 的根节点 root
//root 的左子树将被构建为 Construct([A[0], A[1], ..., A[i - 1]])
//root 的右子树将被构建为 Construct([A[i + 1], A[i + 2], ..., A[A.length - 1]])
//返回 root

//新插入的节点一定没有右孩子，它一定是某一结点的右孩子

class Solution {
public:
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		if (root == nullptr)
			return new TreeNode(val);
		TreeNode *new_node = new TreeNode(val);
		if (val>root->val) {
			new_node->left = root;
			return new_node;
		}
		TreeNode *cur = root;
		TreeNode *pre = root;
		while (cur&&cur->val>val) {
			pre = cur;
			cur = cur->right;
		}
		pre->right = new_node;
		new_node->left = cur;
		return root;
	}
};