#include<string>
#include<vector>

using namespace std;

//Given a string, find the first non - repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//s = "leetcode"
//return 0.
//
//s = "loveleetcode",
//return 2.

//使用两个数组记录每个字母第一次出现的位置和最后一次出现的位置
//从前向后遍历
//第一次出现的位置和最后一次出现的位置相同，就是答案


class Solution_387 {
public:
	int firstUniqChar(string s) {
		vector<int>first_appear(26, -1);
		vector<int>last_appear(26, -1);
		int n = s.size();
		for (int i = 0; i<n; i++) {
			if (first_appear[s[i] - 'a'] == -1)
				first_appear[s[i] - 'a'] = i;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (last_appear[s[i] - 'a'] == -1)
				last_appear[s[i] - 'a'] = i;
		}
		for (int i = 0; i<n; i++) {
			int index = s[i] - 'a';
			if (first_appear[index] == last_appear[index] && first_appear[index] != -1)
				return i;
		}
		return -1;
	}
};

