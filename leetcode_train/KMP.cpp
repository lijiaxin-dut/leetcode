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


