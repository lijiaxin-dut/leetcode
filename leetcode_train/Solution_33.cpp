#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//0　　1　　2　　 4　　5　　6　　7
//
//7　　0　　1　　 2　　4　　5　　6
//
//6　　7　　0　　 1　　2　　4　　5
//
//5　　6　　7　　 0　　1　　2　　4
//
//4　　5　　6　　7　　0　　1　　2
//
//2　　4　　5　　6　　7　　0　　1
//
//1　　2　　4　　5　　6　　7　　0

//二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段，
//我们观察上面红色的数字都是升序的，由此我们可以观察出规律，
//如果中间的数小于最右边的数，则右半段是有序的，
//若中间数大于最右边数，则左半段是有序的
//判断target是否在有序的区间内，跟端点值进行比较



class Solution_33 {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = (right + left) / 2;
			if (nums[mid] == target)
				return mid;
			//右半部分有序，增序
			if (nums[mid]<nums[right]) {
				if (nums[mid]<target&&nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			//左半部分有序，增序
			else {
				if (nums[mid]>target&&nums[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		return -1;

	}
};