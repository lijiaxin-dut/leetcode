#include"TreeNode.h"
#include<vector>
#include<unordered_map>
#include<string>
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



class Solution {
	vector<TreeNode*>rs;
	unordered_map<string, int>m;
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		rs.clear();
		m.clear();
		dfs(root);
		return rs;
	}
	string dfs(TreeNode*node) {
		if (node == nullptr)
			return "#";
		string cur = to_string(node->val);
		cur += "," + dfs(node->left) + "," + dfs(node->right);
		if (m.count(cur) && m[cur] == 1)
			rs.push_back(node);
		m[cur]++;
		return cur;
	}
};