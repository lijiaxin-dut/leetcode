#include"TreeNode.h"
#include<algorithm>

//invert a binary tree.
//
//Example:
//
//Input:
//
//4
/// \
//2     7
/// \ / \
//1   3 6   9
//Output:
//
//4
/// \
//7     2
/// \ / \
//9   6 3   1

//µÝ¹é·´×ª¼´¿É

class Solution_226 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		// TreeNode *temp=root->left;
		// root->left=root->right;
		// root->right=temp;
		std::swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};