#include<map>
#include<random>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_set>
#include<iostream>
using namespace std;

//Given an array which consists of non - negative integers and an integer m, you can split the array into m non - empty continuous subarrays.Write an algorithm to minimize the largest sum among these m subarrays.
//
//Note:
//If n is the length of array, assume the following constraints are satisfied :
//
//1 ≤ n ≤ 1000
//1 ≤ m ≤ min(50, n)


//1.dfs+memory
//从头开始拆分数组
//2.二分搜索
//设置mid为阈值，假定所有分组求和都<=mid

class Solution_binary_search {
	bool can_split(vector<int>&nums, int m, int target) {
		int sum = 0;
		int size = 0;
		for (int i = 0; i< nums.size(); i++) {
			sum += nums[i];
			if (sum>target) {
				size++;
				sum = nums[i];
			}
		}
		return size<m;
	}
public:
	int splitArray(vector<int>& nums, int m) {
		int left = 0;
		int right = 0;
		for (auto c : nums) {
			left = max(left, c);
			right += c;
		}
		while (left<right) {
			int mid = left + (right - left) / 2;
			bool is_split = can_split(nums, m, mid);
			if (is_split == true) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};


class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<long>pre_sum(n, 0);
		pre_sum[0] = nums[0];
		for (int i = 1; i<n; i++)
			pre_sum[i] = pre_sum[i - 1] + nums[i];
		vector<vector<long>>c(n, vector<long>(m + 1, LONG_MIN));
		return dfs(c, n, nums, 0, m, pre_sum);
	}
	long dfs(vector<vector<long>>&c, int n, vector<int>&nums, int cur_index, int m, vector<long>&pre_sum) {
		if (cur_index == n)
			return 0;
		if (c[cur_index][m] != LONG_MIN)
			return c[cur_index][m];
		//cur_index到n为一组
		if (m == 1) 
			return pre_sum[n - 1] - pre_sum[cur_index] + nums[cur_index];
		long max_sum = LONG_MAX;;
		for (int i = cur_index; i<n; i++) {
			long right_max = max(pre_sum[i] - pre_sum[cur_index] + nums[cur_index], dfs(c, n, nums, i + 1, m - 1, pre_sum));
			max_sum = min(max_sum, right_max);
		}
		c[cur_index][m] = max_sum;
		return max_sum;

	}
};