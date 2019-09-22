#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]

//dfs穷举所有的可能性
//有左括号了才可以添加右括号







class Solution_22 {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>rs;
		string current_ps;
		help(rs, current_ps, 0, 0, n);
		return rs;
	}
	void help(vector<string>&rs, string &current_ps, int left_size, int right_size, int n) {
		if (left_size == n&&right_size == n) {
			rs.push_back(current_ps);
			return;
		}
		if (left_size>right_size&&right_size<n) {
			current_ps.push_back(')');
			help(rs, current_ps, left_size, right_size + 1, n);
			current_ps.pop_back();

		}
		if (left_size<n) {
			current_ps.push_back('(');
			help(rs, current_ps, left_size + 1, right_size, n);
			current_ps.pop_back();
		}

	}
};