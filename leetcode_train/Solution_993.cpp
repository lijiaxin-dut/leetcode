#include<vector>
#include"TreeNode.h"
#include<queue>

using namespace std;


//In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k + 1.
//
//Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
//
//We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
//
//Return true if and only if the nodes corresponding to the values x and y are cousins.


//bfs


class Solution_993 {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (root->val == x || root->val == y)
			return false;
		int x_depth = 0;
		int y_depth = 0;
		auto x_parent = find_parent(root, x, x_depth);
		auto y_parent = find_parent(root, y, y_depth);
		if (x_depth != y_depth || x_parent == y_parent)
			return false;
		return true;
	}
	TreeNode* find_parent(TreeNode*node, int x, int &depth) {
		queue<TreeNode*>q;
		q.push(node);
		int level = 0;
		while (!q.empty()) {
			int level_size = q.size();
			for (int i = 0; i<level_size; i++) {
				auto t = q.front();
				q.pop();
				if (t->left) {
					q.push(t->left);
					if (t->left->val == x) {
						depth = level;
						return t;
					}
				}
				if (t->right) {
					q.push(t->right);
					if (t->right->val == x) {
						depth = level;
						return t;
					}
				}
			}
			level++;
		}
		return nullptr;

	}
};