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
	int lengthOfLongestSubstring(string s) {
		int s_size = s.size();
		if (s_size <= 1)
			return s_size;
		int first_pointer = 0, second_pointer = 0, max_length_without_repeating = 0;
		vector<int>mark(128, 0);
		//滑动窗口，两个指针向右滑动，使用mark标记哪些字符重复出现过
		while (first_pointer<s_size) {
			//如果未出现过，更新结果
			if (mark[s[second_pointer]] == 0) {
				mark[s[second_pointer]] = 1;
				second_pointer++;
				max_length_without_repeating = max(max_length_without_repeating, second_pointer - first_pointer);
			}
			//出现过，左指针向右滑动
			else {
				mark[s[first_pointer]] = 0;
				first_pointer++;
			}
		}
		return max_length_without_repeating;
	}
};
//int main() {
//
//	Solution_3 s;
//	cout<<s.lengthOfLongestSubstring("aab");
//}