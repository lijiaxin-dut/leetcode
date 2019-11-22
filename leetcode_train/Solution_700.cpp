#include"TreeNode.h"

//Return any binary tree that matches the given preorder and postorder traversals.
//
//Values in the traversals pre and post are distinct positive integers.


class Solution_700 {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr)
			return nullptr;
		if (root->val == val)
			return root;
		else if (root->val<val)
			return searchBST(root->right, val);
		else
			return searchBST(root->left, val);
	}
};