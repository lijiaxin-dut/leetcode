#include"TreeNode.h"
#include<algorithm>

using namespace std;


//
//Given a binary search tree(BST), find the lowest common ancestor(LCA) of two given nodes in the BST.
//
//According to the definition of LCA on Wikipedia : 
//“The lowest common ancestor is defined between 
//two nodes p and q as the lowest node in T that 
//has both p and q as descendants(where we allow 
//a node to be a descendant of itself).”



//给定一个根节点，分别在左右子树查找p,q
//若p,q分布在左右子树中
//则该节点就是LCA节点
//不断的将该节点自底向上返回即可



class Solution_236 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		if (root == NULL || root == p || root == q)
			return root;
		TreeNode*left = lowestCommonAncestor(root->left, p, q);
		TreeNode*right = lowestCommonAncestor(root->right, p, q);
		if (left&&right)
			return root;
		if (left == NULL)
			return right;
		else
			return left;

	}
};

//int main() {
//	TreeNode *t1 = new TreeNode(3);
//	TreeNode *t2 = new TreeNode(5);
//	TreeNode *t3 = new TreeNode(6);
//	TreeNode *t4 = new TreeNode(2);
//	TreeNode *t5 = new TreeNode(7);
//	TreeNode *t6 = new TreeNode(4);
//
//
//	t1->left = t2;
//	t2->left = t3;
//	t2->right = t4;
//	t4->left = t5;
//	t4->right = t6;
//	Solution_236 s;
//	s.lowestCommonAncestor(t1, t3, t5);
//
//}