#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given a set of distinct integers, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//	Example :
//
//	Input : nums = [1, 2, 3]
//	Output :
//	[
//		[3],
//		[1],
//		[2],
//		[1, 2, 3],
//		[1, 3],
//		[2, 3],
//		[1, 2],
//		[]
//	]

//遍历所有可能的开始位置，进行递归
//子集中有一个空元素

class Solution_78 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty())
			return vector<vector<int>>();
		vector<vector<int>> rs;
		vector<int>one_subset;
		rs.push_back(one_subset);
		for (int i = 0; i<nums.size(); i++)
			help(rs, one_subset, nums, i);
		return rs;
	}
	void help(vector<vector<int>> &rs, vector<int>&one_subset, vector<int>& nums, int start_index) {
		if (start_index >= nums.size())
			return;
		one_subset.push_back(nums[start_index]);
		rs.push_back(one_subset);
		for (int i = start_index + 1; i<nums.size(); i++) {
			help(rs, one_subset, nums, i);
		}
		one_subset.pop_back();



	}
};

//int main() {
//	Solution_78 s;
//	vector<int>nums{ 1,2,3 };
//	s.subsets(nums);
//}