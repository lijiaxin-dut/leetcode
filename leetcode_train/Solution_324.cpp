#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//
//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
//	Example 1:
//
//Input: nums = [1, 5, 1, 1, 6, 4]
//	Output : One possible answer is[1, 4, 1, 5, 1, 6].


//波浪排序
//首相由大到小排序
//将数组分为两部分，前半部分和后半部分，交替不停的从两部分取出元素


class Solution_324 {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<int>());
		int left = 0;
		int right = nums.size() / 2;
		auto temp = nums;
		for (int i = 0; i<nums.size(); i++)
		{
			if (i % 2 == 0)
				nums[i] = temp[right++];
			else
				nums[i] = temp[left++];
		}

	}
};