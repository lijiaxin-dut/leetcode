#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?



//方法1
//dp
//dp[i][j]=dp[i-1][j]+dp[i][j-1]
//初始化时，第一行或者第一列遇到第一个1之后，后面的值不需要在初始化
//注意跳过障碍即可


//方法2   dfs
//遇到障碍跳过即可
//help(current_m + 1, current_n, m, n, rs);
//help(current_m, current_n + 1, m, n, rs);



class Solution_63 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		// if(obstacleGrid.empty())
		// return 0;
		// int m=obstacleGrid.size();
		// int n=obstacleGrid[0].size();
		// int rs=0;
		// help(obstacleGrid,1,1,m,n,rs);
		// return rs;
		if (obstacleGrid.empty())
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		unsigned long long  rs = 0;
		vector<vector<unsigned long long >>dp(m + 1, vector<unsigned long long >(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			if (obstacleGrid[i - 1][0] == 1) {
				dp[i][1] = 0;
				break;
			}
			else
				dp[i][1] = 1;
		}
		for (int j = 1; j <= n; j++) {
			if (obstacleGrid[0][j - 1] == 1) {
				dp[1][j] = 0;
				break;
			}
			else
				dp[1][j] = 1;
		}

		for (int i = 2; i <= m; i++) {
			for (int j = 2; j <= n; j++) {
				if (obstacleGrid[i - 1][j - 1] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m][n];
	}
	void help(vector<vector<int>>& obstacleGrid, int current_m, int current_n, int m, int n, int &rs) {
		if (current_m>m || current_n>n || obstacleGrid[current_m - 1][current_n - 1])
			return;
		if (current_m == m&&current_n == n) {
			rs++;
			return;
		}
		help(obstacleGrid, current_m + 1, current_n, m, n, rs);
		help(obstacleGrid, current_m, current_n + 1, m, n, rs);
	}
};