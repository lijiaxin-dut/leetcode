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
	stack<TreeNode*>s;
	TreeNode* root;
public:
	BSTIterator(TreeNode* r) {
		root = r;
		if (root != nullptr) {
			while (root) {
				s.push(root);
				root = root->left;
			}

		}
	}

	/** @return the next smallest number */
	int next() {
		if (s.empty())
			return -1;
		root = s.top();
		s.pop();
		int rs = root->val;
		root = root->right;
		if (root != nullptr) {
			while (root) {
				s.push(root);
				root = root->left;
			}
		}
		return rs;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (root == nullptr&&s.empty())
			return false;
		else
			return true;
	}
};