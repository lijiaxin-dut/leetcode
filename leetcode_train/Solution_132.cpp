#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//Example:
//
//Input: "aab"
//	Output : 1
//	Explanation : The palindrome partitioning["aa", "b"] could be produced using 1 cut.

//1.dp
//dp[i]表示s[0,i]的最下cut数目
//用p[i][j]标记s[i,..j]是否时回文串


class Solution_132 {
public:
	int minCut(string s) {
		int n = s.size();
		vector<int>dp(n, INT_MAX);
		vector<vector<bool>> p(n, vector<bool>(n, false));
		dp[0] = 0;
		for (int i = 1; i<n; i++) {
			for (int j = 0; j <= i; j++) {
				if (s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {
					p[j][i] = true;
					if (j == 0)
						dp[i] = 0;
					else
						dp[i] = min(dp[i], dp[j - 1] + 1);
				}

			}

		}
		return dp[n - 1];

	}
};