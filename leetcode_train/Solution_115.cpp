#include<string>
#include<vector>

using namespace std;

//Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
//A subsequence of a string is a new string which is formed from the original string by 
//deleting some(can be none) of the characters without disturbing the relative positions 
//of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

//dp[i][j]表示t[0,i-1]与s[0,j-1]之间的结果
//如果t[i-1]!=s[j-1]
//s[j-1]不在结果中，与s[j-2]相等，即dp[i][j-1]
//If t[i - 1] == s[j - 1], 
//the number of distinct subsequences include two parts : 
//those with s[j - 1] and those without;

//An empty string will have exactly one subsequence in any string : -)
//Non - empty string will have no subsequences in an empty string.

//
//Ø r a b b b i t
//Ø 1 1 1 1 1 1 1 1
//r 0 1 1 1 1 1 1 1
//a 0 0 1 1 1 1 1 1
//b 0 0 0 1 2 3 3 3
//b 0 0 0 0 1 3 3 3
//i 0 0 0 0 0 0 3 3
//t 0 0 0 0 0 0 0 3


class Solution_115 {
public:
	int numDistinct(string s, string t) {
		int m = t.size();
		int n = s.size();
		vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
		for (int j = 0; j <= n; j++)
			dp[0][j] = 1;
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= m; i++) {
				dp[i][j] = dp[i][j - 1];
				if (t[i - 1] == s[j - 1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[m][n];
	}
};