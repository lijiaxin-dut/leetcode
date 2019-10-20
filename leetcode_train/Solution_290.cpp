#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;


//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.


//使用stringstream对单词分割
//进行两个映射
//pattern->str
//st->pattern

//每次在两个hash_map中同时查找



class Solution_290 {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string>hash_map_1;
		unordered_map<string, char>hash_map_2;
		stringstream ss(str);
		vector<string>str_s;
		while (getline(ss, str, ' ')) {
			str_s.push_back(str);
		}
		if (str_s.size() != pattern.size())
			return false;
		for (int i = 0; i<pattern.size(); i++) {
			if (hash_map_1.find(pattern[i]) == hash_map_1.end() && hash_map_2.find(str_s[i]) == hash_map_2.end()) {
				hash_map_1[pattern[i]] = str_s[i];
				hash_map_2[str_s[i]] = pattern[i];
			}
			else if (hash_map_1.find(pattern[i]) == hash_map_1.end() || hash_map_2.find(str_s[i]) == hash_map_2.end())
				return false;
			else
			{
				if (str_s[i] != hash_map_1[pattern[i]] || hash_map_2[str_s[i]] != pattern[i])
					return false;
			}
		}
		return true;
	}
};