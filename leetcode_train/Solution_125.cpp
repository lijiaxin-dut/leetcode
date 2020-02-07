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


//isalnum ()  �ж�һ��char�ǲ������ֻ�����ĸ

class Solution_125 {
public:
	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		int left = 0;
		int right = s.size() - 1;
		while (left<right) {
			while (left<right && !isalnum(s[left]))
				left++;
			while (left<right && !isalnum(s[right]))
				right--;
			if (toupper(s[left]) != toupper(s[right]))
				return false;
			else {
				left++;
				right--;
			}
		}
		return true;
	}
};

