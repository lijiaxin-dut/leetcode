
//Given an integer, write a function to determine if it is a power of two.


//2�ı������ֻ��һ��1
//ȥ�����һ��1���ж��Ƿ�Ϊ0

class Solution_231 {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		n = n&(n - 1);
		return n == 0;
	}
	bool isPowerOfTwo_1(int n) {
		if (n <= 0)
			return false;
		while (n>0) {
			if (n == 1)
				return true;
			else if (n % 2 == 0)
				n = n / 2;
			else
				return false;
		}
		return true;

	}
};