#include<vector>

using namespace std;
//
//Find the kth largest element in an unsorted array.Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Example 1:
//
//Input: [3, 2, 1, 5, 6, 4] and k = 2
//	Output : 5

//找到第k大的数字
//使用partition，由大到小排序，返回大于等于轴的位置
//如果p==k-1  返回nums[p]
//p>k-1   right=p-1   在左半侧找
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
		int i = left;//i是第一个<=pivot的元素
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