#include<string>

using namespace std;

//Given a non - negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//Note:
//The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.
//Example 1 :
//
//	Input : num = "1432219", k = 3
//	Output : "1219"
//	Explanation : Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//	Example 2 :
//
//	Input : num = "10200", k = 1
//	Output : "200"
//	Explanation : Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

//单调栈，遇到的数字放入栈中
//从栈中弹出比当前元素大的值
//

class Solution_402 {
public:
	string removeKdigits(string num, int k) {
		int n = num.size();
		string s;
		for (int i = 0; i<n; i++) {
			if (s.empty() || num[i]>s.back()) {
				s.push_back(num[i]);
			}
			else {
				while (!s.empty() && num[i]<s.back() && k>0) {
					s.pop_back();
					k--;
				}
				s.push_back(num[i]);
			}
		}
		while (k>0 && !s.empty()) {
			s.pop_back();
			k--;
		}
		while (!s.empty() && s[0] == '0')
			s.erase(s.begin());
		return s.empty() ? "0" : s;

	}
};