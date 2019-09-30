#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>
#include<queue>

using namespace std;


//Given a non - empty array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
//
//Example 1 :
//
//	Input : [2, 2, 1]
//	Output : 1
//	Example 2 :
//
//	Input : [4, 1, 2, 1, 2]
//	Output : 4


//找到只出现一次的数字

//将所有的数进行亦或
//两个相等的数亦或为0

class Solution_136 {
public:
	int singleNumber(vector<int>& nums) {
		int rs = 0;
		for (int i = 0; i<nums.size(); i++) {
			rs ^= nums[i];
		}
		return rs;
	}
};