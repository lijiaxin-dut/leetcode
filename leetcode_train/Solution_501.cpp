#include<vector>
#include"TreeNode.h"

using namespace std;

//Given a binary search tree(BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than or equal to the node's key.
//The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//Both the left and right subtrees must also be binary search trees.
//
//
//For example :
//Given BST[1, null, 2, 2],
//
//1
//\
//2
///
//2


//是二叉搜索树，中序遍历结果是有序的
//记录前驱节点， 当前频率 ，最大频率



class Solution_501 {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int>rs;
		TreeNode *pre = nullptr;
		int max_cnt = 0;
		int cur_cnt = 1;//为了保存第一个访问的节点，因为pre为空，
		dfs(root, pre, rs, max_cnt, cur_cnt);
		return rs;
	}
	void dfs(TreeNode *node, TreeNode *&pre, vector<int>&rs, int &max_cnt, int &cur_cnt) {
		if (node == nullptr)
			return;
		dfs(node->left, pre, rs, max_cnt, cur_cnt);
		if (pre != nullptr) {
			if (node->val == pre->val)
				cur_cnt++;
			else
				cur_cnt = 1;
		}
		if (cur_cnt >= max_cnt) {
			if (cur_cnt>max_cnt)
				rs.clear();
			rs.push_back(node->val);
			max_cnt = cur_cnt;
		}
		pre = node;
		dfs(node->right, pre, rs, max_cnt, cur_cnt);
	}
};