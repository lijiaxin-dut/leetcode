#include<vector>
#include<algorithm>

using namespace std;

//You are given coins of different denominations and a total 
//amount of money amount.Write a function to compute the fewest 
//number of coins that you need to make up that amount.If that 
//amount of money cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//
//Input: coins = [1, 2, 5], amount = 11
//	Output : 3
//	Explanation : 11 = 5 + 5 + 1


//dp[i]=min(dp[i],dp[i-one_con]+1) for all coins

class Solution_322 {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		vector<int>dp(amount + 1, INT_MAX / 2);
		for (auto &one_coins : coins) {
			if (one_coins>amount)
				continue;
			dp[one_coins] = 1;
		}
		for (int i = 1; i <= amount; i++) {
			for (auto &one_coins : coins) {
				if (i >= one_coins)
					dp[i] = min(dp[i], dp[i - one_coins] + 1);
			}
		}
		if (dp[amount] == INT_MAX / 2)
			return -1;
		return dp[amount];
	}
};

int main() {
	Solution_322 s;
	s.coinChange(vector<int>{ 1,2,5 }, 11);
}