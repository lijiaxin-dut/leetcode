#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


//Given a string s that consists of only uppercase English letters, 
//you can perform at most k operations on that string.

//In one operation, you can choose any character of the string and change 
//it to any other uppercase English character.

//Find the length of the longest sub - string containing all repeating 
//letters you can get after performing the above operations.


//两个指针，使用map两个指针中间元素每个元素出现的次数
//出现次数+k<=frist-second，就得到一个合法的解


//滑动窗口不需要减少
//假设k=2;
//当前最长重复字母的次数为3，窗口长度为5
//则当前结果为5
//如果想得到为6的结构
//至少重复的字母要为4次，4+2变成6

//所以当滑动窗口向右平移时，不需要重新计  当前最长重复字母的个数

class Solution_424 {
public:
	int characterReplacement(string s, int k) {
		if (s.size() <= 1)
			return s.size();
		unordered_map<char, int> mark;
		int current_length = 0;
		int current_start = 0;
		int rs = 0;
		for (int i = 0; i<s.size(); i++) {
			mark[s[i]]++;
			//当前最长的连续的字符数
			current_length = max(current_length, mark[s[i]]);
			//当前两个指针的差值<=当前连续长度+k,就说明两个指针之间在k次操作可以变为相同的连续字母
			if (i - current_start + 1 <= current_length + k) {
				rs = max(rs, i - current_start + 1);
				continue;
			}
			else {
				//左指针向右边移动，减少左指针当前指向字母出现的次数
				mark[s[current_start]]--;
				current_start++;
			}
		}
		return rs;
	}
};

//int main() {
//	Solution_424 s;
//	s.characterReplacement("ABAB", 2);
//
//}