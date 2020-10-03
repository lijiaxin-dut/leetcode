#include<vector>

#include<algorithm>

using namespace std;
//������������Ա� A �� B ��������ô��������ġ�
//
//���ص� N ���������֡����ڴ𰸿��ܷǳ��󣬷�����ģ 10 ^ 9 + 7 �Ľ����


//l = A��B����С������
//f(x) ΪС�ڵ���x���������֣�f(x) = x/a+x/b-x/l
//Ȼ����ַ���������

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