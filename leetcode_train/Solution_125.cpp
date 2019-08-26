#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Description
//Given a string, determine if it is a palindrome, considering only alphanumeric 
//characters and ignoring cases.

//Note: For the purpose of this problem, we define empty string as valid palindrome.


//isalpha()  判断一个char是不是数字或者字母

class Solution_125 {
public:
	bool isPalindrome(string s) {
		if (s.size() <= 1)
			return true;
		int lo = 0;
		int hi = s.size() - 1;
		while (lo<hi) {
			while (lo<hi&&isalpha(s[lo]) == false)
				lo++;
			while (lo<hi&&isalpha(s[hi]) == false)
				hi--;
			if (lo<hi&&toupper(s[lo]) != toupper(s[hi]))
				return false;
			else if (lo >= hi) {
				return true;
			}
			else {
				lo++;
				hi--;
			}
		}
		return true;
	}
};

