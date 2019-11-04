
#include"TreeNode.h"
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//Consider all the leaves of a binary tree.From left to right order, the values of those leaves form a leaf value sequence.
//
//
//
//For example, in the given tree above, the leaf value sequence is(6, 7, 4, 9, 8).
//
//Two binary trees are considered leaf - similar if their leaf value sequence is the same.
//
//Return true if and only if the two given trees with head nodes root1 and root2 are leaf - similar.


//分别找到两棵树的叶子节点
//比较是否相同



class Solution_872 {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int>r_1_leaf;
		vector<int>r_2_leaf;
		dfs(r_1_leaf, root1);
		dfs(r_2_leaf, root2);
		return r_1_leaf == r_2_leaf;


	}
	void dfs(vector<int>&leaf, TreeNode*x) {
		if (x == nullptr)
			return;
		if (x->left == NULL&&x->right == NULL)
			leaf.push_back(x->val);
		dfs(leaf, x->left);
		dfs(leaf, x->right);
	}
};