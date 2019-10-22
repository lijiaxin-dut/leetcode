#include<algorithm>

using namespace std;


//Given an integer, write a function to determine if it is a power of three.

//采用换底公式
//n=3^i
//i=log_3^n
//i=log(n)/log(3)
//判断log(n)/log(3)是不是整数即可

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