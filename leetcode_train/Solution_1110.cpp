#include<vector>
#include"TreeNode.h"
#include<unordered_set>

//给出二叉树的根节点 root，树上每个节点都有一个不同的值。
//
//如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
//
//返回森林中的每棵树。你可以按任意顺序组织答案。



//dfs
//dfs函数返回是否删除当前节点



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
class Solution {
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int>s(to_delete.begin(), to_delete.end());
		vector<TreeNode*>rs;
		dfs(root, s, rs, false);
		return rs;
	}

	bool dfs(TreeNode *node, unordered_set<int>&s, vector<TreeNode*>&rs, bool parent_exit) {
		if (node == nullptr)
			return false;
		bool del = s.find(node->val) != s.end();//not exit  del == true
		if (dfs(node->left, s, rs, !del)) {
			node->left = nullptr;
		}
		if (dfs(node->right, s, rs, !del)) {
			node->right = nullptr;
		}
		if (del == false && parent_exit == false)
			rs.push_back(node);

		return del;
	}


};