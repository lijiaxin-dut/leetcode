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

//为了防止溢出，每一层都重新计数

class Solution_662 {
public:
	int widthOfBinaryTree(TreeNode* root) {
		deque<pair<TreeNode*, int >>q;
		int rs = 0;
		if (root == nullptr)
			return 0;
		q.push_back(make_pair(root, 1));
		while (!q.empty()) {
			int cur_size = q.size();
			int off_size = q.back().second;
			rs = max(rs, q.back().second - q.front().second + 1);
			for (int i = 0; i<cur_size; i++) {
				auto cur_node = q.front();
				q.pop_front();
				if (cur_node.first->left) {
					q.push_back(make_pair(cur_node.first->left, 2 * cur_node.second - off_size));
				}
				if (cur_node.first->right) {
					q.push_back(make_pair(cur_node.first->right, 2 * cur_node.second + 1 - off_size));
				}
			}
		}
		return rs;

	}
};