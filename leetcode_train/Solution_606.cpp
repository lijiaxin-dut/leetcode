#include"TreeNode.h"
#include<string>

using namespace std;


//You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
//
//The null node needs to be represented by empty parenthesis pair "()".And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
//
//Example 1:
//Input: Binary tree : [1, 2, 3, 4]
//	1
//	/ \
//	2     3
//	/
//	4
//
//	Output: "1(2(4))(3)"
//
//	Explanation : Originallay it needs to be "1(2(4)())(3()())",
//	but you need to omit all the unnecessary empty parenthesis pairs.
//	And it will be "1(2(4))(3)".

//跳过空节点
//当存在右节点而不存在左节点时
//需要添加括号

//dfs


class Solution_606 {
public:
	string tree2str(TreeNode* t) {
		string rs;
		dfs(t, rs);
		return rs;
	}
	void dfs(TreeNode *node, string &rs) {
		if (node == nullptr) {
			return;
		}
		rs += to_string(node->val);
		if (node->left == nullptr&&node->right == nullptr) {
			return;
		}
		if (node->left != nullptr) {
			rs += "(";
			dfs(node->left, rs);
			rs += ")";
		}
		if (node->right != nullptr) {
			if (node->left == nullptr) {
				rs += "()";
			}
			rs += "(";
			dfs(node->right, rs);
			rs += ")";
		}
	}
};