#include<vector>
#include"TreeNode.h"

using namespace std;

//����������ĸ��ڵ� root ��һ������ distance ��
//
//��������������� Ҷ �ڵ�֮��� ���·������ С�ڻ��ߵ��� distance �������ǾͿ��Թ���һ�� ��Ҷ�ӽڵ�� ��
//
//�������� ��Ҷ�ӽڵ�Ե����� ��
//

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/

//dfs����ÿ���ڵ㵽Ҷ�ӽڵ�ľ���
//

class Solution {
public:
	int countPairs(TreeNode* root, int distance) {
		int rs = 0;
		auto i = dfs(root, distance, rs);
		return rs;
	}
	vector<int>dfs(TreeNode *node, int distance, int &rs) {
		if (node == nullptr)
			return{};
		if (node->left == nullptr && node->right == nullptr) {
			return{ 0 };
		}
		vector<int>res;
		vector<int>left = dfs(node->left, distance, rs);
		for (auto &i : left) {
			if (++i>distance)
				continue;
			res.push_back(i);
		}
		vector<int>right = dfs(node->right, distance, rs);
		for (auto &i : right) {
			if (++i>distance)
				continue;
			res.push_back(i);
		}
		for (auto l : left) {
			for (auto r : right) {
				if (l + r <= distance)
					rs++;
			}
		}
		return res;
	}
};