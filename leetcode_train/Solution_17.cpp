#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

//
//Given a string containing digits from 2 - 9 inclusive, return all possible
//letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given 
//below.Note that 1 does not map to any letters.


//Example:
//
//Input: "23"
//	Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


//使用队列保存每一轮的结果
//笛卡尔乘积


class Solution_17 {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return{};
		map<int, string>hash_map;
		hash_map[2] = "abc";
		hash_map[3] = "def";
		hash_map[4] = "ghi";
		hash_map[5] = "jkl";
		hash_map[6] = "mno";
		hash_map[7] = "pqrs";
		hash_map[8] = "tuv";
		hash_map[9] = "wxyz";
		vector<string>rs;
		queue<string>temp_s;
		temp_s.push("");

		for (int i = 0; i<digits.size(); i++) {
			int current_size = temp_s.size();
			while (current_size>0) {
				current_size--;
				const auto  pre = temp_s.front();
				temp_s.pop();
				for (auto &one_char : hash_map[digits[i] - '0']) {
					temp_s.push(pre + one_char);
				}
			}
		}
		while (!temp_s.empty()) {
			rs.push_back(temp_s.front());
			temp_s.pop();
		}
		return rs;

	}
};

