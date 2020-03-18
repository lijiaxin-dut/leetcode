#include<vector>
#include<algorithm>
using namespace std;
//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//Note: You may not engage in multiple transactions at the same time(i.e., you must sell the stock before you buy again).
//
//	Example 1 :
//
//	Input : [3, 3, 5, 0, 0, 3, 1, 4]
//	Output : 6
//	Explanation : Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3 - 0 = 3.
//	Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4 - 1 = 3.
//
//

//dp[k][i]:���k�ν��ף�ǰ[0,i)����Ʒ������
//dp[k][i]=max(dp[k][i]��prices[i]-(price[j]-dp[k-1][j-1]))  j=1,...i j���Ե���i,�ȼ�dp[k-1][i]����ʾ��k�β���ɶҲ����

class Solution {
public:
	int maxProfit_1(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int max_k = 2;
		int n = prices.size();
		vector<vector<int>>dp(max_k + 1, vector<int>(n + 1, 0));
		int rs = 0;
		for (int k = 1; k <= max_k; k++) {
			for (int i = 1; i <= n; i++) {
				//�Ѻ�벿�ֵ�maxȡ����
				for (int j = 1; j<i; j++) {
					dp[k][i] = max(dp[k][i], max(dp[k][i - 1], prices[i - 1] - prices[j - 1] + dp[k - 1][j - 1]));
				}
			}
		}
		return dp[max_k][n];
	}

	int maxProfit_2(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int max_k = 2;
		int n = prices.size();
		vector<vector<int>>dp(max_k + 1, vector<int>(n + 1, 0));
		int rs = 0;
		for (int k = 1; k <= max_k; k++) {
			for (int i = 1; i <= n; i++) {
				//���Կ������������Сֵ��һ���ظ��Ĺ���
				int min_val = prices[0];
				for (int j = 1; j <= i; j++) {
					min_val = min(min_val, prices[j - 1] - dp[k - 1][j - 1]);
				}
				//����һ����Сֵ������������ֵ
				dp[k][i] = max(dp[k][i - 1], prices[i - 1] - min_val);
			}
		}
		return dp[max_k][n];
	}
	int maxProfit_3(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int max_k = 2;
		int n = prices.size();
		vector<vector<int>>dp(max_k + 1, vector<int>(n + 1, 0));
		int rs = 0;
		for (int k = 1; k <= max_k; k++) {
			int min_val = prices[0];
			for (int i = 1; i <= n; i++) {
				min_val = min(min_val, prices[i - 1] - dp[k - 1][i - 1]);
				//����һ����Сֵ������������ֵ
				dp[k][i] = max(dp[k][i - 1], prices[i - 1] - min_val);
			}
		}
		return dp[max_k][n];
	}
};
