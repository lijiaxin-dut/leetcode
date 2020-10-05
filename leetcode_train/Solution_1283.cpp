#include<vector>
#include<algorithm>

using namespace std;

//给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
//
//请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
//
//每个数除以除数后都向上取整，比方说 7 / 3 = 3 ， 10 / 2 = 5 。
//
//题目保证一定有解。

//二分

class Solution {
	bool check(vector<int>&nums, double k, int threshold) {
		int sum = 0;
		for (auto c : nums) {
			sum += ceil(c / k);
			if (sum>threshold)
				return false;
		}
		return sum <= threshold;
	}
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		int right = *max_element(nums.begin(), nums.end());
		int left = 1;
		int rs = INT_MAX;
		while (left<right) {
			int mid = left + (right - left) / 2;
			bool is_ch = check(nums, mid, threshold);
			if (is_ch == true) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};