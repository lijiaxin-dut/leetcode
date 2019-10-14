#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given an integer array nums, find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//Example 1:
//
//Input: [2, 3, -2, 4]
//	Output : 6
//	Explanation : [2, 3] has the largest product 6.
//	Example 2 :
//
//	Input : [-2, 0, -1]
//	Output : 0
//	Explanation : The result cannot be 2, because[-2, -1] is not a subarray.

//dp
//dp[i][j]表示i到j的乘积
//dp[i][j]=dp[i][j-1]*dp[j]
//保存最大的结果就行
//TLE

//dp
//用两个dp数组，其中
//max_sub[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最大子数组乘积，
//min_sub[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最小子数组乘积，
//初始化时max_sub[0]和min_sub[0]都初始化为nums[0]，其余都初始化为0。
//那么从数组的第二个数字开始遍历，那么此时的最大值和最小值只会在这三个数字之间产生，
//即max_sub[i - 1] * nums[i]，min_sub[i - 1] * nums[i]，和nums[i]
//使用rs保存遇到过的最大值

class Solution_152 {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size();
		vector<vector<int>>dp(n, vector<int>(n, 1));
		int rs = nums[0];
		for (int i = 0; i<n; i++) {
			dp[i][i] = nums[i];
			rs = max(rs, nums[i]);
		}

		for (int length = 1; length <= n; length++) {
			for (int i = 0, j = i + length; i<n&&j<n; i++, j++) {
				dp[i][j] = dp[i][j - 1] * nums[j];
				rs = max(rs, dp[i][j]);
			}
		}
		return rs;
	}
	int maxProduct_dp(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int current_max = nums[0];
		int current_min = nums[0];
		int rs = nums[0];
		for (int i = 1; i<nums.size(); i++) {
			int p = current_max*nums[i];
			int q = current_min*nums[i];
			current_max = max(nums[i], max(p, q));
			current_min = min(nums[i], min(p, q));
			rs = max(current_max, rs);
		}
		return rs;
	}
	int maxProduct_dp_2(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> max_sub(nums.size(), 0);
		vector<int> min_sub(nums.size(), 0);
		max_sub[0] = nums[0];
		min_sub[0] = nums[0];
		int rs = nums[0];
		for (int i = 1; i<nums.size(); i++) {
			int p = max_sub[i - 1] * nums[i];
			int q = min_sub[i - 1] * nums[i];
			max_sub[i] = max(nums[i], max(p, q));
			min_sub[i] = min(nums[i], min(p, q));
			rs = max(max_sub[i], rs);
		}
		return rs;
	}
};

//int main() {
//	Solution_152 s;
//	vector<int>nums{ 2,3,-2,4 };
//	s.maxProduct(nums);
//}