//We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
//
//Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
//Example:
//Input: 28
//	Output : True
//	Explanation : 28 = 1 + 2 + 4 + 7 + 14

//从2开始判断，判断到根号n
//当可以整除2时，也加上n/2
//知道根号n

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num <= 1)
			return false;
		int sum = 0;
		for (int i = 2; i*i <= num; i++) {
			if (num%i == 0) {
				sum += i;
				sum += num / i;
			}
		}
		sum++;
		return sum == num;
	}
};