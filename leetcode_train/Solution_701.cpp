#include"TreeNode.h"


//Given the root node of a binary search tree(BST) and a value to be inserted into the tree, insert the value into the BST.Return the root node of the BST after the insertion.It is guaranteed that the new value does not exist in the original BST.
//
//Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion.You can return any of them.

class Solution_701 {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == nullptr)
			return new TreeNode(val);
		auto back_root = root;
		while (root != nullptr) {
			if (root->val>val) {
				if (root->left == nullptr) {
					root->left = new TreeNode(val);
					break;
				}
				root = root->left;
			}
			else {
				if (root->right == nullptr) {
					root->right = new TreeNode(val);
					break;
				}
				root = root->right;
			}
		}
		return back_root;
	}
};