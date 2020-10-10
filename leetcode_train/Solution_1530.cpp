#include<vector>
#include"TreeNode.h"

using namespace std;

//给你二叉树的根节点 root 和一个整数 distance 。
//
//如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。
//
//返回树中 好叶子节点对的数量 。
//

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/

//dfs返回每个节点到叶子节点的距离
//

class Solution {
public:
	int countPairs(TreeNode* root, int distance) {
		int rs = 0;
		auto i = dfs(root, distance, rs);
		return rs;
	}
	vector<int>dfs(TreeNode *node, int distance, int &rs) {
		if (node == nullptr)
			return{};
		if (node->left == nullptr && node->right == nullptr) {
			return{ 0 };
		}
		vector<int>res;
		vector<int>left = dfs(node->left, distance, rs);
		for (auto &i : left) {
			if (++i>distance)
				continue;
			res.push_back(i);
		}
		vector<int>right = dfs(node->right, distance, rs);
		for (auto &i : right) {
			if (++i>distance)
				continue;
			res.push_back(i);
		}
		for (auto l : left) {
			for (auto r : right) {
				if (l + r <= distance)
					rs++;
			}
		}
		return res;
	}
};