#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include"TreeNode.h"

using namespace std;

//Given a binary tree, flatten it to a linked list in - place.
//
//For example, given the following tree :
//
//1
/// \
//2   5
/// \   \
//3   4   6
//The flattened tree should look like :
//
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6



//将一颗二叉树改为链表
//类似于前序遍历
//把右节点存起来
//然后把右节点指向左节点
//左子树置空


//为空时，考虑栈种的节点



class Solution_114 {
public:
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		TreeNode*pre_node = root;
		stack<TreeNode*>childs;
		while (!childs.empty() || root != NULL) {
			if (root->right != NULL)
				childs.push(root->right);
			root->right = root->left;
			pre_node = root;
			if (root != NULL) {
				root->left = NULL;
			}
			root = root->right;
			if (root == NULL) {
				if (childs.empty())
					return;
				root = childs.top();
				pre_node->right = root;
				childs.pop();
			}
		}
	}
};
//int main() {
//	TreeNode *t1 = new TreeNode(1);
//	TreeNode *t2 = new TreeNode(2);
//	TreeNode *t3 = new TreeNode(5);
//	t1->left = t2;
//	t1->right = t3;
//	/*TreeNode *t4 = new TreeNode(11);
//	t2->left = t4;
//	TreeNode *t5 = new TreeNode(7);
//	TreeNode *t6 = new TreeNode(2);
//	t4->left = t5;
//	t4->right = t6;*/
//	Solution_114 s;
//	s.flatten(t1);
//
//}