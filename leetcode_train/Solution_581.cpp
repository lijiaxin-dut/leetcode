#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


class Solution_581 {
public:
	//nums[i]<nums[i-1]时，将nums[i]想前移动到合适的位置，类似与插入排序
	//记录最远的移动位置
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		int rs = 0;
		int start = INT_MAX;
		for (int i = 1; i<nums.size(); i++) {
			if (nums[i]<nums[i - 1]) {
				int j = i;
				while (j>0 && nums[j]<nums[j - 1])
				{
					swap(nums[j], nums[j - 1]);
					j--;
				}
				if (j<start)
					start = j;
				rs = i - start + 1;
			}
		}
		return rs;
	}
	//使用临时空间对数组进行排序
	//依次比较数组，找到不一致的起始位置，就是无序的区间
	int findUnsortedSubarray_2(vector<int>& nums) {
		vector<int>t = nums;
		sort(t.begin(), t.end());
		int left = 0;
		int right = nums.size() - 1;
		while (left < nums.size() && nums[left] == t[left])
			left++;
		while (right > left&&nums[right] == t[right])
			right--;
		return right - left + 1;
	}



	int findUnsortedSubarray_3(vector<int>& nums) {
		int n = nums.size();
		vector<int>maxlhs(n);// max number from left to cur
		vector<int>minrhs(n);// min number from right to cur
		int max_val = INT_MIN;
		for (int i = 0; i < n; i++) {
			max_val = max(nums[i], max_val);
			maxlhs[i] = max_val;

		}
		int min_val = INT_MAX;
		for (int i = n - 1; i >= 0; i--) {
			min_val = min(nums[i], min_val);
			minrhs[i] = min_val;
		}
		int i = 0, j = n - 1;
		//当前值比右边最小值还要小，已经有序，找到比最右边最小值小的索引
		while (i < n && nums[i] <= minrhs[i])
			i++;
		//当前值比左边最大值还要大，已经有序，找到比最左边最大值大的索引
		while (j > i && nums[j] >= maxlhs[j])
			j--;

		return j + 1 - i;
	}
};