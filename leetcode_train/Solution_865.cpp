#include"TreeNode.h"
#include<vector>

using namespace std;
//Smallest Subtree with all the Deepest Nodes
//Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.
//
//A node is deepest if it has the largest depth possible among any node in the entire tree.
//
//The subtree of a node is that node, plus the set of all descendants of that node.
//
//Return the node with the largest depth such that it contains all the deepest nodes in its subtree.


//1.找到最后一层的节点，不断的找调用LCA找父节点
//最后的结果就是rs

//2.自底向上递归
//函数返回一个pair
//第一个参数为最大深度，第二个参数为最大深度对应的子树
//
//if left depth == right depth,
//deepest nodes both in the left and right subtree,
//return pair(left.depth + 1, root)

//if left depth > right depth,
//deepest nodes only in the left subtree,
//return pair(left.depth + 1, left subtree)
//
//if left depth < right depth,
//	deepest nodes only in the right subtree,
//	return pair(right.depth + 1, right subtree)

class Solution_865 {
	TreeNode* subtreeWithAllDeepest_1(TreeNode* root) {
		return help_1(root).second;
	}
	pair<int, TreeNode*>help_1(TreeNode*node) {
		if (node == nullptr)
			return make_pair(0, nullptr);
		auto left = help_1(node->left);
		auto right = help_1(node->right);
		if (left.first == right.first)
			return make_pair(left.first + 1, node);
		else {
			if (left.first>right.first)
				return make_pair(left.first + 1, left.second);
			else
				return make_pair(right.first + 1, right.second);
		}


	}







	TreeNode *LCA(TreeNode*root, TreeNode*p1, TreeNode*p2) {
		if (root == nullptr || root == p1 || root == p2)
			return root;
		auto left = LCA(root->left, p1, p2);
		auto right = LCA(root->right, p1, p2);
		if (left != nullptr&&right != nullptr)
			return root;
		if (left == nullptr)
			return right;
		else
			return left;
	}
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if (root == nullptr)
			return root;
		vector<vector<TreeNode*>>levels;
		dfs(root, levels, 0);
		auto depest_level = levels.back();//最后一层的节点
		auto help_node = depest_level[0];
		for (auto &one_node : depest_level)
			help_node = LCA(root, one_node, help_node);
		return help_node;
	}
	void dfs(TreeNode*node, vector<vector<TreeNode*>>&levels, int cur_level) {
		if (node == nullptr)
			return;
		if (cur_level == levels.size())
			levels.emplace_back(vector<TreeNode*>{node});
		else
			levels[cur_level].push_back(node);
		dfs(node->left, levels, cur_level + 1);
		dfs(node->right, levels, cur_level + 1);
	}
};