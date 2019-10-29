#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses), the plus + or minus sign - , non - negative integers and empty spaces .
//
//Example 1:
//
//Input: "1 + 1"
//	Output : 2
//	Example 2 :
//
//	Input : " 2-1 + 2 "
//	Output : 3
//	Example 3 :
//
//	Input : "(1+(4+5+2)-3)+(6+8)"
//	Output : 23

//只有加法和减法，不用考虑优先级问题
//遇到一个数字时，就将连续的数字取出来，表示一个数字
//记录数字前的符号

class Solution_224 {
public:
	int calculate(string s) {
		int res = 0;
		int sign = 1;
		int n = s.size();
		stack<int>nums;
		stack<int>symbol;
		for (int i = 0; i<n; i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				int num = 0;
				while (i<n&&s[i] >= '0'&&s[i] <= '9') {
					num = num * 10 + (s[i] - '0');
					i++;
				}
				i--;
				res = res + sign*num;
			}
			else if (s[i] == '+') {
				sign = 1;
			}
			else if (s[i] == '-') {
				sign = -1;
			}
			else if (s[i] == '(') {
				nums.push(res);
				symbol.push(sign);
				sign = 1;
				res = 0;
			}
			else if (s[i] == ')') {
				sign = symbol.top();
				symbol.pop();
				res = res*sign;
				res += nums.top();
				nums.pop();
			}
		}
		return res;

	}
};