#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.

//二分法查找，
//若找不到，比较跟最后一个mid的关系，判断插在前面还是后面


class Solution_35 {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = -1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid]>target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (target>nums[mid])
			return mid + 1;
		return mid;
	}
};