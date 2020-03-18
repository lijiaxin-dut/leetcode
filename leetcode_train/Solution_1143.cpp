#include<string>
#include<vector>
#include<algorithm>


using namespace std;


//Given two strings text1 and text2, return the length of their longest common subsequence.
//
//A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not).A common subsequence of two strings is a subsequence that is common to both strings.
//
//
//
//If there is no common subsequence, return 0.


//dp[i][j]标识s[0,...i-1]与t[0,...j-1]的最长公共子序列
//if s[i-1]==t[j-1]
   //dp[i][j]=dp[i-1][j-1]
//else
//	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);


class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size();
		int n = text2.size();
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[m][n];

	}
};