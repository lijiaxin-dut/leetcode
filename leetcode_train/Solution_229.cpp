#include<vector>

using namespace std;

//Given an integer array of size n, find all elements that appear more than ⌊ n / 3 ⌋ times.
//
//Note: The algorithm should run in linear time and in O(1) space.
//
//	Example 1 :
//
//	Input : [3, 2, 3]
//	Output : [3]
//	Example 2 :
//
//	Input : [1, 1, 1, 3, 3, 2, 2, 2]
//	Output : [1, 2]

//最多有两个数字出现>n/3次
//投票法
//需要验证最后的两个数是否满足要求？？？？？？？？



class Solution_229 {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int>rs;
		int a = -1;
		int b = -1;
		int c_a = 0;
		int c_b = 0;
		for (auto &i : nums) {
			if (a == i)
				c_a++;
			else if (b == i)
				c_b++;
			else if (c_a == 0) {
				c_a = 1;
				a = i;
			}
			else if (c_b == 0) {
				c_b = 1;
				b = i;
			}
			else {
				c_a--;
				c_b--;
			}
		}
		c_a = 0;
		c_b = 0;

		for (auto &i : nums) {
			if (i == a)
				c_a++;
			if (i == b)
				c_b++;
		}
		if (c_a>nums.size() / 3)
			rs.push_back(a);
		if (c_b>nums.size() / 3)
			rs.push_back(b);
		return rs;

	}
};