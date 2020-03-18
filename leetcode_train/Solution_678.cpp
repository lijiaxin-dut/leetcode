#include<string>
#include<vector>
#include<stack>


using namespace std;
//
//Given a string containing only three types of characters : '(', ')' and '*', write a function to check whether this string is valid.We define the validity of a string by these rules :
//
//Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//Any right parenthesis ')' must have a corresponding left parenthesis '('.
//Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
//An empty string is also valid.

//穷举所有的可能


class Solution {
	//使用两个栈，保存*和(的位置
	//遇到）时，优先弹出（，不存在的话弹出*
	//结束时，判断左括号是否为空
	//
	bool checkValidString_stack(string s) {
		stack<int>left;
		stack<int>start;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] == '(')
				left.push(i);
			else if (s[i] == '*')
				start.push(i);
			else {
				if (left.empty() && start.empty())
					return false;
				if (!left.empty())
					left.pop();
				else {
					start.pop();
				}
			}
		}
		while (!left.empty() && !start.empty()) {
			if (left.top()>start.top())
				return false;
			left.pop();
			start.pop();
		}
		return left.empty();
	}

public:
	//2222222222222222222222222
	vector<vector<int>>m;
public:
	bool checkValidString_2(string s) {
		int n = s.size();
		m.resize(n, vector<int>(n, -1));
		return help_2(s, 0, n - 1);
	}
	bool help_2(string &s, int left, int right) {
		//空字符串
		if (left>right)
			return true;
		if (left == right)
			return s[left] == '*';
		if (m[left][right] >= 0)
			return m[left][right];
		//两端是合法的
		if ((s[left] == '*' || s[left] == '(') && (s[right] == ')' || s[right] == '*') && help_2(s, left + 1, right - 1)) {
			m[left][right] = 1;
			return m[left][right];
		}
		//可能跟中间的进行匹配
		for (int p = left; p<right; p++) {
			if (help_2(s, left, p) && help_2(s, p + 1, right)) {
				m[left][right] = 1;
				return m[left][right];
			}
		}
		m[left][right] = 0;
		return m[left][right];

	}




	//1111111111111111111111111111111
	bool checkValidString_dfs(string s) {
		return help_dfs(s, 0, 0, 0);
	}
	bool help_dfs(string &s, int cur_index, int left_size, int right_size) {
		if (right_size>left_size)
			return false;
		for (int i = cur_index; i<s.size(); i++) {
			if (s[i] == '(')
				left_size++;
			else if (s[i] == ')')
				right_size++;

			if (right_size>left_size)
				return false;
			if (s[i] == '*')
				return help_dfs(s, i + 1, left_size + 1, right_size) ||
				help_dfs(s, i + 1, left_size, right_size + 1) ||
				help_dfs(s, i + 1, left_size, right_size);
		}
		return left_size == right_size;
	}
};