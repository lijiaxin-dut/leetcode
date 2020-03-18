#include<vector>
#include<algorithm>
using namespace std;

//hard to understand



//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

//1.穷举
//每一天有三个状态，穷绝所有的穷举，然后找出最大值
//2.保存三个状态
//hold[i],sold[i],rest[i]
//sold[i]售出的状态，有hold进行卖出或者sold[i-1]
//hold[i]持有的状态，可以继续持有，或者有rest买入
//rest[i]休息状态，可以持续休息，或卖出后进行休息

class Solution_309 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
			return 0;
		vector<int>rest(n, 0);
		vector<int>hold(n, 0);
		vector<int>sold(n, 0);
		hold[0] = -prices[0];
		for (int i = 1; i<n; i++) {
			hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
			sold[i] = max(sold[i - 1], hold[i - 1] + prices[i]);
			rest[i] = max(rest[i - 1], sold[i - 1]);
		}
		return max(sold[n - 1], rest[n - 1]);


	}
};