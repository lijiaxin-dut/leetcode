#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

//You are given a list of non - negative integers, a1, a2, ..., an, and a target, S.Now you have 2 symbols + and -.For each integer, you should choose one from + and -as its new symbol.
//
//Find out how many ways to assign symbols to make sum of integers equal to target S.
//
//Example 1:
//Input: nums is[1, 1, 1, 1, 1], S is 3.
//	Output : 5
//	Explanation :
//
//	-1 + 1 + 1 + 1 + 1 = 3
//	+ 1 - 1 + 1 + 1 + 1 = 3
//	+ 1 + 1 - 1 + 1 + 1 = 3
//	+ 1 + 1 + 1 - 1 + 1 = 3
//	+ 1 + 1 + 1 + 1 - 1 = 3
//
//	There are 5 ways to assign symbols to make the sum of nums be target 3.

//1.dfs遍历所有的可能
//2.dp
//dp[i][j]表示[0,...,i-1]求和为j的可能性
//dp[i][j+nums[i]]+=dp[i-1][j]
//dp[i][j-nums[i]]+=dp[i-1][j]

class Solution_494 {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		int rs = 0;
		dfs(rs, nums, 0, n, S, 0);
		return rs;

	}
	void dfs(int &rs, vector<int>&nums, int current_index, int n, int S, int current_sum) {
		if (current_index == n) {
			if (current_sum == S) {
				rs++;
			}
			return;
		}
		dfs(rs, nums, current_index + 1, n, S, current_sum + nums[current_index]);
		dfs(rs, nums, current_index + 1, n, S, current_sum - nums[current_index]);


	}

	int findTargetSumWays_dp(vector<int>& nums, int S) {
		int n = nums.size();
		vector<unordered_map<int, int>>dp(n + 1);
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (auto &one : dp[i - 1]) {
				int sum = one.first;
				int cnt = one.second;
				dp[i][sum + nums[i - 1]] += cnt;
				dp[i][sum - nums[i - 1]] += cnt;
			}
		}
		return dp[n][S];
	}
};