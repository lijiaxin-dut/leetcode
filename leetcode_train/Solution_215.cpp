#include<vector>

using namespace std;
//
//Find the kth largest element in an unsorted array.Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Example 1:
//
//Input: [3, 2, 1, 5, 6, 4] and k = 2
//	Output : 5

//�ҵ���k�������
//ʹ��partition���ɴ�С���򣬷��ش��ڵ������λ��
//���p==k-1  ����nums[p]
//p>k-1   right=p-1   ��������
// 0 0 0 0 0 k 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 p 0 0
//else    left=p+1



class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int p = partition(nums, left, right);
			if (p == k - 1)
				return nums[p];
			else if (p > k - 1) {
				right = p - 1;
			}
			else {
				left = p + 1;
			}
		}
		return 0;
	}

	int partition(vector<int>&nums, int left, int right) {
		int pivot = nums[right];
		int i = left;//i�ǵ�һ��<=pivot��Ԫ��
		for (int j = left; j <= right; j++) {
			if (nums[j]>pivot) {
				swap(nums[j], nums[i]);
				i++;
			}
		}
		swap(nums[i], nums[right]);
		return i;



	}
};