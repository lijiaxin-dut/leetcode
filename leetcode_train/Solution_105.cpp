#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"TreeNode.h"

using namespace std;

//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3, 9, 20, 15, 7]
//inorder = [9, 3, 15, 20, 7]
//Return the following binary tree :
//
//3
/// \
//9  20
/// \
//15   7

//前序遍历：根-左-右
//中序遍历：左-根-右
//前序遍历的第一个节点为根节点，找到中序根节点所在的位置
//递归的进行下去

class Solution_105 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return help(preorder, 0, preorder.size(), inorder, 0, inorder.size());
	}
	TreeNode *help(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end) {
		//if(preorder.empty())
		//     return NULL;
		if (p_start == p_end)
			return NULL;
		TreeNode *root = new TreeNode(preorder[p_start]);
		//找到分界线,一定会找到index
		int length = 0;
		for (int index=i_start; index<i_end; index++) {		
			if (inorder[index] == preorder[p_start]) {
				break;
			}
			length++;
		}
		root->left = help(preorder, p_start + 1, p_start + length+1, inorder, i_start, i_start + length);
		root->right = help(preorder, p_start + 1+ length, p_end, inorder, i_start + length+1 , i_end);
		return root;

	}
};

//int main() {
//	Solution_105 s;
//	vector<int>p{ 3,9,20,15,7 };
//	vector<int>in{ 9,3,15,20,7 };
//	s.buildTree(p, in);
//}