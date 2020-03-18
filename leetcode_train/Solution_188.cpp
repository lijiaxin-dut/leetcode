#include<vector>
#include<algorithm>

using namespace std;

//
//Say you have an array for which the i - th element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most k transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//
//Example 1 :
//
//	Input : [2, 4, 1], k = 2
//	Output : 2
//	Explanation : Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4 - 2 = 2.


//最多k次交易


//dp[k][i]:最多k次交易，前[0,i)个物品的收益
//dp[k][i]=max(dp[k][i]，prices[i]-(price[j]-dp[k-1][j-1]))  j=1,...i j可以等于i,等价dp[k-1][i]，表示第k次操作啥也不做



class Solution {
public:

	int quick_buy(vector<int>& prices) {
		int n = prices.size();
		prices.push_back(0);
		int rs = 0;
		int min_val = prices[0];
		for (int i = 0; i<n; i++) {
			if (prices[i]>prices[i + 1]) {
				rs += prices[i] - min_val;
				min_val = prices[i + 1];
			}
		}
		return rs;

	}
public:
	//当k过大时，退化成无限次交易的情况
	int maxProfit_quick(int max_k, vector<int>& prices) {
		if (prices.empty())
			return 0;
		int n = prices.size();
		if (max_k >= n)
			return quick_buy(prices);
		vector<vector<int>>dp(max_k + 1, vector<int>(n + 1, 0));
		for (int k = 1; k <= max_k; k++) {
			int min_val = prices[0];
			for (int i = 1; i <= n; i++) {
				min_val = min(min_val, prices[i - 1] - dp[k - 1][i - 1]);
				dp[k][i] = max(dp[k][i - 1], prices[i - 1] - min_val);
			}
		}
		return dp[max_k][n];
	}

	int maxProfit(int max_k, vector<int>& prices) {
		if (prices.empty())
			return 0;
		int n = prices.size();
		vector<vector<int>>dp(2, vector<int>(n + 1, 0));
		for (int k = 1; k <= min(max_k, n); k++) {
			int min_val = prices[0];
			for (int i = 1; i <= n; i++) {
				min_val = min(min_val, prices[i - 1] - dp[0][i - 1]);
				dp[1][i] = max(dp[1][i - 1], prices[i - 1] - min_val);
			}
			swap(dp[0], dp[1]);
			dp[1][0] = 0;
		}
		return dp[0][n];
	}
};