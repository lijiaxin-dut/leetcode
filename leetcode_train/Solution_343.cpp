#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.Return the maximum product you can get.
//
//Example 1:
//
//Input: 2
//	Output : 1
//	Explanation : 2 = 1 + 1, 1 × 1 = 1.


//dp
//dp[i]表示至少两个数相乘的结果
//dp[i] = max(dp[i], max(j*(i - j), dp[i - j] * j)); j=1...i-1
//单独考虑两个数字乘积最大的情况
//如7
//dp[7]=max(dp[7],3*4,dp[3]*4)

//如果递推式忽略了j*(i - j)，结果是至少三个数相乘了



//或者 找规律

//数字3可以拆分成 2 + 1 或 1 + 1 + 1，显然第一种拆分方法乘积大为2。
//
//数字4拆成 2 + 2，乘积最大，为4。
//
//数字5拆成 3 + 2，乘积最大，为6。
//
//数字6拆成 3 + 3，乘积最大，为9。
//
//数字7拆为 3 + 4，乘积最大，为 12。
//
//数字8拆为 3 + 3 + 2，乘积最大，为 18。
//
//数字9拆为 3 + 3 + 3，乘积最大，为 27。
//
//数字10拆为 3 + 3 + 4，乘积最大，为 36。
//
//....
//
//那么通过观察上面的规律，我们可以看出从5开始，数字都需要先拆出所有的3，一直拆到剩下一个数为2或者4，



class Solution_343
{
public:
	int integerBreak_1(int n) {
	if (n == 2 || n == 3) return n - 1;
	int res = 1;
	while (n > 4) {
		res *= 3;
		n -= 3;
	}
	return res * n;
}
	int integerBreak(int n) {
		vector<int>dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j<i; j++) {
				dp[i] = max(dp[i], max(j*(i - j), dp[i - j] * j));
			}
		}
		return dp[n];
	}
};