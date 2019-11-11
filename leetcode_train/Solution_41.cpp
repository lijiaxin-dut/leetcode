#include<set>
#include<vector>

using namespace std;

//Given an unsorted integer array, find the smallest missing positive integer.
//
//Example 1:
//
//Input: [1, 2, 0]
//	Output : 3
//	Example 2 :
//
//	Input : [3, 4, -1, 1]
//	Output : 2
//	Example 3 :
//
//	Input : [7, 8, 9, 11, 12]
//	Output : 1


//使用临时空间，保存所有的正数

//第一个消失的正数一定在[1 ,n]之间，或者为n+1

//不断的将该范围的数字放到数组中对应的为止上


class Solution_41 {
public:
	int firstMissingPositive_one_pass(vector<int>& nums) {
		for (int i = 0; i<nums.size(); i++) {
			while (nums[i]>0 && nums[i]<nums.size() && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i<nums.size(); i++)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
	int firstMissingPositive(vector<int>& nums) {
		set<int>count_number;
		for (auto &one_num : nums) {
			if (one_num>0)
				count_number.insert(one_num);
		}
		int rs = 1;
		for (auto &one_rs : count_number) {
			if (rs != one_rs)
				return rs;
			rs++;
		}
		return count_number.size() + 1;
	}
};