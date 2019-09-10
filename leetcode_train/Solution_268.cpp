#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//Example 1:
//
//Input: [3, 0, 1]
//	Output : 2
//	Example 2 :
//
//	Input : [9, 6, 4, 2, 3, 5, 7, 0, 1]
//	Output : 8

//给定了数字的范围，不断的将数字i放到对应的索引即可

//或者异或的方法，如果有缺失，使用的是n进行替补

//Index	0	1	2	3
//Value	0	1	3	4
//
//
//= 4∧(0∧0)∧(1∧1)∧(2∧3)∧(3∧4)
//= (4∧4)∧(0∧0)∧(1∧1)∧(3∧3)∧2
//= 0∧0∧0∧0∧2
//= 2



class Solution_268 {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i<n; i++) {
			while (nums[i]<n&&nums[i] != i) {
				swap(nums[i], nums[nums[i]]);
			}
		}
		for (int i = 0; i<n; i++) {
			if (nums[i] != i)
				return i;
		}
		return nums.size();

	}
};