#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non - negative integers, +, -, *, / operators and empty spaces.The integer division should truncate toward zero.
//
//Example 1:
//
//Input: "3+2*2"
//	Output : 7
//	Example 2 :
//
//	Input : " 3/2 "
//	Output : 1
//	Example 3 :
//
//	Input : " 3+5 / 2 "
//	Output : 5


//�г˳����������������ִ���ջ��
//��¼����֮ǰ�Ĳ�����
//�����˷��ͳ���ʱ����ջ������Ԫ�أ��������㣬��������������ջ

class Solution_227 {
public:
	int calculate(string s) {
		char op = '+';
		stack<int>nums;
		long num = 0;
		int n = s.size();
		for (int i = 0; i<n; i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				num = num * 10 + (s[i] - '0');
			}
			if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
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
};