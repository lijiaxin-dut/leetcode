#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input: "babad"
//	Output : "bab"
//	Note : "aba" is also a valid answer.


//动态规划，最长回文字串
//dp[i][j]表示i->j是否构成回文
//dp[i, j] = 1      if i == j
//
//			= s[i] == s[j]   if j = i + 1
//
//			= s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1
class Solution_5 {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return s;
		int n = s.size();
		vector<vector<bool>>dp(n, vector<bool>(n, false));
		for (int i = 0; i<n; i++) {
			dp[i][i] = true;
		}
		int rs = 1;
		int rs_start = 0;
		for (int i = 0, j = i + 1; j<n; i++, j++) {
			if (s[i] == s[j]) {
				rs = 2;
				rs_start = i;
				dp[i][j] = true;
			}
		}

		for (int length = 3; length <= n; length++) {
			for (int start = 0; start<n + 1 - length; start++) {
				int end = start + length - 1;
				if (s[start] == s[end] && dp[start + 1][end - 1] == true) {
					dp[start][end] = true;
					rs_start = start;
					rs = max(rs, length);
				}
			}
		}
		return s.substr(rs_start, rs);
	}
};