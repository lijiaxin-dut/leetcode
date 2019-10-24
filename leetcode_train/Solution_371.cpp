

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

//将进位与相加单独考虑
//a^b   得到不需要进位的结果
//只考虑进位的加 0+0=0, 0+1=0, 1+0=0, 1+1=1，
//而这其实这就是'与'的运算，而第三步在将两者相加时，我们再递归调用这个算法


//carry = a & b & 0x7ffffff  强制把最高位的1清零

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