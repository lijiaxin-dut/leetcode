#include<string>
#include<sstream>

using namespace std;


//You are given a license key represented as a string S which consists only alphanumeric character and dashes.The string is separated into N + 1 groups by N dashes.
//
//Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character.Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.
//
//Given a non - empty string S and a number K, format the string according to the rules described above.

//从后向前一次划分


class Solution {
	string split(string s) {
		stringstream ss(s);
		string rs;
		while (getline(ss, s, '-')) {
			if (!s.empty())
				rs += s;
		}
		return rs;
	}
public:
	string licenseKeyFormatting(string S, int K) {
		string new_s = split(S);
		string rs;
		int cur_length = 0;
		for (int i = new_s.size() - 1; i >= 0; i--) {
			rs.push_back(new_s[i]);
			cur_length++;
			if (cur_length%K == 0)
				rs.push_back('-');

		}
		if (rs.back() == '-')
			rs.pop_back();
		reverse(rs.begin(), rs.end());
		for (int i = 0; i<rs.size(); i++) {
			if (isalpha(rs[i]))
				rs[i] = toupper(rs[i]);
		}
		return rs;

	}
};