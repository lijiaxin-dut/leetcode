#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
#include<sstream>
#include"TreeNode.h"

using namespace std;

class Solution_94 {
public:
	vector<int> inorderTraversal_miro(TreeNode* root) {
		vector<int>rs;
		while (root != nullptr) {
			if (root->left == nullptr) {
				//������Ϊ��ʱ������Ҫ��ǰ���ڵ㣬ֱ�ӷ��ʼ���
				//��Ϊǰ���ڵ�Ϊ�Լ��������Ѿ������ʹ�
				//1
				//  \
				//   2  2��ǰ���ڵ�Ϊ1���Ѿ����ʹ�
				//   1
				// /
				//0     0������ǰ���ڵ�
				rs.push_back(root->val);
				root = root->right;
			}
			else {
				TreeNode*pre = get_pre_node(root);
				if (pre->right == nullptr) {
					pre->right = root;
					root = root->left;
				}
				else if (pre->right == root) {
					rs.push_back(root->val);
					pre->right = nullptr;
					root = root->right;

				}
			}
		}
		return rs;

	}
	TreeNode*get_pre_node(TreeNode*n) {
		TreeNode*pre = n;
		if (pre->left != nullptr) {
			pre = pre->left;
			while (pre->right != nullptr&&pre->right != n)
				pre = pre->right;
		}
		return pre;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>rs;
		stack<TreeNode*>right_child;
		while (root != NULL || !right_child.empty()) {
			while (root != NULL) {
				right_child.push(root);
				root = root->left;
			}
			root = right_child.top();
			right_child.pop();
			rs.push_back(root->val);
			root = root->right;
		}
		return rs;

	}
};
