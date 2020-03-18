#include<vector>




//(This problem is an interactive problem.)
//
//You may recall that an array A is a mountain array if and only if:
//
//A.length >= 3
//There exists some i with 0 < i < A.length - 1 such that :
//A[0] < A[1] < ... A[i - 1] < A[i]
//	A[i] > A[i + 1] > ... > A[A.length - 1]
//	Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.If such an index doesn't exist, return -1.
//
//	You can't access the mountain array directly.  You may only access the array using a MountainArray interface:
//
//	MountainArray.get(k) returns the element of the array at index k(0 - indexed).
//	MountainArray.length() returns the length of the array.
//	Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.Also, any solutions that attempt to circumvent the judge will result in disqualification.
//
//
//
//	Example 1:
//
//Input: array = [1, 2, 3, 4, 5, 3, 1], target = 3
//	Output : 2
//	Explanation : 3 exists in the array, at index = 2 and index = 5. Return the minimum index, which is 2.


//山峰数组查找
//1.二分法找到山顶，peak
//然后分别在左侧和右侧寻找target


 class MountainArray {
	public:
		int get(int index);
		int length();
		
};

 class Solution {
	 int find_peak(MountainArray &m) {
		 int left = 0;
		 int right = m.length() - 1;
		 while (left<right) {
			 int mid = left + (right - left) / 2;
			 if (m.get(mid)<m.get(mid + 1)) {
				 left = mid + 1;
			 }
			 else
				 right = mid;
		 }

		 return left;
	 }
	 int binary_search_left(int left, int right, int target, MountainArray &m) {
		 while (left <= right) {
			 int mid = left + (right - left) / 2;
			 int cur_val = m.get(mid);
			 if (cur_val == target)
				 return mid;
			 else if (cur_val>target)
				 right = mid - 1;
			 else
				 left = mid + 1;
		 }
		 return -1;

	 }
	 int binary_search_right(int left, int right, int target, MountainArray &m) {
		 while (left <= right) {
			 int mid = left + (right - left) / 2;
			 int cur_val = m.get(mid);
			 if (cur_val == target)
				 return mid;
			 else if (cur_val>target)
				 left = mid + 1;
			 else
				 right = mid - 1;
		 }
		 return -1;

	 }
 public:
	 int findInMountainArray(int target, MountainArray &m) {
		 int peak_index = find_peak(m);
		 int left = 0;
		 int right = m.length();
		 int left_rs = binary_search_left(0, peak_index, target, m);
		 if (left_rs != -1)
			 return left_rs;
		 return binary_search_right(peak_index, right - 1, target, m);


	 }
 };