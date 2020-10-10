//给定一个正整数 n，返回长度为 n 的所有可被视为可奖励的出勤记录的数量。 答案可能非常大，你只需返回结果mod 109 + 7的值。
//
//学生出勤记录是只包含以下三个字符的字符串：
//
//'A' : Absent，缺勤
//'L' : Late，迟到
//'P' : Present，到场
//如果记录不包含多于一个'A'（缺勤）或超过两个连续的'L'（迟到），则该记录被视为可奖励的。

//dp[i][i][j]表示前i个物品，有i个A，末尾j个L
//dp[i][0][0]：无 A，末尾无 0 个 L，简记 0A0L，如 ..PLP..PLLP..LP
//dp[i][0][1]：0A1L，如 ..PLP..PLLP..PL
//dp[i][0][2]：0A2L，如 ..PLP..PLLP..PLL
//dp[i][1][0]：1A0L，如 ..PLP..A..PLLP..P / ..PLP..PLLP..A
//dp[i][1][1]：1A1L，如 ..PLP..A..PLLP..PL
//dp[i][1][2]：1A2L，如 ..PLP..A..PLLP..PLL

//通过加字母改变状态


class Solution {
public:
	long dp[100001][2][3];
	int checkRecord(int n) {
		int mod = 1e9 + 7;
		dp[1][1][0] = 1; // A
		dp[1][0][1] = 1; // L
		dp[1][0][0] = 1; // P
		for (int i = 2; i <= n; i++) {
			//加P
			dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod;
			dp[i][1][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % mod;
			//加L
			dp[i][0][1] = dp[i - 1][0][0];
			dp[i][0][2] = dp[i - 1][0][1];
			dp[i][1][1] = dp[i - 1][1][0];
			dp[i][1][2] = dp[i - 1][1][1];
			//加A
			dp[i][1][0] += (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod;
		}
		return  (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % mod;

	}
};