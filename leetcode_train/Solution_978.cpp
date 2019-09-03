#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
//当 A 的子数组 A[i], A[i + 1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：
//
//若 i <= k < j，当 k 为奇数时， A[k] > A[k + 1]，且当 k 为偶数时，A[k] < A[k + 1]；
//	或 若 i <= k < j，当 k 为偶数时，A[k] > A[k + 1] ，且当 k 为奇数时， A[k] < A[k + 1]。
//	也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。
//
//	返回 A 的最大湍流子数组的长度。

//使用两个指针
//符号相等时，跳过
//可以有两个连续递增或者递减的情况
//给定一个i
//判断A[i-1]A[i]和A[i]A[i+1]的关系，若异号，right++
//若同号，则left->i是异号的，更新left到i
//或者达到了末尾的位置

class Solution_978 {
public:
	int maxTurbulenceSize_(vector<int>& A) {
		if (A.size() <= 1)
			return A.size();
		int left = 0;
		int right = 0;
		int rs = 1;
		while (right<A.size() - 1) {
			if (A[right]<A[right + 1]) {
				right++;
				int index = 0;
				while (right<A.size() - 1) {
					if (index % 2 == 0 && A[right]>A[right + 1]) {
						index++;
						right++;
					}
					else if (index % 2 == 1 && A[right]<A[right + 1]) {
						index++;
						right++;
					}
					else {
						rs = max(rs, right - left + 1);
						left = right;
						break;
					}
					rs = max(rs, right - left + 1);
				}
			}
			else if (A[right]>A[right + 1]) {
				right++;
				int index = 1;
				while (right<A.size() - 1) {
					if (index % 2 == 0 && A[right]>A[right + 1]) {
						index++;
						right++;
					}
					else if (index % 2 == 1 && A[right]<A[right + 1]) {
						index++;
						right++;
					}
					else {
						rs = max(rs, right - left + 1);
						left = right;
						break;
					}
					rs = max(rs, right - left + 1);
				}
			}
			else {
				right++;
				left = right;
			}
		}
		return rs;
	}

	int compare(int a, int b) {
		if (a<b)
			return 1;
		else if (a>b)
			return -1;
		else
			return 0;
	}
	int maxTurbulenceSize(vector<int>& A) {
		int left = 0;
		int rs = 1;
		for (int i = 1; i<A.size(); i++) {
			int c = compare(A[i - 1], A[i]);
			if (c == 0)
				left = i;
			else if (i == A.size() - 1 || (c*compare(A[i], A[i + 1]) != -1)) {
				rs = max(rs, i - left + 1);
				left = i;
			}

		}
		return rs;
	}
};

//int main() {
//	Solution_978 s;
//	vector<int>nums{ 9,4,2,10,7,8,8,1,9 };
//	s.maxTurbulenceSize(nums);
//}