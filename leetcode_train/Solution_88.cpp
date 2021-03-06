#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

//Note:
//The number of elements initialized in nums1 and nums2 are m and n respectively.
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold
//additional elements from nums2.


//从后向前一次判断，从后面开始填充
//最后将剩下的数字全部拷贝到前面

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int min_length = min(m, n);
		int i = m - 1, j = n - 1;
		int current_index = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] <= nums2[j]) {
				nums1[current_index--] = nums2[j--];
			}
			else {
				nums1[current_index--] = nums1[i--];
			}
		}
		while (i >= 0) 
			nums1[current_index--] = nums1[i--];
		while (j >= 0) 
			nums1[current_index--] = nums2[j--];
	}
};