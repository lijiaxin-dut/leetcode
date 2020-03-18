#include<string>

using namespace std;


//Given a word, you need to judge whether the usage of capitals in it is right or not.
//
//We define the usage of capitals in a word to be right when one of the following cases holds :
//
//All letters in this word are capitals, like "USA".
//All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital, like "Google".
//Otherwise, we define that this word doesn't use capitals in a right way.
//
//
//Example 1:
//
//Input: "USA"
//	Output : True


//根据首字母大小分类

class Solution {
	bool is_all_capital(string &s, int start_index) {
		for (int i = start_index; i<s.size(); i++)
			if (!(s[i] >= 'A'&&s[i] <= 'Z'))
				return false;
		return true;
	}
	bool is_all_not_capital(string &s, int start_index) {
		for (int i = start_index; i<s.size(); i++)
			if (!(s[i] >= 'a'&&s[i] <= 'z'))
				return false;
		return true;

	}
public:
	bool detectCapitalUse(string s) {
		if (s.empty())
			return false;
		if (s[0] >= 'a'&&s[0] <= 'z') {
			return is_all_not_capital(s, 1);
		}
		else if (s[0] >= 'A'&&s[0] <= 'Z') {
			return is_all_capital(s, 1) || is_all_not_capital(s, 1);
		}
		return false;
	}
};