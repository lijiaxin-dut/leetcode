

//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.
//
//Example 1:
//
//Input: 16
//	Output : true


//首先判断是不是2的power,如果是，n-1能被3整除，则就是4的power

//4^n - 1 = (2^n + 1) * (2^n - 1)
//among any 3 consecutive numbers, there must be one that is a multiple of 3
//among(2 ^ n - 1), (2 ^ n), (2 ^ n + 1),
//one of them must be a multiple of 3, and (2 ^ n) cannot be the one, 
//therefore either(2 ^ n - 1) or (2 ^ n + 1) must be a multiple of 3, 
//and 4 ^ n - 1 must be a multiple of 3 as well.



class Solution_342 {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0)
			return false;
		while (num % 4 == 0)
			num = num / 4;
		return num == 1;
	}


	bool isPowerOfFour_1(int num) {
		if (num <= 0)
			return false;
		if (0 == (num&(num - 1))) {
			if ((num - 1) % 3 == 0)
				return true;
		}
		return false;
	}

};