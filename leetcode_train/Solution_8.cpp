#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//实现字符串转数字
//忽略开始的空格
//忽略空格后，第一个字符若是+ - 或者数字，记录，否则不合法
//已知找到下一个不是数字的位置，停止
//生成数字的过程中，判断是否溢出

class Solution_8 {
public:
	int myAtoi(string str) {
		int n = str.size();
		int first_sign_or_number = -1;
		for (int i = 0; i<n; i++) {
			if (str[i] == ' ')
				continue;
			if (str[i] == '-' || str[i] == '+' || (str[i] >= '0'&&str[i] <= '9')) {
				first_sign_or_number = i;
				break;
			}
			else {
				return 0;
			}
		}
		if (first_sign_or_number == -1)
			return 0;
		bool is_negative = false;
		long rs = 0;
		if (str[first_sign_or_number] == '-' || str[first_sign_or_number] == '+') {
			if (str[first_sign_or_number] == '-')
				is_negative = true;
			first_sign_or_number++;
		}
		for (int i = first_sign_or_number; i<n; i++) {
			if (str[i] >= '0'&&str[i] <= '9') {
				rs = rs * 10 + (str[i] - '0');
				if (rs>INT_MAX&&is_negative == false)
					return INT_MAX;
				if (is_negative == true && -rs<INT_MIN)
					return INT_MIN;
			}
			else
				break;

		}
		if (is_negative)
			rs = -rs;
		return int(rs);

	}
};


//int main() {
//	Solution_8 s;
//	s.myAtoi("-42");
//}