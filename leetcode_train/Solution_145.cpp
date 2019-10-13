#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include"TreeNode.h"
using namespace std;

//Given a binary tree, return the postorder traversal of its nodes' values.
//
//Example:
//
//Input: [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//	Output: [3, 2, 1]
//	Follow up : Recursive solution is trivial, could you do it iteratively ?


//ʹ��pre�����һ�η��ʵĽڵ�
//���ҽڵ�Ϊ�գ������ϴη��ʽڵ�Ϊ�ýڵ���ҽڵ�
//���Է��ʵ�ǰ�ڵ�



class Solution_145 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int>rs;
		stack<TreeNode*>my_stack;
		TreeNode *pre = root;
		while (root) {
			while (root->left != NULL) {
				my_stack.push(root);
				root = root->left;
			}
			while (root != NULL && (root->right == NULL || root->right == pre)) {
				rs.push_back(root->val);
				pre = root;
				if (my_stack.empty()) {
					return rs;
				}
				root = my_stack.top();
				my_stack.pop();
			}
			my_stack.push(root);
			root = root->right;
		}
		return rs;
	}
};
