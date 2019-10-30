#include<algorithm>

using namespace std;
//
//Given a positive integer n and you can do operations as follow :
//
//If n is even, replace n with n / 2.
//If n is odd, you can replace n with either n + 1 or n - 1.
//What is the minimum number of replacements needed for n to become 1 ?

//dfs   ����2ʱ��ֱ�ӳ���2
//��������ʱ������min(n+1,n-1),+1  -1����Ҫ����


class Solution_397 {
public:
	int integerReplacement(int n) {
		return dfs(n) - 1;
	}
	long dfs(long n) {
		if (n == 1)
			return 1;
		if (n % 2 == 1)
			return min(dfs(n + 1), dfs(n - 1)) + 1;
		else
			return dfs(n / 2) + 1;
	}
};