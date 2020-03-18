#include<vector>
#include<algorithm>


using namespace std;
//
//Your are given an array of integers prices, for which the i - th element is the price of a given stock on day i; and a non - negative integer fee representing a transaction fee.
//
//You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.You may not buy more than 1 share of a stock at a time(ie.you must sell the stock share before you buy again.)
//
//Return the maximum profit you can make.

//保持两个状态sold hold
//sold为售出后的状态，或者啥也不干的状态
//hold为买入的状态，或者啥也不干的状态

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		if (n == 0)
			return 0;
		vector<int>hold(n, 0);
		vector<int>sold(n, 0);
		hold[0] = -prices[0] - fee;
		for (int i = 1; i<n; i++) {
			hold[i] = max(hold[i - 1], sold[i - 1] - prices[i] - fee);
			sold[i] = max(sold[i - 1], hold[i - 1] + prices[i]);
		}
		return sold[n - 1];

	}
};