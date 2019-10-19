#include<vector>
#include<string>

using namespace std;

//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//Example 1:
//
//Input: s = "anagram", t = "nagaram"
//	Output : true
//	Example 2 :
//
//	Input : s = "rat", t = "car"
//	Output : false

//统计每个字符串字符出现的次数，进行比较



class Solution_242 {
public:
	bool isAnagram(string s, string t) {
		vector<int>mark_s(26);
		vector<int>mark_t(26);
		for (int i = 0; i<s.size(); i++) {
			mark_s[s[i] - 'a']++;
		}
		for (int i = 0; i<t.size(); i++) {
			mark_t[t[i] - 'a']++;
		}
		return mark_s == mark_t;

	}
};