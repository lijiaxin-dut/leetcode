//Given an integer n, return the number of trailing zeroes in n!.
//
//Example 1:
//
//Input: 3
//	Output : 0
//	Explanation : 3!= 6, no trailing zero.
//	Example 2 :
//
//	Input : 5
//	Output : 1
//	Explanation : 5!= 120, one trailing zero.


//0��*10�õ�
//10=2*5
//������ͳ��5�ĸ�������
//5  10  15   20  25  ....
//100/5=20

//��Ҫ����25 125   ...�ɶ����˻��õ�������



class Solution {
public:
	int trailingZeroes(int n) {
		int rs = 0;
		for (long int i = 5; n / i>0; i = i * 5)
		{
			rs += n / i;
		}
		return rs;
	}
};