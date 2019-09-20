#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"TreeNode.h"
using namespace std;


//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
//Example:
//
//Input: 3
//	Output :
//	[
//		[1, null, 3, 2],
//		[3, 2, null, 1],
//		[3, 1, null, null, 2],
//		[2, 1, 3],
//		[1, null, 2, null, 3]
//	]
//	   Explanation:
//				  The above output corresponds to the 5 unique BST's shown below:
//
//					  1         3     3      2      1
//					  \ / / / \      \
//					  3     2     1      1   3      2
//					  / / \                 \
//					  2     1         2                 3


//dfs
//对于任意一个根节点
//左右子树所有的组合都生成一个根节点
//子树可以公用

class Solution_95 {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return{};
		return helper(1, n);
	}
	vector<TreeNode*> helper(int start, int end) {
		if (start > end)
			return{ nullptr };
		vector<TreeNode*> res;
		for (int i = start; i <= end; ++i) {
			auto left = helper(start, i - 1), right = helper(i + 1, end);
			//子树公用
			for (auto a : left) {
				for (auto b : right) {
					TreeNode *node = new TreeNode(i);
					node->left = a;
					node->right = b;
					res.push_back(node);
				}
			}
		}
		return res;
	}
};

//int main() {
//	Solution_95 s;
//	auto t=s.generateTrees(5);
//	return 0;
//}