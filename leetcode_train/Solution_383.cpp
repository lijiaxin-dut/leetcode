#include<string>
#include<unordered_map>

using namespace std;



//Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines; otherwise, it will return false.
//
//Each letter in the magazine string can only be used once in your ransom note.
//
//Note:
//You may assume that both strings contain only lowercase letters.
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true


//判断一个字符串是否是另一个的子序列


class Solution_383 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int>hash_map;
		for (auto &one_char : magazine)
			hash_map[one_char]++;
		for (auto &one_char : ransomNote) {
			if (hash_map.find(one_char) == hash_map.end())
				return false;
			if (hash_map[one_char] <= 0)
				return false;
			hash_map[one_char]--;
		}
		return true;
	}
};