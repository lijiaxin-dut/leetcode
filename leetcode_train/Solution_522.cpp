#include<string>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
//
//Given a list of strings, you need to find the longest uncommon subsequence among them.The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
//
//A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements.Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
//
//The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence.If the longest uncommon subsequence doesn't exist, return -1.
//
//Example 1:
//Input: "aba", "cdc", "eae"
//	Output : 3



//对字符串按长度排序
//如果最长的字符串没有重复，最长的字符串就是答案
//如果最长的字符串重复出现，就一次判读字符串，是不是比他长的字串，如果不是，就是答案


class Solution {
	set<string>get_duplicates(vector<string>&strs) {
		set<string>rs;
		set<string>s;
		for (auto &one_str : strs) {
			if (s.find(one_str) != s.end())
				rs.insert(one_str);
			s.insert(one_str);
		}
		return rs;
	}
	bool is_subsequence(string &s1, string &s2) {
		int s2_index = 0;
		for (int i = 0; i<s1.size() && s2_index<s2.size(); i++) {
			if (s1[i] == s2[s2_index])
				s2_index++;

		}
		return s2_index == s2.size();

	}
public:
	int findLUSlength(vector<string>& strs) {
		if (strs.empty())
			return 0;
		sort(strs.begin(), strs.end(), [](string &a, string &b) {return a.size()>b.size(); });
		set<string>duplicates = get_duplicates(strs);
		if (duplicates.find(strs[0]) == duplicates.end())
			return strs[0].size();

		for (int i = 0; i<strs.size(); i++) {
			auto &one_s = strs[i];
			if (duplicates.find(one_s) == duplicates.end()) {
				bool is_sub = false;
				for (int j = 0; j<i; j++) {
					if (is_subsequence(strs[j], one_s) == true) {
						is_sub = true;
						break;
					}
				}
				if (is_sub == false)
					return one_s.size();
			}
		}
		return -1;


	}
};