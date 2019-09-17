#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array of 2n integers, your task is to group these integers into n pairs of integer, say(a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
//
//Example 1:
//Input: [1, 4, 3, 2]
//
//	Output : 4
//	Explanation : n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

//要最大化每对中的较小值之和，那么肯定是每对中两个数字大小越接近越好，因为如果差距过大，
//而我们只取较小的数字，那么大数字就浪费掉了

//首先对数组排序，按顺序的每两个就是一对，我们取出每对中的第一个数即为较小值累加起来即可


class Solution_561{
public:
	int arrayPairSum(vector<int>& nums) {
		int two_n = nums.size();
		int n = nums.size() / 2;
		sort(nums.begin(), nums.end());
		int rs = 0;
		for (int i = 0; i<two_n; i = i + 2) {
			rs += nums[i];
		}
		return rs;
	}
};