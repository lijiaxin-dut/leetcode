#include<vector>
#include<algorithm>
using namespace std;

//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are :
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.




//1.dp 
// dp[i]表示求和为i的个数
// dp[target]=dp[target]+dp[target-i]

//2.dfs
//





class Solution_377 {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned int>dp(target + 1);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (auto &one_num : nums) {
				if (i >= one_num) {
					dp[i] = dp[i] + dp[i - one_num];
				}
			}
		}
		return dp[target];
	}
	int combinationSum4_dfs(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int rs = 0;
		int current_sum = 0;
		dfs(nums, rs, target, current_sum);
		return rs;
	}

	void dfs(vector<int>&nums, int &rs, int target, int &current_sum) {
		if (current_sum == target) {
			rs++;
			return;
		}
		if (current_sum>target)
			return;
		for (int i = 0; i<nums.size(); i++) {
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			current_sum += nums[i];
			dfs(nums, rs, target, current_sum);
			current_sum -= nums[i];

		}

	}
};