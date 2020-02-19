#include<vector>
#include<memory>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

//Given a list of unique words, find all pairs of distinct indices(i, j) in the given list, so that the concatenation of the two words, i.e.words[i] + words[j] is a palindrome.
//
//Example 1:
//
//Input: ["abcd", "dcba", "lls", "s", "sssll"]
//	Output : [[0, 1], [1, 0], [3, 2], [2, 4]]
//	Explanation : The palindromes are["dcbaabcd", "abcddcba", "slls", "llssssll"]
//

//使用map保存所有word的逆序
//给定一个word,划分为左右两个部分，left,right
//如果left为回文，并且在right在map中，则 re_right+left+right  构成回文
//如果right为回文，并且left在map中，则  left+right+re_left 构成回文


class Solution_336 {
	bool is_para(string&s) {
		if (s.empty())
			return true;
		int left = 0;
		int right = s.size() - 1;
		while (left<right) {
			if (s[left++] != s[right--])
				return false;
		}
		return true;
	}
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int>hash_map;
		set<vector<int>>rs;
		for (int i = 0; i<words.size(); i++) {
			string temp = words[i];
			reverse(temp.begin(), temp.end());
			hash_map[temp] = i;
		}
		for (int i = 0; i<words.size(); i++) {
			string cur_s = words[i];
			for (int j = 0; j <= cur_s.size(); j++) {
				string left;
				string right;
				if (j > 0)
					left = cur_s.substr(0, j);//left不为空
				if (j<cur_s.size())
					right = cur_s.substr(j);//right不为空
				if (is_para(left) == true && hash_map.find(right) != hash_map.end() && hash_map[right] != i)
					rs.insert({ hash_map[right],i });
				if (is_para(right) == true && hash_map.find(left) != hash_map.end() && hash_map[left] != i)
					rs.insert({ i,hash_map[left] });
			}
		}
		return{ rs.begin(),rs.end() };



	}
};