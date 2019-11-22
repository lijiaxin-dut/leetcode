#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;

//A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
//
//Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations :
//
//CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
//CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
//CBTInserter.get_root() will return the head node of the tree.

//把所有节点存储到数组中
//根节点标号为1

//假设一个节点的id为i
//则左孩子id为2*i
//右孩子id为2*i+1

class CBTInserter {
	vector<TreeNode*>all_nodes;
	TreeNode*root;
public:
	CBTInserter(TreeNode* root) {
		this->root = root;
		queue<TreeNode*>q;
		q.push(root);
		all_nodes.push_back(new TreeNode(-1));
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			all_nodes.push_back(t);
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
	}

	int insert(int v) {
		int cur_index = all_nodes.size();
		int p_index = cur_index / 2;
		TreeNode*new_node = new TreeNode(v);
		if (all_nodes[p_index]->left == nullptr)
			all_nodes[p_index]->left = new_node;
		else
			all_nodes[p_index]->right = new_node;
		all_nodes.push_back(new_node);
		return all_nodes[p_index]->val;
	}

	TreeNode* get_root() {
		return root;
	}
};