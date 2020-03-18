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

//遇到括号时，把目前的结果存起来，把括号前的符号存起来

class Solution_224 {
public:


	int calculate_complexe(string s) {
		//最开始默认为正数，op为当前数字之前的操作符
		//不断的把数字放入栈中，遇到括号时，进行递归调用
		//遇到*/时，与栈顶元素进行结合
		char op = '+';
		stack<int>nums;
		int n = s.size();
		int num = 0;
		for (int i = 0; i<n; i++) {
			if (s[i] >= '0'&&s[i] <= '9')
				num = num * 10 + (s[i] - '0');
			else if (s[i] == '(') {
				int left = i;
				int right = left;
				int count = 0;
				for (int j = left; j<n; j++) {
					if (s[j] == '(')
						count++;
					else if (s[j] == ')')
						count--;
					if (count == 0) {
						right = j;
						break;
					}
				}
				num = calculate(s.substr(i + 1, right - left - 1));
				i = right + 1;
			}
			//上一个数字处理完毕，进行运算
			if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
				if (op == '+')
					nums.push(num);
				else if (op == '-')
					nums.push(-num);
				else if (op == '*') {
					nums.top() = nums.top()*num;
				}
				else if (op == '/') {
					nums.top() = nums.top() / num;
				}
				op = s[i];
				num = 0;
			}
		}
		long rs = 0;
		while (!nums.empty()) {
			rs += nums.top();
			nums.pop();
		}
		return rs;
	}
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