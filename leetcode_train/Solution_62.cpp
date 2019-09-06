#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
//
//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach 
//the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?

//方法1
//dp
//dp[i][j]=dp[i-1][j]+dp[i][j-1]
//方法2   dfs
//help(current_m + 1, current_n, m, n, rs);
//help(current_m, current_n + 1, m, n, rs);


class Solution {
public:
	int uniquePaths_dp(int m, int n) {
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 1));
		for(int i=1;i<=m;i++)
		    dp[i][1]=1;
		for(int j=1;j<=n;j++)
		    dp[1][j]=1;
		for (int i = 2; i <= m; i++) {
			for (int j = 2; j <= n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m][n];
	}
	int uniquePaths_recur(int m, int n) {
		int rs=0;
		help(1,1,m,n,rs);
		return rs;
	}

	void help(int current_m, int current_n, int m, int n, int &rs) {
		if (current_m>m || current_n>n)
			return;
		if (current_m == m&&current_n == n) {
			rs++;
			return;
		}
		help(current_m + 1, current_n, m, n, rs);
		help(current_m, current_n + 1, m, n, rs);
	}
};