#include<vector>
#include<sstream>
#include<string>

using namespace std;

//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//...
//Example 1:
//
//Input: 1
//	Output : "A"
//	Example 2 :
//
//	Input : 28
//	Output : "AB"
//	Example 3 :
//
//	Input : 701
//	Output : "ZY"


//想象成26进制
//不断从取出尾部的数字
// 'A' + n % 26 表示当前的数字

//注意 n--


class Solution {
public:
	string convertToTitle(int n) {
		// vector<char>bridge{'0','A','B','C','D','E','F','G','H','I','J','K',\
		        //    'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		string rs;
		while (n>0) {
			n--;
			string temp;
			temp += 'A' + n % 26;
			rs = temp + rs;
			n = n / 26;
		}
		return rs;
	}
};