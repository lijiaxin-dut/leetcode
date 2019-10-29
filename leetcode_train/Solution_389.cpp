#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Given two strings s and t which consist of only lowercase letters.
//
//String t is generated by random shuffling string s and then add one more letter at a random position.
//
//Find the letter that was added in t.
//
//Example:
//
//Input:
//s = "abcd"
//t = "abcde"
//
//Output :
//	e
//
//	Explanation :
//'e' is the letter that was added.


//1.找到出现次数不同的字母
//2.所有数字都出现了两次，只有一个出现了一次




class Solution_389 {
public:

	char findTheDifference_XOR(string s, string t) {
		char c = 0;
		for (int i = 0; i<s.size(); i++)
			c = c^s[i];
		for (int i = 0; i<t.size(); i++)
			c = c^t[i];
		return c;
	}

	char findTheDifference(string s, string t) {

		vector<int>hash_map_s(26, 0);
		for (int i = 0; i<s.size(); i++) {
			hash_map_s[s[i] - 'a']++;
		}
		vector<int>hash_map_t(26, 0);
		for (int i = 0; i<t.size(); i++) {
			hash_map_t[t[i] - 'a']++;
		}
		for (int i = 0; i<26; i++) {
			if (hash_map_t[i] != hash_map_s[i])
				return i + 'a';
		}
		return ' ';


	}
};