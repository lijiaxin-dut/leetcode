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

//nullptr可以防灾容器中

class Solution_95 {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return{};
		vector<int>nums;
		for (int i = 1; i <= n; i++) {
			nums.push_back(i);
		}
		return help(nums, 0, n - 1);

	}
	vector<TreeNode*>help(vector<int>&nums, int start, int end) {
		if (start>end)
			return vector<TreeNode*>{nullptr};
		if (start == end)
			return vector<TreeNode*>{new TreeNode(nums[start])};
		vector<TreeNode*>rs;
		//i位置的做根节点
		for (int i = start; i <= end; i++) {
			auto left = help(nums, start, i - 1);
			auto right = help(nums, i + 1, end);
			for (auto one_left : left) {
				for (auto one_right : right) {
					TreeNode *new_node = new TreeNode(nums[i]);
					new_node->left = one_left;
					new_node->right = one_right;
					rs.push_back(new_node);
				}
			}
		}
		return rs;

	}
};

//int main() {
//	Solution_95 s;
//	auto t=s.generateTrees(5);
//	return 0;
//}