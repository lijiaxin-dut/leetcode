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
//前序遍历的过程中，修改指针指向
//前序遍历时，保存右节点，注意不要保存空节点






class Solution_114 {
public:
	void flatten(TreeNode* root) {
		stack<TreeNode*>s;
		TreeNode *pre = nullptr;
		while (!s.empty() || root != nullptr) {
			while (root) {
				if (root->right)
					s.push(root->right);
				pre = root;
				root = root->left;
				pre->right = root;
				pre->left = nullptr;
			}
			if (s.empty())
				break;
			root = s.top();
			s.pop();
			pre->right = root;
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