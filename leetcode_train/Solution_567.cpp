#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

//Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
//In other words, one of the first string's permutations is the substring of the second string.


//使用两个map映射
//首先将s1映射到map，将s2的前|s1|个字符也进行映射
//不断将s2的窗口向右移动
//移动的过程中修改s2的map
//index i表示窗口的右端
//index left表示窗口的左端
//只有26个小写字母，使用vector<int>26作为映射


class Solution_567 {
public:
	bool checkInclusion_map_1(string s1, string s2) {
		//如果s2的字串包含s1的全排列，则字串的字符与s1相等，并且出现的频率也相等
		if (s1.size()>s2.size())
			return false;
		map<char, int>hash_map_s1;
		map<char, int>hash_map_s2;
		for (int i = 0; i<s1.size(); i++) {
			hash_map_s1[s1[i]]++;
			hash_map_s2[s2[i]]++;
		}
		if (hash_map_s2 == hash_map_s1)
			return true;
		int left = 0;
		for (int i = s1.size(); i<s2.size(); i++) {
			hash_map_s2[s2[left]]--;
			if (hash_map_s2[s2[left]] == 0)
				hash_map_s2.erase(s2[left]);
			left++;
			hash_map_s2[s2[i]]++;
			if (hash_map_s2 == hash_map_s1)
				return true;
		}
		return false;

	}
	bool checkInclusion(string s1, string s2) {
		//如果s2的字串包含s1的全排列，则字串的字符与s1相等，并且出现的频率也相等
		if (s1.size()>s2.size())
			return false;
		vector<int>hash_map_s1(26);
		vector<int>hash_map_s2(26);
		for (int i = 0; i<s1.size(); i++) {
			hash_map_s1[s1[i] - 'a']++;
			hash_map_s2[s2[i] - 'a']++;
		}
		if (hash_map_s2 == hash_map_s1)
			return true;
		int left = 0;
		for (int i = s1.size(); i<s2.size(); i++) {
			hash_map_s2[s2[left++] - 'a']--;
			hash_map_s2[s2[i] - 'a']++;
			if (hash_map_s2 == hash_map_s1)
				return true;
		}
		return false;
	}
};

//int main() {
//	Solution_567 s;
//	string s1 = "adc";
//	string s2 = "dcda";
//	s.checkInclusion(s1, s2);
//}