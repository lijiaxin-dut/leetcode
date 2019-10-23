//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//Given two integers x and y, calculate the Hamming distance.

//�������������Ȼ���������ֶ���������1�ĸ���


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