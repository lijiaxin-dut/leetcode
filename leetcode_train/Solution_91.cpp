#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given a non - empty string containing only digits, determine the total number of ways to decode it.
//
//Example 1:
//
//Input: "12"
//	Output : 2
//	Explanation : It could be decoded as "AB" (1 2) or "L" (12).

//dfs穷举所有组合

//dp[i]为0到i的所有组合
//单独处理dp[0]和dp[1]
//s[i]='0',如果s[i-1]='1'或者‘2’ dp[i]=dp[i-2]，i-1与i只能组合，
//			否则为0
//s[i-1]='1'或者s[i-1]='2'并且s[i]<='6',  dp[i]=dp[i-1]+dp[i-2]
//		dp[i]=dp[i-1],只能单独译码

class Solution {
public:

	int numDecodings(string s) {
		int rs = 0;
		int n = s.size();
		if (n == 0 || s[0] == '0')
			return 0;
		if (n == 1)
			return 1;
		vector<int>dp(n, 0);
		dp[0] = 1;
		if (n > 1) {
			if (s[1] == '0') {
				if (s[0] == '1' || s[0] == '2')
					dp[1] = dp[0];
				else
					return 0;
			}
			else if (s[1] != '0') {
				if (s[0] == '1' || (s[0] == '2'&&s[1] <= '6'))
					dp[1] = 2;
				else
					dp[1] = 1;
			}

		}
		for (int i = 2; i < n; i++) {
			if (s[i] == '0') {
				if (s[i - 1] == '1' || s[i - 1] == '2') {
					//合并译码，不增加可能性,10或者20必须放到一起
					dp[i] = dp[i - 2];
				}
				else
					return 0;
			}
			else {
				//两种译码可能
				//dp[i-1]为单独译码，不组合
				//dp[i-2]为组合译码，将s[i-1]s[i]组合译码
				if (s[i - 1] == '1' || (s[i - 1] == '2'&&s[i] <= '6')) {
					dp[i] = dp[i - 1] + dp[i - 2];
				}
				else {
					dp[i] = dp[i - 1];
				}
			}

		}
		return dp[n - 1];


		//int rs = 0;
		//int n = s.size();
		//int current_length = 0;//记录当前处理过的长度
		//help(s, rs, 0, n, current_length);
		//return rs;
	}
	void help(string &s, int &rs, int start, int n, int current_length) {
		if (current_length == n)
			rs++;
		if (start >= n) {
			return;
		}
		for (int i = start; i<n; i++) {
			string one_iter;
			int current_start = start;
			if (s[i] == '0')
				continue;
			while (current_start<n) {
				one_iter += s[current_start];
				if (atoi(one_iter.c_str())>26)
					break;
				current_start++;
				current_length += current_start - i;
				help(s, rs, current_start, n, current_length);
				current_length -= current_start - i;
			}
		}
	}
};
//int main() {
//	Solution s;
//	s.numDecodings("10");
//}