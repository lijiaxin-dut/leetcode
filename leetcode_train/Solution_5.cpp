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
		int n = s.size();
		if (n == 0)
			return "";
		bool dp[1000][1000] = { false };
		for (int i = 0; i < n; i++)
			dp[i][i] = true;
		int rs_left = 0;
		int rs_length = 1;
		for (int length = 2; length <= n; length++) {
			for (int left = 0; left < n - length + 1; left++) {
				int right = left + length - 1;
				if (s[left] == s[right] && (length == 2 || dp[left + 1][right - 1])) {
					dp[left][right] = true;
					rs_left = left;
					rs_length = length;
				}
			}
		}
		return s.substr(rs_left, rs_length);
	}
};