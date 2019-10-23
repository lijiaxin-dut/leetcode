#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Given a non - negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
//
//	Example:
//
//Input: 2
//	Output : 91
//	Explanation : The answer should be the total numbers in the range of 0 ≤ x < 100,
//	excluding 11, 22, 33, 44, 55, 66, 77, 88, 99


//给定n位数，找出每一位都不同的数字

//1.dfs
//2.n位数，每位数字都不同的个数 9*9*8*7...
//dp[n]=dp[n-1]*ava_number
//dp[4]=dp[3]*7
//对所有的n求和
//单独考虑0和1


class Solution {
public:
	int countNumbersWithUniqueDigits_1(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 10;
		vector<int>dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 9;
		int ava_number = 9;
		int rs = 10;
		for (int i = 2; i <= n&&ava_number>0; i++) {
			dp[i] = dp[i - 1] * ava_number;
			rs += dp[i];
			ava_number--;
		}
		return rs;
	}

	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)
			return 1;
		int current_digits = 1;
		vector<bool>mark(10, false);
		int rs = 1;
		for (int i = 1; i <= 9; i++) {
			mark[i] = true;
			rs++;
			dfs(mark, rs, n, current_digits);
			mark[i] = false;
		}
		return rs;

	}
	void dfs(vector<bool>&mark, int &rs, const int n, int &current_digits) {
		if (current_digits == n) {
			return;
		}
		for (int i = 0; i <= 9; i++) {
			if (mark[i] == true)
				continue;
			rs++;
			mark[i] = true;
			current_digits++;
			dfs(mark, rs, n, current_digits);
			mark[i] = false;
			current_digits--;
		}
	}
};