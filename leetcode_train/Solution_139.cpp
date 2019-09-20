#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//dfs穷举所有的可能，dp数组记录是否查询过

//dp[i]记录[0,i)是否可以拆分
//[0,i)拆分为[0,j)和[j,i),
//[0,j)就是dp[j]
//[j,i)就是substr(j,i-j)
//注意边界条件即可

class Solution_139 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool>dp(n + 1, false);
		dp[0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j<n; j++) {
				auto temp = s.substr(j, i - j);
				if (dp[j] == true && find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}
	bool wordBreak_(string s, vector<string>& wordDict) {
		bool is_true = false;

		int n = s.size();
		vector<vector<int>>dp(n, vector<int>(n, 0));
		help(s, s.size(), 0, wordDict, is_true, dp);
		return is_true;
	}
	void help(string &s, int n, int start, vector<string>& wordDict, bool &is_true, vector<vector<int>>&dp) {
		if (start == n || is_true == true) {
			is_true = true;
			return;
		}
		for (int length = 1; length<n - start + 1; length++) {
			int end = start + length - 1;
			string new_s = s.substr(start, length);
			if (find(wordDict.begin(), wordDict.end(), new_s) != wordDict.end()) {
				if (dp[start][end] == 0) {
					dp[start][end] = 2;
					help(s, n, end + 1, wordDict, is_true, dp);
				}
			}
			else
				dp[start][end] = 1;
		}
	}
};
int main() {
	Solution_139 s;
	string ss("leetcode");
	vector<string>v_string{ "leet","code" };
	s.wordBreak(ss, v_string);
}