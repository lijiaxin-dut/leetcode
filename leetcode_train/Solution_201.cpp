//Given a range[m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//Example 1:
//
//Input: [5, 7]
//	Output : 4
//	Example 2 :
//
//	Input : [0, 1]
//	Output : 0

//
//找m和n的前缀有多少相同的位数
//不断的将m\n向右移动
//直至相等，然后恢复原来的位数即可

//那个例子不太明显，我们再来看一个范围[26, 30]，它们的二进制如下：
//
//11010　　11011　　11100　　11101　　11110

//观察左边有多少相同的位数即可
class Solution_201 {
public:
	int rangeBitwiseAnd(int m, int n) {
		int c = 0;
		while (m != n) {
			m = m >> 1;
			n = n >> 1;
			c++;
		}
		return m << c;
	}
};