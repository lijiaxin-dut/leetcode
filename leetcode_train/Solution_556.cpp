#include<string>
#include<algorithm>


using namespace std;

//Given a positive 32 - bit integer n, you need to find the smallest 32 - bit integer which has exactly the same digits existing in the integer n and is greater in value than n.If no such positive 32 - bit integer exists, you need to return -1.
//
//Example 1:
//
//Input: 12
//	Output : 21
//
//
//	Example 2 :
//
//	Input : 21
//	Output : -1

//下一个全排列
//注意越界

class Solution {
public:
	int next_per(string s) {
		try {
			int n = s.size();
			for (int i = n - 1; i >= 1; i--) {
				if (s[i - 1]<s[i]) {
					for (int j = n - 1; j >= i; j--) {
						if (s[j]>s[i - 1]) {
							swap(s[j], s[i - 1]);
							break;
						}
					}
					reverse(s.begin() + i, s.end());
					return stoi(s);
				}
			}
			return -1;
		}
		catch (...) {
			return -1;
		}

	}
	int nextGreaterElement(int n) {
		string s = to_string(n);
		return next_per(s);
	}
};