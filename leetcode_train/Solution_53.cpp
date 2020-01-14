#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an integer array nums, find the contiguous subarray 
//(containing at least one number) which has the largest sum and return its sum.


//1.当求和小于0时，就重新求和，负数一定不会对正数部分有贡献


//2.分治法
//mid将数组一分为2，假设最大数组和分别在左边，右边和横跨两个数组
//横跨两个数组时，mid在最优解中，从mid到left求和，记录最大值
//从mid到right求和，记录最大值
//返回三个值中的最大值



class Solution_53 {
public:

	int maxSubArray_dd(vector<int>& nums) {
		return maxSubArray_dd(nums, 0, nums.size() - 1);
	}
	int maxSubArray_dd(vector<int>& nums, int left, int right) {
		if (left > right) {
			return INT_MIN;
		}
		int mid = left + (right - left) / 2;
		int l_max = maxSubArray_dd(nums, left, mid - 1);
		int r_max = maxSubArray_dd(nums, mid + 1, right);
		int mid_left_max = 0;
		for (int i = mid - 1, sum = 0; i >= left; i--) {
			sum += nums[i];
			mid_left_max = max(sum, mid_left_max);
		}
		int mid_right_max = 0;
		for (int i = mid + 1, sum = 0; i <= right; i++) {
			sum += nums[i];
			mid_right_max = max(mid_right_max, sum);
		}
		return max(max(l_max, r_max), mid_left_max + mid_right_max + nums[mid]);

	}


	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int sum = 0;
		int rs = nums[0];
		for (int i = 0; i<nums.size(); i++) {
			sum += nums[i];
			rs = max(rs, sum);
			if (sum<0) {
				sum = 0;
				continue;
			}
		}
		return rs;

	}
};