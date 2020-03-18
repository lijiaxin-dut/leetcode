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


//������һ����ȫ��������
//������ڵ����Ϊn
//���ӽڵ����Ϊ2n��2n+1

//�ж�ÿһ���һ�������λ�ú͵ڶ����ڵ��λ�ò�������ֵ

//Ϊ�˷�ֹ�����ÿһ�㶼���¼���

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