//请你帮忙设计一个程序，用来找出第 n 个丑数。
//
//丑数是可以被 a 或 b 或 c 整除的 正整数。
//
//
//
//示例 1：
//
//输入：n = 3, a = 2, b = 3, c = 5
//输出：4
//解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10...其中第 3 个是 4。
//

class Solution {
	long gcd(long x, long y) {
		if (x == 0)
			return y;
		return gcd(y % x, x);
	}
	long lcm(long a, long b) {
		return a*b / gcd(a, b);
	}
public:
	int nthUglyNumber(int n, int a, int b, int c) {
		long lcmAB = lcm(a, b);
		long lcmAC = lcm(a, c);
		long lcmBC = lcm(b, c);
		// 三个数的最小公倍数
		long lcmABC = lcm(lcmAB, c);
		long left = 1;
		long right = 2e9;
		while (left<right) {
			long mid = left + (right - left) / 2;
			long size = mid / a + mid / b + mid / c - mid / lcmAB - mid / lcmAC - mid / lcmBC + mid / lcmABC;
			if (size >= n) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};