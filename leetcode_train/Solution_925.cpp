#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, 
//the key might get long pressed, and the character will be typed 1 or more times.

//You examine the typed characters of the keyboard.Return True if it is possible that it 
//was your friends name, with some characters(possibly none) being long pressed.


//判断name是不是typed子序列


class Solution_925 {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0;
		for (const auto &one_char : typed) {
			if (i<name.size() && one_char == name[i])
				i++;
		}
		if (i == name.size())
			return true;
		return false;
	}
};

//int main() {
//	Solution_925 s;
//	s.isLongPressedName("laiden", "laiden");
//}