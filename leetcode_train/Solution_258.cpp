
//Given a non - negative integer num, repeatedly add all its digits until the result has only one digit.
//
//Example:
//
//Input: 38
//	Output : 2
//	Explanation : The process is like : 3 + 8 = 11, 1 + 1 = 2.
//	Since 2 has only one digit, return it.
//

//�ҹ��ɣ����Եó����ɣ�ÿ9��һѭ�������д���9�������������Ƕ�9ȡ��
//1    1
//2    2
//3    3
//4    4
//5    5
//6    6
//7    7
//8    8
//9    9
//10    1
//11    2
//12    3
//13    4
//14    5
//15    6
//16    7
//17    8
//18    9
//19    1
//20    2




class Solution_258 {
public:
	int addDigits(int num) {
		if (num == 0)
			return num;
		int rs = num % 9;
		if (rs == 0)
			return 9;
		return rs;
	}
};