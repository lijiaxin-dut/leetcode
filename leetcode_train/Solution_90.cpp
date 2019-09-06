#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//	Example :
//
//	Input : [1, 2, 2]
//	Output :
//	[
//		[2],
//		[1],
//		[1, 2, 2],
//		[2, 2],
//		[1, 2],
//		[]
//	]

//对数组进行排序
//如果不是第一个数字，判断跟前一个数字是否相同
//跳过相同的数字


class Solution_90 {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>();
		sort(nums.begin(), nums.end());
		vector<vector<int>> rs;
		vector<int>one_subset;
		rs.push_back(one_subset);
		for (int i = 0; i<nums.size(); i++) {
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			help(rs, one_subset, nums, i);
		}
		return rs;
	}
	void help(vector<vector<int>> &rs, vector<int>&one_subset, vector<int>& nums, int start_index) {
		if (start_index >= nums.size())
			return;
		one_subset.push_back(nums[start_index]);
		rs.push_back(one_subset);
		for (int i = start_index + 1; i<nums.size(); i++) {
			if (i>start_index + 1 && nums[i] == nums[i - 1])
				continue;
			help(rs, one_subset, nums, i);
		}
		one_subset.pop_back();
	}
};