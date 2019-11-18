#include"TreeNode.h"

//Given a Binary Search Tree(BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
//
//Example:
//
//Input: The root of a Binary Search Tree like this :
//	5
//	/ \
//	2     13
//
//	Output: The root of a Greater Tree like this :
//	18
//	/ \
//	20     13

//反向中序遍历即可

class Solution_538 {
public:
	TreeNode* convertBST(TreeNode* root) {
		int sum = 0;
		rever_inorder(root, sum);
		return root;
	}
	void rever_inorder(TreeNode *root, int &sum) {
		if (root == nullptr)
			return;
		rever_inorder(root->right, sum);
		sum += root->val;
		root->val = sum;
		rever_inorder(root->left, sum);
	}
};