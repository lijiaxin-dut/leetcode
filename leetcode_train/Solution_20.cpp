#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;


//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.


//使用栈保存遇见过的左括号
//遇见右括号就弹出
//判断是否匹配

class Solution_20 {
public:
	bool isValid(string s) {
		if (s.size() % 2 == 1)
			return false;
		stack<char>left_pa;
		for (auto &one_pa : s) {
			if (one_pa == '(' || one_pa == '{' || one_pa == '[')
				left_pa.push(one_pa);
			else
			{
				if (left_pa.empty())
					return false;
				auto top = left_pa.top();
				left_pa.pop();
				if (top == '('&&one_pa != ')')
					return false;
				else if (top == '{'&&one_pa != '}')
					return false;
				else if (top == '['&&one_pa != ']')
					return false;
			}
		}
		if (left_pa.empty())
			return true;
		else
			return false;

	}
};