#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

//给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//
//注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
//
//
//
//示例 1：
//
//输入：
//s = "barfoothefoobarman",
//words = ["foo", "bar"]
//输出：[0, 9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
//输出的顺序不重要, [9, 0] 也是有效答案。
//示例 2：
//
//输入：
//s = "wordgoodgoodgoodbestword",
//words = ["word", "good", "best", "word"]
//输出：[]



class Solution{
public:

	//滑动窗口，控制窗口的长度为s
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int>rs;
		if (s.empty() || words.empty())
			return rs;
		unordered_map<string, int>dict;
		int word_size = words.size();
		int word_length = words[0].size();
		for (auto &one_word : words) {
			dict[one_word]++;
		}
		int window_length = word_size*word_length;
		for (int i = 0; i<word_length; i++) {
			int left = i;
			int right = i;
			int count = 0;
			unordered_map<string, int>tmp_map;
			while (right + word_length <= s.size()) {
				string w = s.substr(right, word_length);
				tmp_map[w]++;
				count++;
				//在这里控制滑动窗口的最大长度为s
				while ((dict.find(w) == dict.end() || tmp_map[w]>dict[w]) && left <= right) {
					string sub = s.substr(left, word_length);
					tmp_map[sub]--;
					if (tmp_map[sub] == 0) {
						tmp_map.erase(sub);
					}
					left += word_length;
					count--;
				}
				if (count == word_size) {
					rs.push_back(left);
				}
				right += word_length;
			}

		}
		return rs;
	}


	vector<int> findSubstring_worse(string s, vector<string>& words) {
		vector<int>rs;
		if (s.empty() || words.empty())
			return rs;
		unordered_map<string, int>dict;
		int word_size = words.size();
		int word_length = words[0].size();
		for (auto &one_word : words) {
			dict[one_word]++;
		}
		int window_length = word_size*word_length;
		for (int i = 0; i < s.size(); i++) {
			int right = i + window_length;
			if (right > s.size())
				break;
			unordered_map<string, int>sub_window;
			for (int j = i; j < right; j += word_length) {
				string sub = s.substr(j, word_length);
				if (dict.find(sub) == dict.end())
					break;
				sub_window[sub]++;
			}
			if (sub_window == dict) {
				rs.push_back(i);
			}
		}
		return rs;

	}
};
