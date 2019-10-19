//
//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
//Example 1:
//
//Input: 6
//	Output : true
//	Explanation : 6 = 2 × 3

//不断的除以 2，3，5
//判断最后能否为1


class Solution {
public:
	bool isUgly(int num) {
		if (num == 0)
			return false;
		while (num % 2 == 0)
			num = num / 2;
		while (num % 3 == 0)
			num = num / 3;
		while (num % 5 == 0)
			num = num / 5;
		return num == 1;

	}
};