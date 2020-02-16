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
	vector<vector<int>>c;
public:
	//考虑一个位置时，如果认为是先戳破，
	//[3,1,2,4,5,6],比如4 [3,1,2],[5,6]则左右两个问题相互依赖因为边界发生变化
	//如果我们认为最后戳破4，
	//[3,1,2],[5,6]两个子问题不发生依赖
	int maxCoins_dd(vector<int>& nums) {
		c.resize(nums.size(), vector<int>(nums.size(), -1));
		int result = getMaxCoins(nums, 0, nums.size() - 1);
		return result;
	}
	int getMaxCoins(vector<int>&nums, int start, int end) {
		if (end >= start) {
			if (c[start][end] != -1)
				return c[start][end];
		}
		if (start == end) {
			int result = (start - 1<0 ? 1 : nums[start - 1]) * nums[start] * (end + 1 >= nums.size() ? 1 : nums[end + 1]);
			return result;
		}
		int maxCoins = 0;
		for (int i = start; i <= end; i++) {
			int temp = (start - 1<0 ? 1 : nums[start - 1])*nums[i] * (end + 1 >= nums.size() ? 1 : nums[end + 1]) + getMaxCoins(nums, start, i - 1) + getMaxCoins(nums, i + 1, end);
			maxCoins = max(maxCoins, temp);
		}
		if (end >= start) {
			c[start][end] = maxCoins;
		}
		return maxCoins;

	}
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

