#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

//Write a program to find the n - th ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
//Example:
//
//Input: n = 10
//	Output : 12
//	Explanation : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

//按顺序不断生成ugly number
//记录当前ugly number由哪个系数*之前的数组得到的

//1 2 3 4 5 6 8 9 10 12 15.
//it must be x * 2 or y * 3 or z * 5, where x, y, z is an existing number.
//In this case x = 8, y = 6, z = 4. Then you compare x * 2, y * 3, z * 5 so you know 
//next number will be x * 2 = 8 * 2 = 16.

//下一个x的位置就是9所在的位置


class Solution_264 {
public:
	int nthUglyNumber(int n) {
		vector <int> results{ 1 };
		int i = 0, j = 0, k = 0;
		while (results.size() < n)
		{
			results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
			if (results.back() == results[i] * 2)
				++i;
			if (results.back() == results[j] * 3)
				++j;
			if (results.back() == results[k] * 5)
				++k;
		}
		return results.back();
	}
};

//int main() {
//	Solution_264 s;
//	s.nthUglyNumber(10);
//}