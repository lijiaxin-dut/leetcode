#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//只能向右或者向下走
//找到一条路径，使得经过的点求和最小

//注意初始化的条件

//dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);


class Solution_64 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
		dp[1][1] = grid[0][0];
		for (int i = 2; i <= m; i++)
			dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
		for (int j = 2; j <= n; j++)
			dp[1][j] = dp[1][j - 1] + grid[0][j - 1];
		for (int i = 2; i <= m; i++) {
			for (int j = 2; j <= n; j++) {
				dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[m][n];
	}
};