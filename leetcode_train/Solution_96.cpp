#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
//Example:
//
//Input: 3
//	Output : 5
//	Explanation :
//	Given n = 3, there are a total of 5 unique BST's:
//
//	1         3     3      2      1
//	\ / / / \      \
//	3     2     1      1   3      2
//	/ / \                 \
//	2     1         2                 3




//����������� dfs
//1,2,3,4,5,6,7,8
//���ѡ4��Ϊ���ڵ�
//rs[4]=rs[1-3]*rs[5-8]
//ʹ��dp[i][j]��¼i->j����Ŀ���´�����ʱֱ�Ӳ��


//��̬�滮
//dp[i]��ʾi���ڵ㹹����Ŀ�Ŀ�����
//dp[i]+=dp[j]*dp[i-j-i]�������������л���
class Solution_96 {
public:
	int numTrees_1(int n) {
		int rs = 0;
		vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; i++)
			dp[i][i] = 1;
		rs = help(dp, 1, n);
		return rs;
	}
	int help(vector<vector<int>>&dp, int start, int end) {
		if (start>end)
			return 0;
		if (start == end)
			return 1;
		if (dp[start][end] != 0)
			return dp[start][end];
		int rs = 0;
		for (int i = start; i <= end; i++) {
			if (i == start) {
				dp[start + 1][end] = help(dp, start + 1, end);
				rs += dp[start + 1][end];
			}
			else if (i == end) {
				dp[start][end - 1] = help(dp, start, end - 1);
				rs += dp[start][end - 1];
			}
			else {
				dp[start][i - 1] = help(dp, start, i - 1);
				dp[i + 1][end] = help(dp, i + 1, end);
				rs += dp[start][i - 1] * dp[i + 1][end];
			}
		}
		return rs;
	}

	int numTrees(int n) {
		vector<int>dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j<i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};