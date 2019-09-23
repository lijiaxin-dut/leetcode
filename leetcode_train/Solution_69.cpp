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


//ע��Խ��
//mid=left+(right-left)/2;
//��Ҫʹ�ó˷��Ƚϣ�ʹ�ó����Ƚ�

class Solution_68 {
public:
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