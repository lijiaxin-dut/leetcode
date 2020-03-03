#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


//Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
//
//	Note: n will be less than 15, 000.
//
//	Example 1 :
//	Input : [1, 2, 3, 4]
//
//	Output : False
//
//	Explanation : There is no 132 pattern in the sequence.

//1.三层循环
//2.两层循环
//考虑j k循环，使用一个变量保存当前最小的j
//3.stack
//stack递增的顺序保存second数字，top元素最小
//遇到更大就弹出，并且使用thrid保存，
//thrid是小于second的数字并且接近second
class Solution {
public:

	bool find132pattern_stack(vector<int>& nums) {
		int thrid = INT_MIN;
		stack<int>s;
		int n = nums.size();
		for (int i = n - 1; i >= 0; i--) {
			if (nums[i]<thrid)
				return true;
			while (!s.empty() && nums[i]>s.top()) {
				thrid = s.top();
				s.pop();
			}
			s.push(nums[i]);
		}
		return false;
	}
	bool find132pattern(vector<int>& nums) {
		int n = nums.size();
		int min_i = INT_MAX;
		for (int j = 0; j<n; j++) {
			min_i = min(nums[j], min_i);
			for (int k = j + 1; k<n; k++) {
				if (nums[k]<nums[j] && min_i<nums[k])
					return true;
			}
		}

		return false;
	}
};