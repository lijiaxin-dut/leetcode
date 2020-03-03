#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;


//You are given coins of different denominations and a total amount of money.Write a function to compute the number of combinations that make up that amount.You may assume that you have infinite number of each kind of coin.
//
//
//
//Example 1:
//
//Input: amount = 5, coins = [1, 2, 5]
//	Output : 4
//	Explanation : there are four ways to make up the amount :
//	   5 = 5
//		   5 = 2 + 2 + 1
//		   5 = 2 + 1 + 1 + 1
//		   5 = 1 + 1 + 1 + 1 + 1
//


//自定向下递归+备忘录
//not using the ith coin, only using the first i-1 coins to make up amount j, then we have dp[i-1][j] ways.
//using the ith coin, since we can use unlimited same coin, we need to know how many ways to make up amount j - coins[i - 1] by using first i coins(including ith), which is dp[i][j - coins[i - 1]]
class Solution {
	vector<vector<int>>c;
public:

	int change_dp(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<vector<int>>dp(n + 1, vector<int>(amount + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= amount; j++) {
				dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
			}
		}
		return dp[n][amount];

	}
	int change(int amount, vector<int>& coins) {
		if (amount == 0)
			return 1;
		c.resize(amount + 1, vector<int>(coins.size(), -1));
		return  dfs(coins, amount, 0);

	}
	int dfs(vector<int>&coins, int amount, int cur_index) {
		if (cur_index >= coins.size())
			return 0;
		if (c[amount][cur_index] != -1)
			return c[amount][cur_index];
		if (amount == 0)
			return 1;
		int rs = 0;
		for (int i = cur_index; i<coins.size(); i++) {
			if (amount >= coins[i])
				rs += dfs(coins, amount - coins[i], i);
		}
		c[amount][cur_index] = rs;
		return rs;
	}


};