#include<vector>
#include<algorithm>


using namespace std;


//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//You may assume nums1 and nums2 cannot be both empty.


//��(m+n+1)/2��(m+n+2)/2
//�ҵ���������ͳ�2����

//�����������������ҵ�k������

//�Ƚ����������k/2������(indexΪk/2-1)
//���
//��һ������ A[1] ��A[2] ��A[3]��A[k / 2] ... ��B[1]��B[2]��B[3]��B[k / 2] ..
//. ����� A[k / 2]<B[k / 2] ����ôA[1]��A[2]��A[3]��A[k / 2]
//���������ǵ� k С�����֡�

//A �����б� A[k / 2] С������ k / 2 - 1 ����B �����У�B[k / 2] �� A[k / 2] С��
//���� B[k / 2] ǰ�ߵ����ֶ��� A[k / 2] С��Ҳֻ�� k / 2 - 1 ����
//���Ա� A[k / 2] С����������� k / 1 - 1 + k / 2 - 1 = k - 2����
//���� A[k / 2] ����ǵ� k - 1 С������
//���� A[k / 2] С�������������ǵ� k С�����ˣ����Կ��԰������ų���



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
			//ɾ��mid1��ǰ�벿��
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