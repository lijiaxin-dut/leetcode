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
	
public:
	int countPrimes(int n) {
		int res = 0;
		vector<bool> prime(n, true);
		for (int i = 2; i < n; ++i) {
			if (!prime[i])
				continue;
			++res;
			//筛掉当前素数的倍数
			for (int j = 2; i * j < n; ++j) {
				prime[i * j] = false;
			}
		}
		return res;
	}


};