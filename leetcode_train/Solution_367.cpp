//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
//Note: Do not use any built - in library function such as sqrt.
//
//	Example 1 :
//
//	Input : 16
//	Output : true
//	Example 2 :
//
//	Input : 14
//	Output : false

//从left=1,right=num开始二分


class Solution_367 {
public:
	bool isPerfectSquare(int num) {
		for (int i = 1; i <= num / i; i++) {
			if (i == num / i&&num%i == 0)
				return true;
		}
		return false;

	}
	bool isPerfectSquare_1(int num) {
		int left = 1;
		int right = num;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == num / mid&&num%mid == 0)
				return true;
			else if (mid>num / mid)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return false;
	}
};