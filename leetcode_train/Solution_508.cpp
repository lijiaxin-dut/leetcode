#include"TreeNode.h"
#include<unordered_map>

using namespace std;
//
//Given the root of a tree, you are asked to find the most frequent subtree sum.The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node(including the node itself).So what is the most frequent subtree sum value ? If there is a tie, return all the values with the highest frequency in any order.
//
//Examples 1
//Input :
//
//	5
//	/ \
//	2 - 3

//dfs 计算每个子树和
//记录最大的频率。使用map保存子树和的频率

class Solution_508 {
	unordered_map<int, int>hash_map;
	int max_frequent = 0;
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {

		dfs(root);
		vector<int>rs;
		for (auto &one : hash_map) {
			if (one.second == max_frequent)
				rs.push_back(one.first);
		}
		return rs;

	}
	int dfs(TreeNode *node) {
		if (node == nullptr)
			return 0;
		int val = 0;
		val += dfs(node->left);
		val += dfs(node->right);
		val += node->val;
		hash_map[val]++;
		if (hash_map[val]>max_frequent)
			max_frequent = hash_map[val];
		return val;

	}
};