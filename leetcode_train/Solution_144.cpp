#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include"TreeNode.h"
using namespace std;

//Given a binary tree, return the preorder traversal of its nodes' values.
//
//Example:
//
//Input: [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//	Output: [1, 2, 3]
//

//不断的将非空右节点放入栈中
//一直向左子树走
//


class Solution_144 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int>rs;
		stack<TreeNode*>nodes;
		while (root != NULL || !nodes.empty()) {
			if (root) {
				if (root->right != NULL)
					nodes.push(root->right);
				rs.push_back(root->val);
				root = root->left;
			}
			else {
				root = nodes.top();
				nodes.pop();
			}

		}
		return rs;


	}
};