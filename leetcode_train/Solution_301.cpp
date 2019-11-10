#include<string>
#include<vector>

using namespace std;

//Remove the minimum number of invalid parentheses in order to make the input string valid.Return all possible results.
//
//Note: The input string may contain letters other than the parentheses(and).
//
//	Example 1 :
//
//	Input : "()())()"
//	Output : ["()()()", "(())()"]
//	Example 2 :
//
//	Input : "(a)())()"
//	Output : ["(a)()()", "(a())()"]


//分别记录左括号多出来的个数和右括号多出来的个数
//然后递归，不断的删除多出来的括号
//注意去重

class Solution_301 {
	bool is_valid(string t) {
		int cnt = 0;
		for (auto &c : t) {
			if (c == '(')
				cnt++;
			else if (c == ')') {
				cnt--;
				if (cnt<0)
					return false;
			}
		}
		return true;
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		int c1 = 0;
		int c2 = 0;
		for (char c : s) {
			if (c == '(')
				c1++;
			if (c == ')') {
				if (c1 == 0)
					c2++;
				else
					c1--;
			}
		}
		vector<string>rs;
		dfs(0, c1, c2, s, rs);
		return rs;

	}

	void dfs(int start, int c1, int c2, string s, vector<string>&rs) {
		if (c1 == 0 && c2 == 0) {
			if (is_valid(s))
				rs.push_back(s);
			return;
		}
		for (int i = start; i<s.size(); i++) {
			if (i != start&&s[i] == s[i - 1])
				continue;
			if (c1>0 && s[i] == '(')
				dfs(i, c1 - 1, c2, s.substr(0, i) + s.substr(i + 1), rs);
			if (c2>0 && s[i] == ')')
				dfs(i, c1, c2 - 1, s.substr(0, i) + s.substr(i + 1), rs);
		}
	}
};