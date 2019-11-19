#include"TreeNode.h"
#include<vector>
#include<unordered_map>

using namespace std;

//Given a binary tree, return all duplicate subtrees.For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//
//Two trees are duplicate if they have the same structure with same node values.
//
//Example 1:
//
//1
/// \
//2   3
/// / \
//4   2   4
///
//4
//The following are two duplicate subtrees :
//
//2
///
//4
//and
//
//4

//1.dfs找到所有求和
//然后依次判断是否同构，TLE

//2.遍历整棵树，对所有的子树进行序列化，注意空字符串
//如果这个节点的序列化出现过，就说明有重复子树



class Solution_652 {
	unordered_map<int, vector<TreeNode*>>hash_map;
	bool is_same(TreeNode*left, TreeNode*right) {
		if (left == nullptr&&right == nullptr)
			return true;
		if (left == nullptr || right == nullptr)
			return false;
		if (left->val != right->val)
			return false;
		return is_same(left->left, right->left) && is_same(left->right, right->right);
	}
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		vector<TreeNode*>rs;
		for (auto &one_sum_val : hash_map) {
			auto &v = one_sum_val.second;
			for (int i = 0; i<v.size(); i++) {
				int old_size = v.size();
				for (int j = i + 1; j<v.size(); j++) {
					bool find = is_same(v[i], v[j]);
					if (find == true) {
						v.erase(v.begin() + j);
						j--;
					}
				}
				if (old_size != v.size()) {
					rs.push_back(v[i]);
					v.erase(v.begin() + i);
					i--;
				}
			}
		}
		return rs;

	}
	int dfs(TreeNode*node) {
		if (node == nullptr)
			return 0;
		int val = dfs(node->left) + dfs(node->right) + node->val;
		hash_map[val].push_back(node);
		return val;
	}
};