#include<vector>
#include"TreeNode.h"
#include<stack>
using namespace std;

////Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.


//遍历整棵树，找到两个符合条件的几点即可
//1.先得到中序遍历序列，然后找到两个需要修改的节点
//2.递归，在递归的过程中记录两个需要修改的指针
//first 指向第一个元素
//second指向第二个元素
//6, 3, 4, 5, 2   6为第一个元素，2为第二个元素
//pre指向当前遍历的前一个元素


class Solution_99 {
public:
	TreeNode *first = nullptr, *second = nullptr, *pre = nullptr;
	void recoverTree_res(TreeNode* root) {
		inorder(root);
		swap(first->val, second->val);
	}
	void inorder_res(TreeNode*root) {
		if (root == nullptr)
			return;
		inorder(root->left);
		if (pre != nullptr) {
			if (first == nullptr&&pre->val >= root->val)
				first = pre;
			if (first != nullptr&&pre->val >= root->val)
				second = root;
		}
		pre = root;
		inorder(root->right);

	}
	void recoverTree(TreeNode* root) {
		if (root == nullptr)
			return;
		vector<TreeNode*> in_order_nodes = inorder(root);
		int first_peak = -1;
		for (int i = 0; i<in_order_nodes.size() - 1; i++) {
			if (in_order_nodes[i]->val>in_order_nodes[i + 1]->val) {
				first_peak = i;
				break;
			}
		}
		int second_peak = -1;
		for (int j = first_peak + 1; j<in_order_nodes.size() - 1; j++) {
			if (in_order_nodes[j]->val>in_order_nodes[j + 1]->val) {
				second_peak = j;
				break;
			}
		}
		if (second_peak == -1) {
			swap(in_order_nodes[first_peak]->val, in_order_nodes[first_peak + 1]->val);
		}
		else {
			swap(in_order_nodes[first_peak]->val, in_order_nodes[second_peak + 1]->val);
		}

	}
	vector<TreeNode*>inorder(TreeNode *root) {
		stack<TreeNode*>s;
		vector<TreeNode*>rs;
		while (!s.empty() || root!=nullptr) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			rs.push_back(root);
			root = root->right;
		}
		return rs;

	}
};

