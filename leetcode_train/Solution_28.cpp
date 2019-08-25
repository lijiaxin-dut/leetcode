#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description
//Implement strStr().
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//当被查询的字串长度为0时，返回0

class Solution_28 {
	bool help(string haystack, string needle, int start_index) {
		for (int i = start_index, j = 0; i<haystack.size() && j<needle.size(); i++, j++) {
			if (haystack[i] != needle[j])
				return false;
		}
		return true;
	}
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		if (needle.size()>haystack.size())
			return -1;
		for (int i = 0; i<haystack.size(); i++) {
			if (i + needle.size()>haystack.size())
				return -1;
			if (help(haystack, needle, i) == true)
				return i;
		}
		return -1;
	}
};

