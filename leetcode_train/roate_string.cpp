#include<string>

using namespace std;

//字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

//拼接s1+s1
//判断s2是否在里面

class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		if (s1 == s2)
			return true;
		string new_string = s2 + s2;
		if (strstr(new_string.c_str(), s1.c_str()))
			return true;
		else
			return false;
	}
};