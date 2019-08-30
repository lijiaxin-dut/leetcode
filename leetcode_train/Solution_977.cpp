#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given an array of integers A sorted in non-decreasing order, 
//return an array of the squares of each number, also in sorted non-decreasing order.


//因为原数组有序，将数组中的正负分开考虑

class Solution_977 {
public:
	vector<int> sortedSquares(vector<int>& A) {
		//找到第一个为整数的索引
		int first_positive_index = 0;
		while (first_positive_index<A.size() && A[first_positive_index]<0)
			first_positive_index++;
		//找到最后一个为负数的索引
		int last_negative_index = first_positive_index - 1;
		vector<int>rs(A.size());
		int t = 0;
		//整数索引自增，负数索引自减，不断合并两个有序的数组
		//使用two pointer技术合并两个有序数组
		while (first_positive_index<A.size() && last_negative_index >= 0) {
			if (A[first_positive_index] * A[first_positive_index] <= A[last_negative_index] * A[last_negative_index]) {
				rs[t++] = A[first_positive_index] * A[first_positive_index];
				first_positive_index++;
			}
			else {
				rs[t++] = A[last_negative_index] * A[last_negative_index];
				last_negative_index--;
			}

		}
		//处理还未判断的单个数组
		while (first_positive_index<A.size()) {
			rs[t++] = A[first_positive_index] * A[first_positive_index];
			first_positive_index++;
		}
		while (last_negative_index >= 0) {
			rs[t++] = A[last_negative_index] * A[last_negative_index];
			last_negative_index--;
		}
		return rs;
	}
};

//int main() {
//	Solution_977 s;
//	vector<int>A{ -4 };
//	s.sortedSquares(A);
//}