#include<string>

using namespace std;

//Given an input string(s) and a pattern(p), implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string(not partial).
//
//Note:
//
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like . or *.


//如果p为空，判断s是否为空
//如果p的长度为1，判断s的长度是否为1，并且匹配
//如果p的长度>1,判断第二位是否是*，不是*，按顺序匹配
//如果第二位是*
//需要使用循环判断
//去点p的前两位，与s进行匹配，假设当前字符出现0次
//然后去掉s的首字符，因为*可以出现多次，不需要去掉
//循环结束后，判断isMatch(s, p.substr(2))

//返回调用递归函数匹配s和去掉前两个字符的p的结果
//（这么做的原因是处理星号无法匹配的内容，比如 s="ab", p="a*b"，
//直接进入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，
//那么此时跳出循环后，就到最后的 return 来比较 "b" 和 "b" 了，返回 true。
//再举个例子，比如 s="", p="a*"，由于s为空，不会进入任何的 if 和 while，
//只能到最后的 return 来比较了，返回 true，正确


class Solution_10 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		if (p.size() == 1)
			return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
		if (p[1] != '*') {
			if (s.empty())
				return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2)))
				return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));

	}
};