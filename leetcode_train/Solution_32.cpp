#include<string>
#include<algorithm>
#include<stack>
using namespace std;

//dfs 找出所有的可能


//扫描整个字符串
//如果是（，就保存位置
//如果是），就弹出一个（，进行配对，若不能弹出，则是非法的，或者弹出（，也是非法的
//
//结束后，栈中保存所有的非法下标，用相邻的下标进行相减



class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		stack<int>un_legal;
		for (int i = 0; i<n; i++) {
			if (s[i] == '(')
				un_legal.push(i);
			else {
				if (!un_legal.empty()) {
					if (s[un_legal.top()] == '(')
						un_legal.pop();
					else
						un_legal.push(i);
				}
				else {
					un_legal.push(i);
				}
			}
		}
		if (un_legal.empty())
			return n;
		int right = n;
		int left = 0;
		int rs = 0;
		while (!un_legal.empty()) {
			left = un_legal.top();
			un_legal.pop();
			rs = max(rs, right - left - 1);
			right = left;
		}
		rs = max(rs, left);
		return rs;
	}
};