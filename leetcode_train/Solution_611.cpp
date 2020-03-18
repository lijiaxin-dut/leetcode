#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array consists of non - negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
//Example 1:
//Input: [2, 2, 3, 4]
//	Output : 3
//	Explanation :
//	Valid combinations are :
//	   2, 3, 4 (using the first 2)
//		   2, 3, 4 (using the second 2)
//		   2, 2, 3

//首先排序
//然后调用自己实现的lower_bound函数

class Solution {
	int lower_bound(vector<int>&nums, int i, int j, int target) {
		int left = i;
		int right = j;
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		return left;

	}
public:
	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int rs = 0;
		for (int i = 0; i<nums.size(); i++) {
			for (int j = i + 1; j<nums.size(); j++) {
				int two_sum = nums[i] + nums[j];
				auto it = lower_bound(nums, j + 1, nums.size(), two_sum);
				rs += it - (j + 1);
			}
		}
		return rs;
	}
};