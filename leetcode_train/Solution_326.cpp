#include<algorithm>

using namespace std;


//Given an integer, write a function to determine if it is a power of three.

//���û��׹�ʽ
//n=3^i
//i=log_3^n
//i=log(n)/log(3)
//�ж�log(n)/log(3)�ǲ�����������

class Solution_326 {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0)
			return false;
		double t = log10(n) / log10(3);
		if (t - int(t) == 0)
			return true;
		else
			return false;
	}
};