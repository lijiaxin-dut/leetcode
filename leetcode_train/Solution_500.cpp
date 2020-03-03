#include<unordered_set>
#include<vector>
#include<utility>
#include<ctype.h>
using namespace std;

//Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
//
//
//
//
//
//
//Example:
//
//Input: ["Hello", "Alaska", "Dad", "Peace"]
//	Output : ["Alaska", "Dad"]

//一行一行比较即可

class Solution {
	bool help(const string &s, unordered_set<char>&dict) {
		for (auto &one_char : s) {
			if (dict.find(tolower(one_char)) == dict.end())
				return false;
		}
		return true;

	}
public:
	vector<string> findWords(vector<string>& words) {
		unordered_set<char>first{ 'q','w','e','r','t','y','u','i','o','p' };
		unordered_set<char>second{ 'a','s','d','f','g','h','j','k','l' };
		unordered_set<char>thrid{ 'z','x','c','v','b','n','m' };
		vector<string>rs;
		for (int i = 0; i<words.size(); i++) {
			if (help(words[i], first) == true) {
				rs.push_back(words[i]);
			}
			else if (help(words[i], second) == true) {
				rs.push_back(words[i]);
			}
			else if (help(words[i], thrid) == true) {
				rs.push_back(words[i]);
			}
		}
		return rs;
	}
};