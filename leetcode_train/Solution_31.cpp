#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution_31 {
public:
	//从最尾端开始找，找第一个降序的位置满足i>i-1
	//从尾端开始找，找出第一个大于i-1的元素
	//交换i-1 j
	//i到end逆序
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 1)
			return;
		for (int i_1 = nums.size() - 2, i = nums.size() - 1; i_1 >= 0; i--, i_1--) {
			//找到第一个降序的位置，i-1<i
			if (nums[i_1]<nums[i]) {
				for (int j = nums.size() - 1; j >= i - 1; j--) {
					//找到第一个比i-1大的位置
					if (nums[j]>nums[i - 1]) {
						swap(nums[i - 1], nums[j]);
						//i到结尾逆序
						reverse(nums.begin() + i, nums.end());
						return;
					}
				}
			}
		}
		reverse(nums.begin(), nums.end());
		return;
	}
};