#include<vector>
#include<algorithm>
using namespace std;

//Given a set of distinct positive integers, find the largest subset such that every pair(Si, Sj) of elements in this subset satisfies :
//
//Si % Sj = 0 or Sj % Si = 0.
//
//If there are multiple solutions, return any subset is fine.
//
//Example 1:
//
//Input: [1, 2, 3]
//	Output : [1, 2](of course, [1, 3] will also be ok)
//	Example 2 :
//
//	Input : [1, 2, 4, 8]
//	Output : [1, 2, 4, 8]

//1.dfs
//2.dp
//对数组进行排序
//dp[i]=max(dp[i],dp[j]+1)   if nums[i]%nums[j]==0
//因为nums[j]是solution[j]中最大的数字，如果能整除，就能整除solution[j]中所有的数字



class Solution_368{
	bool div(vector<int>&rs, int val) {
		for (auto &one_num : rs) {
			if (one_num%val != 0 && val%one_num != 0) {
				return false;
			}
		}
		return true;
	}
public:
	vector<int> largestDivisibleSubset_dfs(vector<int>& nums) {
		vector<int>global_rs;
		vector<int>partial_rs;
		for (int i = 0; i<nums.size(); i++) {
			partial_rs.push_back(nums[i]);
			dfs(global_rs, partial_rs, nums, i + 1);
			partial_rs.pop_back();
		}
		return global_rs;
	}
	void dfs(vector<int>&global_rs, vector<int>&partial_rs, vector<int>&nums, int index) {
		if (partial_rs.size()>global_rs.size()) {
			global_rs = partial_rs;
		}
		for (int i = index; i<nums.size(); i++) {
			if (div(partial_rs, nums[i]) == true) {
				partial_rs.push_back(nums[i]);
				dfs(global_rs, partial_rs, nums, i + 1);
				partial_rs.pop_back();
			}
		}
	}
	vector<int> largestDivisibleSubset_dp(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return{};
		sort(nums.begin(), nums.end());
		vector<vector<int>>dp_solution(n);
		vector<int>dp(n, 1);
		for (int i = 0; i<n; i++)
			dp_solution[i] = { nums[i] };
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (dp[i]<dp[j] + 1 && nums[i] % nums[j] == 0) {
					dp[i] = dp[j] + 1;
					dp_solution[i] = dp_solution[j];
					dp_solution[i].push_back(nums[i]);

				}
			}
		}
		vector<int>rs;
		for (auto &one_sub : dp_solution) {
			if (rs.size()<one_sub.size())
				rs = one_sub;
		}
		return rs;
	}
};

