#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array of integers nums sorted in ascending order, find the starting and ending 
//position of a given target value.

//Your algorithm's runtime complexity must be in the order of O(log n).

//If the target is not found in the array, return[-1, -1].

//二分法找到位置后，向两段搜索，找到第一个出现和最后一个出现的位置

class Solution_34 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = (right + left) / 2;
			if (nums[mid] == target) {
				left = mid;
				right = mid;
				int pre_left = left;
				int pre_right = right;
				while (left >= 0 && nums[left] == target) {
					pre_left = left;
					left--;
				}
				while (right<nums.size() && nums[right] == target) {
					pre_right = right;
					right++;
				}
				return vector<int>{pre_left, pre_right};
			}
			else if (nums[mid]>target) {
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		return vector<int>{-1, -1};
	}
};