#include<vector>
#include<algorithm>
using namespace std;


//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//Example:
//
//Input: [10, 9, 2, 5, 3, 7, 101, 18]
//	Output : 4
//	Explanation : The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4.
//
//

//最长上升子序列
//维护一个一维 dp 数组，其中 dp[i] 表示以 nums[i] 为结尾的最长递增子串的长度，
//对于每一个 nums[i]，从第一个数再搜索到i，如果发现某个数小于 nums[i]，
//更新 dp[i]，更新方法为 dp[i] = max(dp[i], dp[j] + 1)

class Solution_300 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size();
		vector<int>dp(n, 1);
		int rs = 1;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (nums[i]>nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
					rs = max(rs, dp[i]);
				}
			}
		}
		return rs;

	}
};