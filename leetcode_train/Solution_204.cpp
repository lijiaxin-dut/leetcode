#include<iostream>
#include<vector>

using namespace std;

//判断一个数num是否为素数
//判断num能否被[2,sqrt(num)]整除
//都不能整除就是素数


//埃拉托斯特尼筛法
//从2-sqrt(n)
//先用2去筛，即把2留下，把2的倍数剔除掉；
//再用下一个素数，也就是3筛，把3留下，把3的倍数剔除掉；
//接下去用下一个素数5筛，把5留下，把5的倍数剔除掉；不断重复下去.


class Solution_204 {
	bool is_prime(int num) {
		if (num <= 1)
			return false;
		for (int i = 2; i*i <= num; i++) {
			if (num%i == 0)
				return false;
		}
		return true;

	}
public:
	int countPrimes_1(int n) {
		int count = 0;
		for (int i = 1; i<n; i++)
		{
			if (is_prime(i))
				count++;
		}
		return count;
	}

	int countPrimes_2(int n) {
		vector<bool>mark(n + 1, true);
		for (int i = 2; i*i<n; i++) {
			if (mark[i] == false)
				continue;
			//2*i已经被筛选过
			for (int j = i*i; j<n; j += i) {
				mark[j] = false;
			}
		}
		int rs = 0;
		for (int i = 2; i<n; i++)
			if (mark[i] == true)
				rs++;
		return rs;

	}


};