#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//	Output :
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]


class Solution_49 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>>hash_map;

		for (const auto &one_str : strs) {
			string temp = one_str;
			sort(temp.begin(), temp.end());
			hash_map[temp].push_back(one_str);
		}
		vector<vector<string>>rs;
		for (const auto &one_group : hash_map)
			rs.push_back(one_group.second);
		return rs;



	}
};