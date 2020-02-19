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

//2.ţ�ٷ�
//x^2-a=0
//x_k+1=x_k-(x^2-a)/(2x)
//x_k+1=(x_k+a/x_k)/2;
//ʹ�������漴��


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
		int i = 1;
		int j = x;
		int ans = 0;
		while (i <= j) {
			int mid = i + (j - i) / 2;
			// upper bound����ʽ����Ϊ����Ҫ�ҵ�ansҪ����ӽ���x��������������upper bound
			if (mid <= x / mid) {
				i = mid + 1;
				ans = mid;
			}
			else
				j = mid - 1;
		}

		return ans;
	}
};