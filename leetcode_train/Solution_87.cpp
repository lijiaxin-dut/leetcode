#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//Given a string s1, we may represent it as a binary tree by partitioning it to two non - empty substrings recursively.
//
//Below is one possible representation of s1 = "great":
//
//great
/// \
//gr    eat
/// \ / \
//g   r  e   at
/// \
//a   t
//To scramble the string, we may choose any non - leaf node and swap its two children.
//
//For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//
//rgeat
/// \
//rg    eat
/// \ / \
//r   g  e   at
/// \
//a   t
//We say that "rgeat" is a scrambled string of "great".


//µ›πÈ«ÛΩ‚
//The base case that s1 can scramble into s2 if s1 == s2.If the frequencies of each characters appearing in s1 and s2 differ, then s1 can not scramble into s2.
//
//If there exist 0 <= i <= s1.length() where
//
//s1[0, i] can scramble into s2[0, i] and s1[i, length] can scramble into s2[i, length]; or
//s1[0, i] can scramble into s2[length - i, length] and s1[i, length] can scramble into s2[0, length - i]
//then, s1 can scramble into s2.

class Solution_87 {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		vector<int>cs1(26, 0);
		vector<int>cs2(26, 0);
		for (int i = 0; i<s1.size(); i++) {
			cs1[s1[i] - 'a']++;
			cs2[s2[i] - 'a']++;
		}
		if (cs1 != cs2)
			return false;
		for (int i = 1; i<s1.size(); i++) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))
				return true;
		}
		return false;
	}
};