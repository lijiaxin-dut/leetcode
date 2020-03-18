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

//1.���
//ÿһ��������״̬��������е���٣�Ȼ���ҳ����ֵ
//2.��������״̬
//hold[i],sold[i],rest[i]
//sold[i]�۳���״̬����hold������������sold[i-1]
//hold[i]���е�״̬�����Լ������У�������rest����
//rest[i]��Ϣ״̬�����Գ�����Ϣ���������������Ϣ

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