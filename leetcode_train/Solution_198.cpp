#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//You are a professional robber planning to rob houses along a street.Each house 
//has a certain amount of money stashed, the only constraint stopping you from 
//robbing each of them is that adjacent houses have security system connected 
//and it will automatically contact the police if two adjacent houses were broken into on the same night.

//Given a list of non - negative integers representing the amount of money of each 
//house, determine the maximum amount of money you can rob tonight without alerting the police.

//Example 1:

//Input: [1, 2, 3, 1]
	//Output : 4
	//Explanation : Rob house 1 (money = 1) and then rob house 3 (money = 3).
	//Total amount you can rob = 1 + 3 = 4.

//dfs穷举
//从0开始，或者从1开始，每次走两步或者三步

//动态规划
//dp[i]表示经过i点的最大代价
//单独考虑dp[0],[1],[2]
//dp[i]=nums[i]+max(dp[i-2],dp[i-3])

class Solution_198 {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		else if (nums.size() == 1)
			return nums[0];
		else if (nums.size() == 2)
			return max(nums[0], nums[1]);
		else if (nums.size() == 3)
			return max(nums[1], nums[0] + nums[2]);

		int n = nums.size();
		vector<int>dp(n, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		dp[2] = max(nums[1], nums[0] + nums[2]);
		int rs = max(dp[0], max(dp[1], dp[2]));
		for (int i = 3; i<n; i++) {
			dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
			rs = max(dp[i], rs);
		}
		return rs;
	}
	int rob_1(vector<int>& nums) {
		int n = nums.size();
		int current_rs = 0;
		int max_rs = 0;
		help(nums,current_rs,max_rs,0,n);
		help(nums,current_rs,max_rs,1,n);
		return max_rs;
	}
	void help(vector<int>&nums, int &current_rs, int &max_rs, int current_index, int n) {
		if (current_index >= n)
			return;
		current_rs += nums[current_index];
		max_rs = max(max_rs, current_rs);

		help(nums, current_rs, max_rs, current_index + 2, n);
		help(nums, current_rs, max_rs, current_index + 3, n);
		current_rs -= nums[current_index];
	}
};
//int main() {
//	Solution_198 s;
//	vector<int>nums{ 1,2,3,1 };
//	cout<<s.rob(nums);
//}