#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Implement pow(x, n), which calculates x raised to the power n(xn).
//
//Example 1:
//
//Input: 2.00000, 10
//	Output : 1024.00000
//	Example 2 :
//
//	Input : 2.10000, 3
//	Output : 9.26100
//	Example 3 :
//
//	Input : 2.00000, -2
//	Output : 0.25000
//	Explanation : 2 - 2 = 1 / 22 = 1 / 4 = 0.25
//


//��n=0ʱ����1�����ϵĽ�n/2�����ж���
//n=ż��������half*half
//nΪ������n>0  ����half*half*x
//nΪ������n<0  ����half*half/x;

class Solution_50 {
public:
	double myPow(double x, int n) {
		return help(x, n);
	}
	double help(double x, int n) {
		if (n == 0)
			return 1;
		double half = help(x, n / 2);
		if (n % 2 == 0)
			return half*half;
		if (n>0)
			return half*half*x;
		else
			return half*half / x;
	}
};