#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
//
//Return the length of the longest(contiguous) subarray that contains only 1s.

//使用两个指针
//left  表示左端区间
//right 表示右端区间
//判断区间内1的个数


class Solution_1004 {
public:
	int longestOnes(vector<int>& A, int K) {
		int number_of_one = 0;
		int left = 0;
		int right = 0;
		int rs = 0;
		while (right<A.size()) {
			//当前位置是1
			if (A[right] == 1) {
				number_of_one++;
				rs = max(rs, right - left + 1);
				right++;
			}
			else {
				//当前位置是0，但是K的值满足0的个数，可以进行修改
				if (number_of_one + K >= (right - left + 1)) {
					rs = max(rs, right - left + 1);
					right++;
				}
				else {
					//K的值过小，无法修改，滑动窗口向右移动，判断左端窗口是不是1
					if (A[left] == 1)
						number_of_one--;
					left++;
				}
			}
		}
		return rs;
	}
};

//int main() {
//	Solution_1004 s;
//	vector<int>A{ 1,1,1,0,0,0,1,1,1,1,0 };
//	int K = 2;
//	s.longestOnes(A, K);
//}