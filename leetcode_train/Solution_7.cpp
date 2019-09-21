#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
//
//Given a 32 - bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//	Output : 321
//	Example 2 :
//
//	Input : -123
//	Output : -321
//	Example 3 :
//
//	Input : 120
//	Output : 21

//单独考虑-INT_MAX
//-INT_MAX的 reverse溢出
//reverse之后可能发生溢出， 使用long保存结果


class Solution_7 {
public:
	int reverse(int x) {
		string s;
		if (x == INT_MIN)
			return 0;
		bool is_negative = false;
		if (x<0) {
			is_negative = true;
			x = -x;
		}
		long rs = 0;
		while (x>0) {
			int number = x % 10;
			x /= 10;
			rs = rs * 10;
			rs += number;

		}
		if (rs>INT_MAX)
			return 0;
		if (is_negative == true)
			rs = -rs;
		return int(rs);

	}
};