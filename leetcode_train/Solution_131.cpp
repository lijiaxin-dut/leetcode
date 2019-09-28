#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>


using namespace std;
//
//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//Example:
//
//Input: "aab"
//	Output :
//	[
//		["aa", "b"],
//		["a", "a", "b"]
//	]

//dfs遍历所有的组合
//辅助函数判断字串是否时回文的

class Solution_131 {
	bool is_para(string &s, int start, int end) {
		while (start<end) {
			if (s[start++] != s[end--]) {
				return false;
			}
		}
		return true;
	}
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> rs;
		vector<string>partial_rs;
		help(rs, 0, s, partial_rs);
		return rs;


	}
	void help(vector<vector<string>> &rs, int start, string &s, vector<string>partial_rs) {
		if (start == s.size())
		{
			rs.push_back(partial_rs);
			return;
		}
		for (int i = start; i<s.size(); i++) {
			if (is_para(s, start, i) == true) {
				partial_rs.push_back(s.substr(start, i - start + 1));
				help(rs, i + 1, s, partial_rs);
				partial_rs.pop_back();
			}

		}
	}
};

//int main() {
//	Solution_131 S;
//	S.partition("aab");
//}