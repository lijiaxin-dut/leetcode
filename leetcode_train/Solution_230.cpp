#include"TreeNode.h"
#include<iostream>
#include<stack>
using namespace std;


//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


//不停的计算子树的高度
//根据高度区分在左子树还是右子树中寻找



//前序遍历，依次访问 


class Solution_230 {
public:
	int kthSmallest(TreeNode* root, int k) {
		int size = 0;
		count_number(root->left, size);
		if (size + 1 == k)
			return root->val;
		if (size >= k) {
			return kthSmallest(root->left, k);
		}
		else {
			return kthSmallest(root->right, k - size - 1);
		}



	}
	void count_number(TreeNode* node, int &size) {
		if (node != NULL) {
			size++;
			count_number(node->left, size);
			count_number(node->right, size);
		}


	}

	int kthSmallest_preorder(TreeNode* root, int k) {
		stack<TreeNode*>S;
		while (root != NULL || !S.empty()) {
			while (root != NULL) {
				S.push(root);
				root = root->left;
			}
			root = S.top();
			S.pop();
			k--;
			if (k == 0)
				return root->val;
			root = root->right;
		}
		return 0;
	}
};