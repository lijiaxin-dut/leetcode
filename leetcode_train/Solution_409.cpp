#include<string>
#include<unordered_map>

using namespace std;

//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//
//Note:
//	Assume the length of given string will not exceed 1, 010.
//
//		Example :
//
//		Input :
//		"abccccdd"
//
//		Output :
//		7
//
//		Explanation :
//		One longest palindrome that can be built is "dccaccd", whose length is 7.


//统计字符的个数，所有偶数+最多一个奇数



class Solution_409 {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int>hash_map;
		for (auto &one_char : s)
			hash_map[one_char]++;
		int rs = 0;
		bool is_even = false;
		for (auto &one : hash_map) {
			if (one.second % 2 == 0)
				rs += one.second;
			else {
				rs += one.second - 1;
				is_even = true;
			}
		}
		return is_even == true ? rs + 1 : rs;

	}
};