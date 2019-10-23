//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//Given two integers x and y, calculate the Hamming distance.

//两个数进行异或，然后计算该数字二进制数中1的个数


class Solution_461 {
public:
	int hammingDistance(int x, int y) {
		int temp = x^y;
		int rs = 0;
		while (temp != 0) {
			rs++;
			temp = temp&(temp - 1);
		}
		return rs;

	}
};