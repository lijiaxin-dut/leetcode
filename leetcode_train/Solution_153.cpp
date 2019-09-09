#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.

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


//mid<right   ,右侧有序，升序，mid最小
//mid>right   ,左侧有序，升序，left最小
//mid=right   ,找到最小



class Solution_153 {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = (int)nums.size() - 1;
		int rs = INT_MAX;
		while (left <= right) {
			int mid = (right + left) / 2;
			if (nums[mid] > nums[right]) {
				//左半部分有序,搜索右半区间
				left = mid + 1;
				rs = min(rs, nums[left]);
			}
			else if (nums[mid] < nums[right]) {
				//右半部分有序，搜索左半区间
				rs = min(rs, nums[mid]);
				right = mid - 1;
			}
			else {
				rs = min(rs, nums[mid]);
				right = mid - 1;
			}
		}
		return rs;
	}
};