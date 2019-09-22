#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;


//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower", "flow", "flight"]
//	Output : "fl"
//	Example 2 :
//
//	Input : ["dog", "racecar", "car"]
//	Output : ""
//	Explanation : There is no common prefix among the input strings.
//	Note :
//
//	All given inputs are in lowercase letters a - z.

class Solution_14 {
public:
	string help(string &lhs, string &rhs) {
		if (lhs.empty() || rhs.empty())
			return "";
		int i = 0;
		int n = min(lhs.size(), rhs.size());
		while (i<n&&i<n) {
			if (lhs[i] != rhs[i]) {
				return lhs.substr(0, i);
			}
			i++;
		}
		return lhs.substr(0, n);

	}
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		string rs = strs[0];
		for (int i = 1; i<strs.size(); i++) {
			rs = help(rs, strs[i]);
		}
		return rs;
	}
};