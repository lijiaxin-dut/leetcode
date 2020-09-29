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

//dfs
//我们可以为二叉树 T 定义一个翻转操作，如下所示：选择任意节点，然后交换它的左子树和右子树。
//
//只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转等价于二叉树 Y。
//
//编写一个判断两个二叉树是否是翻转等价的函数。这些树由根节点 root1 和 root2 给出。
//

class Solution {
public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		return help(root1, root2);
	}
	bool help(TreeNode *root1, TreeNode *root2) {
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 == nullptr || root2 == nullptr)
			return false;
		if (root1->val != root2->val)
			return false;
		return (help(root1->left, root2->right) && help(root1->right, root2->left)) || (help(root1->left, root2->left) && help(root1->right, root2->right));
	}
};