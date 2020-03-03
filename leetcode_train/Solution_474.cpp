#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

//
//In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
//
//For now, suppose you are a dominator of m 0s and n 1s respectively.On the other hand, there is an array with strings consisting of only 0s and 1s.
//
//Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s.Each 0 and 1 can be used at most once.

//二维0 1背包问题



class Solution {
	void count(string &s, int &one, int &zero) {
		for (auto &one_char : s) {
			if (one_char == '0')
				zero++;
			else
				one++;
		}
	}
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int num = strs.size();
		vector<vector<vector<int>>>dp(num + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
		for (int i = 1; i <= num; i++) {
			for (int cur_zero = 0; cur_zero <= m; cur_zero++) {
				for (int cur_one = 0; cur_one <= n; cur_one++) {
					int zero = 0;
					int one = 0;
					count(strs[i - 1], one, zero);
					if (zero <= cur_zero&&one <= cur_one)
						dp[i][cur_zero][cur_one] = max(dp[i - 1][cur_zero][cur_one], dp[i - 1][cur_zero - zero][cur_one - one] + 1);
					else
						dp[i][cur_zero][cur_one] = dp[i - 1][cur_zero][cur_one];

				}

			}
		}
		return dp[num][m][n];
	}
};