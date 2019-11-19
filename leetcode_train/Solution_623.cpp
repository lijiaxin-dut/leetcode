#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d.The root node is at depth 1.
//
//The adding rule is : given a positive integer depth d, for each NOT null tree nodes N in depth d - 1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root.If depth d is 1 that means there is no depth d - 1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.
//
//Example 1 :
//	Input :
//	A binary tree as following :
//4
/// \
//2     6
/// \ /
//3   1 5
//
//v = 1
//
//d = 2
//
//Output:
//4
/// \
//1   1
/// \
//2       6
/// \ /
//3   1   5


//找到d-1层的节点

class Solution_623 {
	vector<TreeNode*>d_level(TreeNode*root, int d) {
		int cur_level = 0;
		queue<TreeNode*>q;
		vector<TreeNode*>rs;
		q.push(root);
		while (!q.empty()) {
			int cur_level_size = q.size();
			cur_level++;
			for (int i = 0; i<cur_level_size; i++) {
				auto cur_node = q.front();
				q.pop();
				if (cur_level == d - 1)
					rs.push_back(cur_node);
				if (cur_node->left)
					q.push(cur_node->left);
				if (cur_node->right)
					q.push(cur_node->right);
			}
			if (cur_level == d-1)
				break;
		}
		return rs;
	}
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode*new_root = new TreeNode(v);
			new_root->left = root;
			return new_root;
		}
		auto level_d_node = d_level(root, d);
		for (auto &one_node : level_d_node) {

			TreeNode*new_root_left = new TreeNode(v);
			if (one_node->left)
				new_root_left->left = one_node->left;
			one_node->left = new_root_left;
			TreeNode*new_root_right = new TreeNode(v);
			if (one_node->right)
				new_root_right->right = one_node->right;
			one_node->right = new_root_right;

		}

		return root;




	}
};