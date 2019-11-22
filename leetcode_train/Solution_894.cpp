#include"TreeNode.h"
#include<vector>

using namespace std;


//A full binary tree is a binary tree where each node has exactly 0 or 2 children.
//
//Return a list of all possible full binary trees with N nodes.Each element of the answer is the root node of one possible tree.
//
//Each node of each tree in the answer must have node.val = 0.
//
//You may return the final list of trees in any order.


//自底向上递归
//不断的将数字进行拆分
//7 = 1 + 5
//5 = 1 + 3

class Solution_894 {
	void generate_new_node(vector<TreeNode*>&cur_N, vector<TreeNode*>&l, vector<TreeNode*>&r) {
		for (auto one_l : l) {
			for (auto one_r : r) {
				TreeNode *new_node = new TreeNode(0);
				new_node->left = one_l;
				new_node->right = one_r;
				cur_N.push_back(new_node);
			}
		}
	}
public:
	vector<TreeNode*> allPossibleFBT(int N) {
		auto t = help(N);
		return t;
	}

	vector<TreeNode*>help(int N) {
		if (N == 1)
			return vector<TreeNode*>{new TreeNode(0)};
		vector<TreeNode*>cur_N;
		int left = 1;
		int right = N - left - 1;
		while (left <= right) {
			auto l = help(left);
			auto r = help(right);
			generate_new_node(cur_N, l, r);
			if (left != right)
				generate_new_node(cur_N, r, l);
			left += 2;
			right = N - left - 1;
		}
		return cur_N;


	}
};