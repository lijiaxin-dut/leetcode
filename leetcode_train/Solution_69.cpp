#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is guaranteed to be a non - negative integer.
//
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
//Example 1:


//注意越界
//mid=left+(right-left)/2;
//不要使用乘法比较，使用除法比较

//2.牛顿法
//x^2-a=0
//x_k+1=x_k-(x^2-a)/(2x)
//x_k+1=(x_k+a/x_k)/2;
//使用正数存即可


class Solution_68 {
public:
	int mySqrt_NW(int x) {
		long t = x;
		while (t*t>x) {
			t = (t + x / t) / 2;
		}
		return t;

	}
	int mySqrt(int x) {
		int left = 1;
		int right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == x / mid)
				return mid;
			if (mid>(x / mid) && (mid - 1) <= (x / (mid - 1)))
				return mid - 1;
			if (mid>x / mid)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return 0;
	}
};