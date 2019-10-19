#include"TreeNode.h"
#include<queue>


using namespace std;
//
//Given a binary search tree(BST), find the lowest common ancestor(LCA) of two given nodes in the BST.
//
//According to the definition of LCA on Wikipedia : 
//��The lowest common ancestor is defined between 
//two nodes p and q as the lowest node in T that 
//has both p and q as descendants(where we allow 
//a node to be a descendant of itself).��

//�ҵ���һ��>=С�ڵ�  <=��ڵ�� �ڵ����LCA

//��α����ҵ��ýڵ�
//���߸��ݹ�ϵ���ж�������������������Ѱ��

class Solution_235 {
public:
	TreeNode* lowestCommonAncestor_1(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val>q->val)
			swap(p, q);
		queue<TreeNode*>Q;
		Q.push(root);
		while (!Q.empty()) {
			root = Q.front();
			Q.pop();
			if (root->val >= p->val&&root->val <= q->val)
				return root;
			if (root->left)
				Q.push(root->left);
			if (root->right)
				Q.push(root->right);
		}
		return NULL;
	}


	TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (true) {
			if (root->val>p->val&&root->val>q->val) {
				root = root->left;
			}
			else if (root->val<p->val&&root->val<q->val) {
				root = root->right;
			}
			else
				return root;
		}

	}

};