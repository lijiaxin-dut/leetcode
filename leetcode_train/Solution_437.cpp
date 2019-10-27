#include"TreeNode.h"
#include<iostream>

using namespace std;



//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards(traveling only from parent nodes to child nodes).
//
//The tree has no more than 1, 000 nodes and the values are in the range - 1, 000, 000 to 1, 000, 000.
//
//Example:
//
//root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1], sum = 8
//
//10
/// \
//5 - 3
/// \    \
//3   2   11
/// \   \
//3 - 2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. - 3 -> 11


//dfs�������һ���ڵ㣬��������ڵ㿪ʼ����·����
//rs+=dfs(root,sum);
//rs += pathSum(root->left, sum);
//rs += pathSum(root->right, sum);


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution_437 {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;
		int rs = 0;
		rs += dfs(root, sum);
		rs += pathSum(root->left, sum);
		rs += pathSum(root->right, sum);
		return rs;
	}
	int dfs(TreeNode *x, int sum) {
		int rs = 0;
		if (x == NULL)
			return 0;
		if (x->val == sum)
			rs++;
		rs += dfs(x->left, sum - x->val);
		rs += dfs(x->right, sum - x->val);
		return rs;
	}
};
//
//int main() {
//	Solution_437 s;
//	TreeNode *n1 = new TreeNode(10);
//	TreeNode *n2 = new TreeNode(5);
//	TreeNode *n3 = new TreeNode(-3);
//	n1->left = n2;
//	n1->right = n3;
//	TreeNode *n4 = new TreeNode(3);
//	TreeNode *n5 = new TreeNode(2);
//	n2->left = n4;
//	n2->right = n5;
//	TreeNode *n6 = new TreeNode(11);
//	n3->right = n6;
//
//	TreeNode *n7 = new TreeNode(3);
//	TreeNode *n8 = new TreeNode(-2);
//	TreeNode *n9 = new TreeNode(1);
//	n4->left=n7;
//	n4->right = n8;
//	n5->right = n9;
//	cout<<s.pathSum(n1,8);
//}