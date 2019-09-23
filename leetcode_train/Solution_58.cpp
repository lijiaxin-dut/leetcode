#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	Example :
//
//	Input : "Hello World"
//	Output : 5
//

//字符串可能以' '结尾，跳过结尾的空格


class Solution_58 {
public:
	int lengthOfLastWord(string s) {
		if (s.empty())
			return 0;
		int last_alpha = s.size() - 1;
		while (last_alpha >= 0 && s[last_alpha] == ' ')
			last_alpha--;
		int rs = 0;
		for (int i = last_alpha; i >= 0; i--) {
			if (s[i] == ' ') {
				break;
			}
			else {
				rs++;
			}
		}
		return rs;
	}
};

