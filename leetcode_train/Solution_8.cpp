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
//正数和负数判断溢出的方式不同，范围不同

class Solution_8 {
public:
	int myAtoi(string str) {
		int n = str.size();
		
		bool is_negative = false;
		int cur_index = 0;
		for (; cur_index<n; cur_index++) {
			if (str[cur_index] == ' ')
				continue;
			else if (str[cur_index] == '+') {
				cur_index++;
				break;
			}
			else if (str[cur_index] == '-') {
				cur_index++;
				is_negative = true;
				break;
			}
			else if (str[cur_index] >= '0'&&str[cur_index] <= '9') {
				break;
			}
			else
				return 0;
		}
		int rs = 0;
		for (; cur_index<n; cur_index++) {
			if (str[cur_index] >= '0'&&str[cur_index] <= '9') {
				if (rs > INT_MAX / 10 || (rs == INT_MAX / 10 && str[cur_index] > '7')) {
					if (is_negative == false)
						return INT_MAX;
					if (is_negative == true)
						return INT_MIN;
				}
				rs = 10 * rs + (str[cur_index] - '0');
				
			}
			else
				break;
		}
		if (is_negative == true)
			rs = -rs;
		return rs;

	}
};


//int main() {
//	Solution_8 s;
//	s.myAtoi("-42");
//}