

//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
//Example 1:
//
//Input: a = 1, b = 2
//	Output : 3
//	Example 2 :
//
//	Input : a = -2, b = 3
//	Output : 1

//����λ����ӵ�������
//a^b   �õ�����Ҫ��λ�Ľ��
//ֻ���ǽ�λ�ļ� 0+0=0, 0+1=0, 1+0=0, 1+1=1��
//������ʵ�����'��'�����㣬���������ڽ��������ʱ�������ٵݹ��������㷨


//carry = a & b & 0x7ffffff  ǿ�ư����λ��1����

class Solution_371 {
public:
	int getSum(int a, int b) {
		if (b == 0)
			return a;
		int carry = a & b & 0x7fffffff;
		a = a^b;
		carry = carry << 1;
		return getSum(a, carry);
	}
};

//int main() {
//	Solution_371 s;
//	s.getSum(-1, -2);
//}