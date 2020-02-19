#include<map>
#include<random>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_set>
#include<iostream>
using namespace std;

//根据回车 \n分解
//根据\t确定当前层数level ， 用level+1表示当前层
//每一层长度+1表示反斜线 \

// 用line.find_last_of('\t') + 1;

class Solution {
public:
	int lengthLongestPath(string input) {
		int res = 0;
		istringstream ss(input);
		unordered_map<int, int> m{ { 0, 0 } };
		string line = "";
		while (getline(ss, line)) {
			int level = line.find_last_of('\t') + 1;
			int len = line.substr(level).size();
			if (line.find('.') != string::npos) {
				res = max(res, m[level] + len);
			}
			else {
				m[level + 1] = m[level] + len + 1;//+1表是  /
			}
		}
		return res;
	}
};

