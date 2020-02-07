#include<vector>

using namespace std;


//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 0, 1, 2, 2, 5, 6] might become[2, 5, 6, 0, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return true, otherwise return false.
//
//Example 1:
//
//Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 0
//	Output : true
//	Example 2 :
//
//	Input : nums = [2, 5, 6, 0, 0, 1, 2], target = 3
//	Output : false


//当mid值与右边值相等时，无法确定左边还是右边
//只能缩小右边的索引，已经确确定nums[right]与target不相等
//不能增加左边的，不确定左边的索引与target的关系



class Solution_81 {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = (right + left) / 2;
			if (nums[mid] == target)
				return true;
			//右半部分有序，增序
			if (nums[mid]<nums[right]) {
				//在右半区间
				if (nums[mid]<target&&nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			//左半部分有序，增序
			else if (nums[mid]>nums[right]) {
				//在左半区间
				if (nums[mid]>target&&nums[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
			else {
				right--;
			}
		}
		return false;

	}
};