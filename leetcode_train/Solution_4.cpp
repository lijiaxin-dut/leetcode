#include<vector>
#include<algorithm>


using namespace std;


//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//You may assume nums1 and nums2 cannot be both empty.


//找(m+n+1)/2和(m+n+2)/2
//找到的数字求和除2即可

//在两个有序数组中找第k个数字

//比较两个数组第k/2个数字(index为k/2-1)
//如果
//更一般的情况 A[1] ，A[2] ，A[3]，A[k / 2] ... ，B[1]，B[2]，B[3]，B[k / 2] ..
//. ，如果 A[k / 2]<B[k / 2] ，那么A[1]，A[2]，A[3]，A[k / 2]
//都不可能是第 k 小的数字。

//A 数组中比 A[k / 2] 小的数有 k / 2 - 1 个，B 数组中，B[k / 2] 比 A[k / 2] 小，
//假设 B[k / 2] 前边的数字都比 A[k / 2] 小，也只有 k / 2 - 1 个，
//所以比 A[k / 2] 小的数字最多有 k / 1 - 1 + k / 2 - 1 = k - 2个，
//所以 A[k / 2] 最多是第 k - 1 小的数。
//而比 A[k / 2] 小的数更不可能是第 k 小的数了，所以可以把它们排除。



class Solution_4 {
	int get_kth_value(vector<int>&nums1, int s1, int e1, vector<int>&nums2, int s2, int e2, int k) {
		int len1 = e1 - s1 + 1;
		int len2 = e2 - s2 + 1;
		if (len2 == 0)
			return nums1[s1 + k - 1];
		if (len1 == 0)
			return nums2[s2 + k - 1];
		if (k == 1)
			return min(nums1[s1], nums2[s2]);
		int mid1 = s1 + min(len1, k / 2) - 1;
		int mid2 = s2 + min(len2, k / 2) - 1;
		if (nums1[mid1]<nums2[mid2]) {
			//删除mid1的前半部分
			return get_kth_value(nums1, mid1 + 1, e1, nums2, s2, e2, k - (mid1 - s1 + 1));
		}
		else {
			return get_kth_value(nums1, s1, e1, nums2, mid2 + 1, e2, k - (mid2 - s2 + 1));
		}


	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int k1 = (m + n + 1) / 2;
		int k2 = (m + n + 2) / 2;
		return (get_kth_value(nums1, 0, m - 1, nums2, 0, n - 1, k1) + get_kth_value(nums1, 0, m - 1, nums2, 0, n - 1, k2)) / 2.0;
	}
};