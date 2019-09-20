#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

//Given an array consisting of n integers, find the contiguous subarray of given length k 
//that has the maximum average value.And you need to output the maximum average value.
//
//Example 1:
//
//Input: [1, 12, -5, -6, 50, 3], k = 4
//	Output : 12.75
//	Explanation : Maximum average is(12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75


//固定窗口长度
//滑动窗口


class Solution_643 {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double rs = 0;
		double sum = 0;
		for (int i = 0; i<k; i++) {
			sum += nums[i];
		}
		rs = sum;
		for (int i = k; i<nums.size(); i++) {
			sum -= nums[i - k];
			sum += nums[i];
			rs = max(rs, sum);
		}
		return rs / k;
	}
};