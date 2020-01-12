#include<iostream>
using namespace std;

//Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero.

//���ϵļ�ȥ������ʹ�ó�������ɸ���
//���ƣ����ֱ��2��
//dividend = 15 divisor = 3
//15-3>0
//15-6>0
//15-12>0
//12-24<0  ����ȥ12
//���Ƶ�����   ans+=(1<<2)

class Solution_29 {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN&&divisor == -1)
			return INT_MAX;
		long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
		int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
		while (dvd >= dvs) {
			long temp = dvs;
			int m = 1;
			while ((temp << 1) <= dvd) {
				temp = temp << 1;
				m = m << 1;
			}
			dvd = dvd - temp;
			ans += m;
		}
		return sign*ans;

	}
};

