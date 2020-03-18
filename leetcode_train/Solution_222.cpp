#include<queue>
#include"TreeNode.h"


using namespace std;
//Given a complete binary tree, count the number of nodes.

//慢二叉树的节点个数
////(2 ^ h) - 1

class Solution_222 {
public:
	int countNodes_1(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*>Q;
		Q.push(root);
		int rs = 0;
		while (!Q.empty()) {
			rs++;
			auto r = Q.front();
			Q.pop();
			if (r->left)
				Q.push(r->left);
			if (r->right)
				Q.push(r->right);
		}
		return rs;
	}

	int countNodes_2(TreeNode* root) {
		if (root == NULL)
			return 0;
		return 1 + countNodes_2(root->left) + countNodes_2(root->right);
	}


	//首先判断一颗二叉树是不是完美二叉树
	//左右高度相等即可
	//返回pow(2,h)-1即可
	//否则按顺序遍历

	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left_hi = 0;
		int right_hi = 0;
		TreeNode*p_left = root;
		while (p_left != NULL) {
			left_hi++;
			p_left = p_left->left;
		}
		TreeNode*p_right = root;
		while (p_right != NULL) {
			right_hi++;
			p_right = p_right->right;
		}
		if (left_hi == right_hi)
			return pow(2, left_hi) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}

	int count_level_3(TreeNode*node) {
		int rs = 0;
		while (node) {
			rs++;
			node = node->left;
		}
		return rs;
	}
public:
	//分别计算左右子树的高度。
	int countNodes_3(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int h_left = count_level_3(root->left);
		int h_right = count_level_3(root->right);
		if (h_left == h_right)
			return pow(2, h_left) + countNodes(root->right);
		else
			return pow(2, h_right) + countNodes(root->left);

	}
};