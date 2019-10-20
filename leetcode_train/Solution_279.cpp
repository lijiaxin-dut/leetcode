#include<vector>
#include<algorithm>

using namespace std;

//Given a positive integer n, find the least number of perfect square numbers(for example, 1, 4, 9, 16, ...) which sum to n.
//
//Example 1:
//
//Input: n = 12
//	Output : 3
//	Explanation : 12 = 4 + 4 + 4.


//dp[i]=min(dp[i-1]+1,dp[i-2*2]+1,dp[i-3*3]+1,...)


class Solution {
public:
	int numSquares(int n) {
		vector<int>dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			}
		}
		return dp[n];
	}
};