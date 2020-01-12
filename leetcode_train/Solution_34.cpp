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

//¿˚”√upper bound∫Õlower bound

class Solution_34 {
public:
	int lowerbound(vector<int>& nums, int target) {
		const int N = nums.size();
		// [l, r)
		int l = 0, r = N;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}
	int upperbound(vector<int>& nums, int target) {
		const int N = nums.size();
		// [l, r)
		int l = 0, r = N;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] <= target) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		return l;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int low = lowerbound(nums, target);
		int high = upperbound(nums, target);
		if (low == high)
			return{ -1, -1 };
		else
			return{ low, high - 1 };

	}
};