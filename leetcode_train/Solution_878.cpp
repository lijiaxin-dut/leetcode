#include<vector>

#include<algorithm>

using namespace std;
//如果正整数可以被 A 或 B 整除，那么它是神奇的。
//
//返回第 N 个神奇数字。由于答案可能非常大，返回它模 10 ^ 9 + 7 的结果。


//l = A、B的最小公倍数
//f(x) 为小于等于x的神奇数字，f(x) = x/a+x/b-x/l
//然后二分法进行搜索

class Solution {
public:
	int nthMagicalNumber(int N, int A, int B) {
		int MOD = 1e9 + 7;
		int L = A / gcd(A, B) * B;

		long lo = 0;
		long hi = (long)max(A, B) * N;
		while (lo < hi) {
			long mid = lo + (hi - lo) / 2;
			if (mid / A + mid / B - mid / L < N)
				lo = mid + 1;
			else
				hi = mid;
		}

		return (int)(lo % MOD);
	}

	int gcd(int x, int y) {
		if (x == 0) return y;
		return gcd(y % x, x);
	}
};