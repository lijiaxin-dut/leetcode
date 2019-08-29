#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description
//Write a function that takes a string as input and reverse only the vowels of a string.

class Solution_345 {
	bool is_vowels(char c) {
		char Upper_c = toupper(c);
		if (Upper_c == 'A' || Upper_c == 'E' || Upper_c == 'I' || Upper_c == 'O' || Upper_c == 'U')
			return true;
		return false;
	}

public:
	string reverseVowels(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left<right) {
			while (left<right&&is_vowels(s[left]) == false)
				left++;
			while (left<right&&is_vowels(s[right]) == false)
				right--;
			if (left >= right)
				break;
			swap(s[left++], s[right--]);
		}
		return s;
	}
};