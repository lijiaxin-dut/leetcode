//Given a range[m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//Example 1:
//
//Input: [5, 7]
//	Output : 4
//	Example 2 :
//
//	Input : [0, 1]
//	Output : 0

//
//��m��n��ǰ׺�ж�����ͬ��λ��
//���ϵĽ�m\n�����ƶ�
//ֱ����ȣ�Ȼ��ָ�ԭ����λ������

//�Ǹ����Ӳ�̫���ԣ�����������һ����Χ[26, 30]�����ǵĶ��������£�
//
//11010����11011����11100����11101����11110

//�۲�����ж�����ͬ��λ������
class Solution_201 {
public:
	int rangeBitwiseAnd(int m, int n) {
		int c = 0;
		while (m != n) {
			m = m >> 1;
			n = n >> 1;
			c++;
		}
		return m << c;
	}
};