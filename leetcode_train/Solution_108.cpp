#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;

//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted array : [-10, -3, 0, 5, 9],
//
//One possible answer is : [0, -3, 9, -10, null, 5], which represents the following height balanced BST :
//
//0
/// \
//- 3   9
/// /
//-10  5

//每次找数组中间的节点作为根节点
//左子树由[left,mid-1]构成
//右子树由[mid+1,right]构成



class Solution_108 {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		return help(left, right, nums);

	}
	TreeNode* help(int left, int right, vector<int>&nums) {
		if (left>right)
			return NULL;
		if (left == right)
			return new TreeNode(nums[left]);
		int mid = left + (right - left) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = help(left, mid - 1, nums);
		root->right = help(mid + 1, right, nums);
		return root;
	}
};