#include<string>
#include<vector>
#include<algorithm>

using namespace std;



//Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//Example 1:
//Input:
//
//"bbbab"
//Output :
//	4
//	One possible longest palindromic subsequence is "bbbb".


//dp[i][j]标识i->j间最大的回文子序列

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		if (n == 0)
			return 0;
		vector<vector<int>>dp(n, vector<int>(n, 0));
		for (int i = 0; i<n; i++)
			dp[i][i] = 1;
		for (int length = 2; length <= n; length++) {
			for (int i = 0; i + length - 1<n; i++) {
				int j = i + length - 1;
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		return dp[0][n - 1];
	}
};