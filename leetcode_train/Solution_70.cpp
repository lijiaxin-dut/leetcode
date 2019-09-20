#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Note : Given n will be a positive integer.
//
//	Example 1 :
//
//	Input : 2
//	Output : 2
//	Explanation : There are two ways to climb to the top.
//	1. 1 step + 1 step
//	2. 2 steps

//¶¯Ì¬¹æ»®
//dp[i]=dp[i-1]+dp[i-2]

class Solution_70 {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		vector<int>dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 2] + dp[i - 1];
		}
		return dp[n];
	}
};