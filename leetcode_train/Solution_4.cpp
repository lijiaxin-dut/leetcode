#include<vector>

using namespace std;


//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//You may assume nums1 and nums2 cannot be both empty.

//线性查找两个数组中的第k个数字
//找(m+n+1)/2和(m+n+2)/2
//找到的数字求和除2即可


class Solution_4 {
	double find_k_value(vector<int>& nums1, vector<int>& nums2, int k) {
		int m = nums1.size();
		int n = nums2.size();
		int n1_index = 0;
		int n2_index = 0;
		int cur_index = 0;
		int pre_value = 0;
		while (true) {
			if (n1_index<m&&n2_index<n) {
				if (nums1[n1_index]<nums2[n2_index]) {
					pre_value = nums1[n1_index];
					n1_index++;
				}
				else {
					pre_value = nums2[n2_index];
					n2_index++;
				}
			}
			else if (n1_index<m&&n2_index == n) {
				pre_value = nums1[n1_index];
				n1_index++;
			}
			else if (n1_index == m&&n2_index<n) {
				pre_value = nums2[n2_index];
				n2_index++;
			}
			cur_index++;
			if (cur_index == k)
				return pre_value;
		}


	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		return (find_k_value(nums1, nums2, (m + n + 1) / 2) + find_k_value(nums1, nums2, (m + n + 2) / 2)) / 2;
	}
};