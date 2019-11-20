#include"TreeNode.h"
#include<queue>

using namespace std;

//Given a binary tree, write a function to get the maximum width of the given tree.The width of a tree is the maximum width among all levels.The binary tree has the same structure as a full binary tree, but some nodes are null.
//
//The width of one level is defined as the length between the end - nodes(the leftmost and right most non - null nodes in the level, where the null nodes between the end - nodes are also counted into the length calculation.
//
//	Example 1:
//
//Input:
//
//1
/// \
//3     2
/// \     \
//5   3     9
//
//Output: 4
//	Explanation : The maximum width existing in the third level with the length 4 (5, 3, null, 9).
//


//假设是一个完全二叉树，
//假设根节点序号为n
//则子节点序号为2n和2n+1

//判断每一层第一个几点的位置和第二个节点的位置差，返回最大值



class Solution_662 {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<pair<TreeNode*, long>>q;
		q.push(make_pair(root, 1));
		unsigned long rs = 0;
		while (!q.empty()) {
			int level_size = q.size();
			unsigned long left = q.front().second;
			unsigned long right = q.front().second;
			for (int i = 0; i<level_size; i++) {
				auto t = q.front();
				q.pop();
				right = t.second;
				if (t.first->left != nullptr)
					q.push(make_pair(t.first->left, right * 2));
				if (t.first->right != nullptr)
					q.push(make_pair(t.first->right, right * 2 + 1));
			}
			rs = max(rs, right - left + 1);
		}
		return rs;
	}
};