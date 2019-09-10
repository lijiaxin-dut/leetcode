#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Given an array of integers and an integer k, you need to find the total 
//number of continuous subarrays whose sum equals to k.
//
//Example 1:
//Input:nums = [1, 1, 1], k = 2
//	Output : 2
//
class Solution_560 {
public:
	//Memory Limit Exceeded
	//dp[i][j]为i->j的求和
	//dp[i][j]=dp[i][j-1]+nums[j]
	int subarraySum_dp(vector<int>& nums, int k) {
		int sum = 0;
		int n = nums.size();
		vector<vector<int>>dp(n, vector<int>(n, 0));
		int rs = 0;
		for (int i = 0; i<n; i++) {
			if (nums[i] == k)
				rs++;
			dp[i][i] = nums[i];
		}
		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				dp[i][j] = dp[i][j - 1] + nums[j];
				if (dp[i][j] == k)
					rs++;
			}
		}
		return rs;
	}
	//使用0(n)的空间
	//求出所有的前缀和
	//两个前缀和的差值就是子数组之和
	int subarraySum_sums(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int>sums(n);
		sums[0] = nums[0];
		for (int i = 1; i < n; i++) {
			sums[i] = sums[i - 1] + nums[i];		
		}
		int rs = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (sums[j] - sums[i]+nums[i] == k)
					rs++;

			}
		}
	}


	//使用map记录已经找到的sum的和,从0开始
	//查询是否存在sum-k的和，从0开始
	//rs+=map[sum-k]
	int subarraySum(vector<int>& nums, int k) {
		if (nums.empty())
			return 0;
		unordered_map<int, int>hash_map;
		hash_map[0] = 1;
		int sum = 0;
		int rs = 0;
		for (int i = 0; i<nums.size(); i++) {
			sum += nums[i];
			rs += hash_map[sum - k];
			hash_map[sum]++;
		}
		return rs;
	}

};