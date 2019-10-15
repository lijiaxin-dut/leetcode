#include"TreeNode.h"
#include<stack>

using namespace std;


//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//
//
//Example:
//
//[[7, 3, 15, null, null, 9, 20]]
//
//BSTIterator iterator = new BSTIterator(root);
//iterator.next();    // return 3
//iterator.next();    // return 7
//iterator.hasNext(); // return true
//iterator.next();    // return 9
//iterator.hasNext(); // return true
//iterator.next();    // return 15
//iterator.hasNext(); // return true
//iterator.next();    // return 20
//iterator.hasNext(); // return false


//ÖÐÐò±éÀú¼´¿É



class BSTIterator {
	TreeNode* root;
	stack<TreeNode*>nodes;
public:
	BSTIterator(TreeNode* root) {
		this->root = root;
	}

	/** @return the next smallest number */
	int next() {
		while (root != NULL) {
			nodes.push(root);
			root = root->left;
		}
		root = nodes.top();
		nodes.pop();
		int rs = root->val;
		root = root->right;
		return rs;

	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return root != NULL || !nodes.empty();
	}
};
