#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
//
//Example 1:
//
//Input: 2
//	Output : [0, 1, 3, 2]
//	Explanation :
//	00 - 0
//	01 - 1
//	11 - 3
//	10 - 2
//
//	For a given n, a gray code sequence may not be uniquely defined.
//	For example, [0, 2, 3, 1] is also a valid gray code sequence.
//
//	00 - 0
//	10 - 2
//	11 - 3
//	01 - 1
//

//使用set记录已经找到过的数字
//每次改变一个数字

//需要不断的将二进制转为十进制


class Solution_89 {
public:
	vector<int> grayCode(int n) {
		vector<int>rs;
		vector<int>each_bit(n, 0);
		set<int>already_number;
		already_number.insert(binary_to_int(each_bit));
		rs.push_back(binary_to_int(each_bit));
		int total_number = pow(2, n);
		while (already_number.size()<total_number) {
			for (int i = 0; i<n; i++) {
				int old_bit = each_bit[i];
				if (old_bit == 0)
					each_bit[i] = 1;
				else
					each_bit[i] = 0;
				int cur_val = binary_to_int(each_bit);
				if (already_number.find(cur_val) != already_number.end()) {
					each_bit[i] = old_bit;
					continue;
				}
				else {
					already_number.insert(cur_val);
					rs.push_back(cur_val);
				}
			}
		}
		return rs;

	}
	int binary_to_int(vector<int>&each_bit) {
		int rs = 0;
		int cur_index = 0;
		for (int i = each_bit.size() - 1; i >= 0; i--) {
			rs += pow(2, cur_index++)*each_bit[i];
		}
		return rs;
	}
};
