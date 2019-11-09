#include<vector>
#include<algorithm>
using namespace std;

//Given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by array nums.You are asked to burst all the balloons.If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.Here left and right are adjacent indices of i.After the burst, the left and right then becomes adjacent.
//
//Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note:
//
//You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100


//dp[i][j]表示i->j可以获得的最大硬币数
//任意属于i->j的k
//假设k是最后戳破的气球
//dp[i][j]=dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]
//不能是nums[k-1]*nums[k]*nums[k+1]

//因为k是最后戳破的，相邻的气球在区间外侧



class Solution_312 {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
		for (int len = 1; len <= n; len++) {
			for (int i = 1; i <= n; i++) {
				int j = i + len - 1;
				if (j <= n) {
					for (int k = i; k <= j; k++) {
						dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
					}
				}
			}
		}
		return dp[1][n];
	}
};