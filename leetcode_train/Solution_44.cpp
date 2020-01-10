#include<string>
using namespace std;

//Given an input string(s) and a pattern(p), implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//The matching should cover the entire input string(not partial).
//
//Note:
//
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like ? or *.

//1.递归，穷举所有的可能

//2.贪心
//依次判断是否相等，
//若出现*号，首先假设出现两次，但记录*对应的位置，在s中对应的位置，p中对象的位置
//若不相等，也不是*
//若之前出现过*号，首先假设*出现了一次返回*的位置重新开始遍历

class Solution_44 {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, i_start = -1, j_start = -1, m = s.size(), n = p.size();
		while (i<m) {
			if (j<n && (s[i] == p[j] || p[j] == '?')) {
				i++;
				j++;
			}
			else if (j<n&&p[j] == '*') {
				i_start = i;
				j_start = j;
				j++;
			}
			else if (i_start >= 0) {
				i = i_start;
				i_start++;
				j = j_start + 1;
			}
			else
				return false;
		}
		while (j<n&&p[j] == '*')
			j++;
		return j == n;

	}

	bool isMatch_recur(string s, string p) {
		return help(s, p, 0, 0);
	}
	bool help(string &s, string &p, int s_index, int p_index) {
		if (s_index == s.size() && p_index == p.size())
			return true;
		if (s_index == s.size() || p_index == p.size()) {
			if (s_index == s.size()) {
				while (p_index<p.size()) {
					if (p[p_index++] != '*')
						return false;
				}
				return true;
			}
			else
				return false;
		}
		if (s[s_index] == p[p_index])
			return help(s, p, s_index + 1, p_index + 1);
		else if (p[p_index] == '?')
			return help(s, p, s_index + 1, p_index + 1);
		else if (p[p_index] == '*')
			return help(s, p, s_index + 1, p_index) || help(s, p, s_index, p_index + 1);
		return false;
	}
};