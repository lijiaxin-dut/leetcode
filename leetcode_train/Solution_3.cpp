#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

//Description
//Given a string, find the length of the longest substring without repeating characters.

//Commonly used tables are:
//int[26] for Letters 'a' - 'z' or 'A' - 'Z'
//int[128] for ASCII
//int[256] for Extended ASCII

class Solution_3 {
public:
	int lengthOfLongestSubstring_(string s) {
		if (s.empty())
			return 0;
		vector<bool>mark(128, 0);
		int rs = 0;
		int left = 0;
		for (int i = 0; i<s.size(); i++) {
			if (mark[s[i]] == 0) {
				mark[s[i]] = 1;
				rs = max(rs, i - left + 1);
			}
			else {
				i--;
				mark[s[left]] = 0;
				left++;

			}
		}
		return rs;
	}
};
