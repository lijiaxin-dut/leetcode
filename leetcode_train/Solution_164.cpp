#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//A peak element is an element that is greater than its neighbors.
//
//Given an input array nums, where nums[i] ≠ nums[i + 1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that nums[-1] = nums[n] = -∞.


//找到第一个降序的位置即可，因为num[-1]=-∞
//若找不到，返回最后一个索引

class Solution_164 {
public:
	int findPeakElement(vector<int>& nums) {

		for (int i = 0; i<nums.size() - 1; i++) {
			if (nums[i]>nums[i + 1])
				return i;
		}
		return nums.size() - 1;

	}
};

//int main() {
//	Solution_164 s;
//	vector<int>nums{ 2,3,-2,4 };
//	s.findPeakElement(nums);
//}