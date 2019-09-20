#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Note that you cannot sell a stock before you buy one.

//
//
//Example 1:
//
//Input: [7, 1, 5, 3, 6, 4]
//	Output : 5
//	Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
//	Not 7 - 1 = 6, as selling price needs to be larger than buying price.
//


//两个数组
//lhs[i]记录从[0,i]的最小值
//rhs[i]记录从[i,n-1]的最大值
//最后找一个最大的差值

class Solution_121 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int n = prices.size();
		vector<int>min_lhs(n, INT_MAX);
		vector<int>max_rhs(n, INT_MIN);
		min_lhs[0] = prices[0];
		for (int i = 1; i<n; i++) {
			min_lhs[i] = min(min_lhs[i - 1], prices[i]);
		}
		max_rhs[n - 1] = prices[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			max_rhs[i] = max(max_rhs[i + 1], prices[i]);
		}
		int rs = 0;
		for (int i = 0; i<n; i++) {
			rs = max(rs, max_rhs[i] - min_lhs[i]);
		}
		return rs;
	}
};

