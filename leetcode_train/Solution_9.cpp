#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

class Solution_9 {
public:
	bool isPalindrome(int x) {
		if (x<0)
			return false;
		long rs = 0;
		int back_x = x;
		while (x>0) {
			int number = x % 10;
			x = x / 10;
			rs = rs * 10 + number;
		}
		if (rs>INT_MAX || back_x != int(rs))
			return false;
		return true;

	}
};