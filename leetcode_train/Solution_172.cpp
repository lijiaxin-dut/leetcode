//Given an integer n, return the number of trailing zeroes in n!.
//
//Example 1:
//
//Input: 3
//	Output : 0
//	Explanation : 3!= 6, no trailing zero.
//	Example 2 :
//
//	Input : 5
//	Output : 1
//	Explanation : 5!= 120, one trailing zero.


//0由*10得到
//10=2*5
//乘数中统计5的个数即可
//5  10  15   20  25  ....
//100/5=20

//还要考虑25 125   ...由多个五乘积得到的数字



class Solution {
public:
	int trailingZeroes_recur(int n) {
		return help(n, 5);

	}
	int help(int n, long long cur_number) {
		if (cur_number>n)
			return 0;
		return n / cur_number + help(n, cur_number * 5);
	}
	int trailingZeroes(int n) {
		int rs = 0;
		for (long int i = 5; n / i>0; i = i * 5)
		{
			rs += n / i;
		}
		return rs;
	}
};