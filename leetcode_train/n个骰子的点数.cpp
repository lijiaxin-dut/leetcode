#include<vector>
#include<algorithm>

using namespace std;


//dp[i][j]
//表示前i个骰子，求和为j的个数
//dp[i][j] +=dp[i-1][j-k] k=1->6

class Solution {
public:
	vector<double> twoSum(int n) {
		vector<vector<int>>dp(n, vector<int>(6 * n + 1, 0));
		double count = pow(6, n);
		for (int i = 1; i <= 6; i++) {
			dp[0][i] = 1;
		}
		for (int i = 1; i<n; i++) {
			for (int j = i; j <= 6 * (i + 1); j++) {
				for (int k = 1; k <= 6; k++) {
					if (j>k) {
						dp[i][j] += dp[i - 1][j - k];
					}
				}
			}
		}

		vector<double>rs;
		for (int i = n; i <= 6 * n; i++) {
			rs.push_back(dp[n - 1][i] / count);
		}
		return rs;
	}

};