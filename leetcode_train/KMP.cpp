#include<iostream>
#include<string>
#include<vector>

using namespace std;


class KMP {
	vector<vector<int>>dfa;
	void generate_dfa(const string &pattern) {
		dfa.resize(256, vector<int>(pattern.size(), 0));
		dfa[pattern[0]][0] = 1;
		//X为状态重启的位置
		for (int X = 0, j = 1; j < pattern.size(); j++) {
			for (int c = 0; c < 256; c++) {
				dfa[c][j] = dfa[c][X];
			}
			dfa[pattern[j]][j] = j + 1;
			X = dfa[pattern[j]][X];
		}
	}
	int search(const string &txt,const string &pattern) {
		int i = 0, j = 0;
		for (; i < txt.size()&&j<pattern.size(); i++) 
			j = dfa[txt[i]][j];
		if (j == pattern.size())
			return i - pattern.size();
		return -1;


	}

};

class Solution {
public:
	int strStr(string s, string t) {

		int s_size = s.size();
		int t_size = t.size();
		vector<int>next(t_size + 1);
		get_next(next, t);
		int i = 0;
		int j = 0;
		while (i < s_size&&j < t_size) {
			if (j == -1 || s[i] == t[j]) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (j == t_size)
			return i - j;
		return -1;
	}
	void get_next(vector<int>&next, const string &p) {
		next[0] = -1;
		int i = 1;
		int j = 0;
		int n = p.size();
		while (i < n) {
			if (j == -1 || p[i] == p[j]) {
				j++;
				i++;
				next[i] = j;
			}
			else {
				j = next[j];
			}
		}
	}

};