#include<vector>

using namespace std;

//hard to understand



//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

//维持三个状态
//s0	  [Consequence] State not immediate after selling; Doesn't have any stock;
		//[Action can take] Buy a new stock / Continue to take a rest
//s1      [Consequence] State with stock in hand;
//		  [Action can take] Sell a stock / Continue to take a rest
//s2		[Consequence] State immediate after selling; Doesn't have any stock (since just sell one to enter this state)
//			[Action can take] Enters next state by taking a rest(since s2 is only for state immediate after selling, we cannot stay here.)



class Solution_309 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		vector<int> s0(prices.size(), 0);//前一个动作不是卖，可以继续reset或者买
		vector<int> s1(prices.size(), 0);//手中持有stock,可以卖，或者reset   ，s[0]=-prices[0]，只能持有prcies[0]
		vector<int> s2(prices.size(), 0);//前一个动作是卖,初始化前面没有工作s2[0]=0,下一个动作只能是reset
		s1[0] = -prices[0];
		s0[0] = 0;
		s2[0] = 0;
		for (int i = 1; i < prices.size(); i++) {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
		return max(s0[prices.size() - 1], s2[prices.size() - 1]);

	}
};