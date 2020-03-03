#include<string>

using namespace std;

//
//Given a non - empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
//

//1.考虑所有可能重复的字串
//调用s.compare比较字符串
//2.

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int n = s.size();
		for (int length = 1; length <= n / 2; length++) {
			if (n%length != 0)
				continue;
			bool find_diff = false;
			for (int j = length; j<n; j = j + length) {
				if (s.compare(0, length, s, j, length) != 0) {
					find_diff = true;
					break;
				}
			}
			if (find_diff == false) {
				return true;
			}
		}
		return false;
	}
};