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
		int n = coins.size();
		vector<int>dp(amount + 1, INT_MAX / 2);
		dp[0] = 0;
		for (int money = 1; money <= amount; money++) {
			for (auto &one_coin : coins) {
				if (one_coin <= money) {
					dp[money] = min(dp[money], dp[money - one_coin] + 1);
				}
			}
		}
		return dp[amount] == INT_MAX / 2 ? -1 : dp[amount];
	}
};

//int main() {
//	Solution_322 s;
//	s.coinChange(vector<int>{ 1,2,5 }, 11);
//}