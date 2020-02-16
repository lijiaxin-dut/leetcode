#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

//Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it.Find and return the shortest palindrome you can find by performing this transformation.
//
//Example 1:
//
//Input: "aacecaaa"
//	Output : "aaacecaaa"

//1.暴力法
//找到包含开始位置的最长回文串
//得到不是回文串的部分，返回，加到s的前面

//2.首先得到s的逆序rs
//找到s从0开始，到一个位置，与rs从反方向开始，相等的位置
//s[0,...i,....j]
//rs[0,....i.....j]
//如果s[0,...,i]与rs[i,...,j]相等，说明这一段区间是回文串
//加上rs的前半部分即可

class Solution_214 {

	bool is_para(const string &s) {
		if (s.size() <= 1)
			return true;
		int left = 0;
		int right = s.size() - 1;
		while (left<right) {
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
public:

	string shortestPalindrome_help(string s) {
		const string r(s.rbegin(), s.rend());
		const int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (s.compare(0, n - i, r, i, n - i) == 0)
				return r.substr(0, i) + s;
		}
		return "";
	}
	string shortestPalindrome(string s) {

		if (s.size() <= 1)
			return s;
		string para;
		for (int length = 1; length <= s.size(); length++) {
			string t = s.substr(0, length);
			if (is_para(t))
				para = t;
		}
		if (para.size() == s.size())
			return s;
		string left = s.substr(para.size());
		reverse(left.begin(), left.end());
		return left + s;


	}
};