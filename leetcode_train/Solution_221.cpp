#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's 
//and return its area.

//Example:
//
//Input:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Output : 4

//dp[i][j]表示以(i,j)为左下角的最长矩形的边长
//dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1


class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>>dp(n, vector<int>(m, 0));
		int rs = 0;
		for (int i = 0; i<n; i++) {
			if (matrix[i][0] == '1') {
				dp[i][0] = 1;
				rs = 1;
			}
		}
		for (int j = 0; j<m; j++) {
			if (matrix[0][j] == '1') {
				dp[0][j] = 1;
				rs = 1;
			}
		}

		for (int i = 1; i<n; i++) {
			for (int j = 1; j<m; j++) {
				if (matrix[i][j] == '1') {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
				rs = max(rs, dp[i][j]);
			}
		}
		
		return rs*rs;
	}
};