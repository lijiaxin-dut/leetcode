#include"TreeNode.h"
#include<vector>

using namespace std;

//Given an integer array with no duplicates.A maximum tree building on this array is defined as follow :
//
//The root is the maximum number in the array.
//The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
//The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
//Construct the maximum tree by the given array and output the root node of this tree.
//
//Example 1:
//Input: [3, 2, 1, 6, 0, 5]
//	Output : return the tree root node representing the following tree :
//
//	   6
//		   / \
//		   3     5
//		   \ /
//		   2  0
//		   \
//		   1


//递归构造，每次找数组中的最大值

class Solution_654 {
	//使用单调栈，保存所有的数节点，是一个递减栈
	//对于每个节点，父亲节点为栈中第一个大于该节点的节点
	//它的左节点是最后一个小于该元素的值
	TreeNode* constructMaximumBinaryTree_stack(vector<int>& nums) {
		vector<TreeNode*>s;
		for (int i = 0; i<nums.size(); i++) {
			TreeNode *cur = new TreeNode(nums[i]);
			while (!s.empty() && nums[i]>s.back()->val) {
				cur->left = s.back();
				s.pop_back();
			}
			if (!s.empty()) {
				s.back()->right = cur;
			}
			s.push_back(cur);
		}
		return s.front();
	}
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty())
			return nullptr;
		return help(nums, 0, nums.size() - 1);
	}
	TreeNode *help(vector<int>&nums, int start, int end) {
		if (start>end)
			return nullptr;
		if (start == end)
			return new TreeNode(nums[start]);
		int max_val_index = -1;
		int max_val = INT_MIN;
		for (int i = start; i <= end; i++) {
			if (nums[i]>max_val) {
				max_val = nums[i];
				max_val_index = i;
			}
		}
		TreeNode *new_node = new TreeNode(max_val);
		new_node->left = help(nums, start, max_val_index - 1);
		new_node->right = help(nums, max_val_index + 1, end);
		return new_node;
	}
};