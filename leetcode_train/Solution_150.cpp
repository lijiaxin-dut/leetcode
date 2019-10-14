#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//
//Note:
//
//Division between two integers should truncate toward zero.
//The given RPN expression is always valid.That means the expression would always 
//evaluate to a result and there won't be any divide by zero operation.

//使用栈保存遇见过的数字
//遇到一个运算符
//从栈中弹出数字进行运算



class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int>nums;
		for (const auto &one_sym : tokens) {
			if (one_sym == "+") {
				auto s = nums.top();
				nums.pop();
				auto f = nums.top();
				nums.pop();
				nums.push(s + f);
			}
			else if (one_sym == "-") {
				auto s = nums.top();
				nums.pop();
				auto f = nums.top();
				nums.pop();
				nums.push(f - s);

			}
			else if (one_sym == "*") {
				auto s = nums.top();
				nums.pop();
				auto f = nums.top();
				nums.pop();
				nums.push(s*f);

			}
			else if (one_sym == "/") {
				auto s = nums.top();
				nums.pop();
				auto f = nums.top();
				nums.pop();
				nums.push(f / s);

			}
			else {
				nums.push(stoi(one_sym.c_str()));

			}
		}
		return nums.top();

	}
};