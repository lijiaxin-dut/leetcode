#include<vector>
#include<sstream>
#include<string>

using namespace std;

//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//Example 1:
//
//Input: "A"
//	Output : 1
//	Example 2 :
//
//	Input : "AB"
//	Output : 28
//	Example 3 :
//
//	Input : "ZY"
//	Output : 701


//从字符串尾部开始
//向前依次遍历
//乘上当前的位置*26


class Solution {
public:
	int titleToNumber(string s) {

		long rs = 0;
		long base = 1;
		for (int i = int(s.size() - 1); i >= 0; i--) {
			rs += (s[i] - 'A' + 1)*base;
			base = base * 26;
		}
		return rs;
	}
};