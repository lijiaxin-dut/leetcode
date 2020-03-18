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

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode*new_root = new TreeNode(v);
			if (root == nullptr)
				return new_root;
			new_root->left = root;
			return new_root;
		}
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty()) {
			d--;
			if (d == 1)
				break;
			int cur_size = q.size();
			for (int i = 0; i<cur_size; i++) {
				auto node = q.front();
				q.pop();
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		while (!q.empty()) {
			TreeNode*new_node_left = new TreeNode(v);
			TreeNode*new_node_right = new TreeNode(v);
			auto cur = q.front();
			q.pop();
			new_node_left->left = cur->left;
			new_node_right->right = cur->right;
			cur->left = new_node_left;
			cur->right = new_node_right;
		}
		return root;

	}
};