#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, add spaces in s to construct a sentence where each word is a valid dictionary word.Return all such possible sentences.
//
//Note:
//
//The same word in the dictionary may be reused multiple times in the segmentation.
//You may assume the dictionary does not contain duplicate words.


//1. 与139相同，使用dp
//2. 自底向上递归，使用memory
//从当前位置出发，考虑所有的长度可能

class Solution_140 {
public:
	vector<string> wordBreak_recursive_memory(string s, vector<string>& wordDict) {
		unordered_map<string, vector<string>> m;
		return helper(s, wordDict, m);
	}
	vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
		if (m.count(s))
			return m[s];
		if (s.empty())
			return vector<string>{""};
		vector<string>res;
		for (string word : wordDict) {
			if (s.substr(0, word.size()) != word)
				continue;
			//前半部分已经找到组合，在后半部分开始递归
			vector<string> rem = helper(s.substr(word.size()), wordDict, m);
			for (string str : rem) {
				if (str.empty())
					res.push_back(word);
				else
					res.push_back(word + " " + str);
			}
		}
		return m[s] = res;


	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool>dp(n, false);
		vector<vector<string>>detail_dp(n);
		unordered_set<string>dicts(wordDict.begin(), wordDict.end());
		for (int i = 0; i<n; i++) {
			for (int j = 0; j <= i; j++) {
				string sub_str = s.substr(j, i - j + 1);
				if ((j == 0 && dicts.find(sub_str) != dicts.end()) || (j>0 && dp[j - 1] == true && dicts.find(sub_str) != dicts.end())) {
					dp[i] = true;
					if (j>0) {
						for (int k = 0; k<detail_dp[j - 1].size(); k++) {
							auto new_p = detail_dp[j - 1][k];
							new_p += sub_str + " ";
							detail_dp[i].push_back(new_p);
						}
					}
					else {
						detail_dp[i].push_back(sub_str + " ");
					}
				}
				else {
					if (dp[i] == true)
						continue;
					dp[i] = false;
				}
			}
		}
		for (auto &one_rs : detail_dp[n - 1])
			one_rs.pop_back();
		return detail_dp[n - 1];
	}
};