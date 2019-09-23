#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
#include<sstream>
#include"TreeNode.h"

using namespace std;

class Solution_94 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>rs;
		stack<TreeNode*>right_child;
		while (root != NULL || !right_child.empty()) {
			while (root != NULL) {
				right_child.push(root);
				root = root->left;
			}
			root = right_child.top();
			right_child.pop();
			rs.push_back(root->val);
			root = root->right;
		}
		return rs;

	}
};
