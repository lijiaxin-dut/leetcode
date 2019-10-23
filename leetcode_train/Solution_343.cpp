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
//	Explanation : 2 = 1 + 1, 1 �� 1 = 1.


//dp
//dp[i]��ʾ������������˵Ľ��
//dp[i] = max(dp[i], max(j*(i - j), dp[i - j] * j)); j=1...i-1
//���������������ֳ˻��������
//��7
//dp[7]=max(dp[7],3*4,dp[3]*4)

//�������ʽ������j*(i - j)����������������������



//���� �ҹ���

//����3���Բ�ֳ� 2 + 1 �� 1 + 1 + 1����Ȼ��һ�ֲ�ַ����˻���Ϊ2��
//
//����4��� 2 + 2���˻����Ϊ4��
//
//����5��� 3 + 2���˻����Ϊ6��
//
//����6��� 3 + 3���˻����Ϊ9��
//
//����7��Ϊ 3 + 4���˻����Ϊ 12��
//
//����8��Ϊ 3 + 3 + 2���˻����Ϊ 18��
//
//����9��Ϊ 3 + 3 + 3���˻����Ϊ 27��
//
//����10��Ϊ 3 + 3 + 4���˻����Ϊ 36��
//
//....
//
//��ôͨ���۲�����Ĺ��ɣ����ǿ��Կ�����5��ʼ�����ֶ���Ҫ�Ȳ�����е�3��һֱ��ʣ��һ����Ϊ2����4��



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