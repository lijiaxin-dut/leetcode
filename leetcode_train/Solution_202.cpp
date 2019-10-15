#include<unordered_set>
#include<vector>

using namespace std;

//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example :
//
//	Input : 19
//	Output : true
//	Explanation :
//	12 + 92 = 82
//	82 + 22 = 68
//	62 + 82 = 100
//	12 + 02 + 02 = 1


//使用set记录这个点以前是否出现过

class Solution {
	int trans(int n) {
		int rs = 0;
		while (n>0) {
			int temp = n % 10;
			rs += temp*temp;
			n = n / 10;
		}
		return rs;

	}
public:
	bool isHappy(int n) {
		unordered_set<int>old_numbers;
		while (true) {
			old_numbers.insert(n);
			n = trans(n);
			if (n == 1)
				return true;
			if (old_numbers.find(n) != old_numbers.end())
				return false;

		}

	}
};