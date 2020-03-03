
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;


//Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.
//
//
//
//Example:
//
//Input: [4, 6, 7, 7]
//	Output : [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7, 7], [4, 7, 7]]
//
//


class Solution_491 {
public:
	vector<vector<int>> findSubsequences_set(vector<int>& nums) {
		vector<vector<int>>rs;
		vector<int>partial_rs;
		dfs(rs, partial_rs, 0, nums);
		return rs;
	}
	void dfs(vector<vector<int>>&rs, vector<int>&partial_rs, int cur_index, vector<int>& nums) {
		if (cur_index >= nums.size())
			return;
		//使用set去重，之前出现过就不用继续dfs
		unordered_set<int>s;
		for (int i = cur_index; i<nums.size(); i++) {
			if (s.count(nums[i]))
				continue;
			if ((!partial_rs.empty() && nums[i] >= partial_rs.back()) || partial_rs.empty()) {
				s.insert(nums[i]);
				partial_rs.push_back(nums[i]);
				if (partial_rs.size() >= 2)
					rs.push_back(partial_rs);
				dfs(rs, partial_rs, i + 1, nums);
				partial_rs.pop_back();
			}
		}


	}
	vector<vector<int>> findSubsequences(vector<int>& nums) {

		set<vector<int>>rs;
		vector<int>partial;
		for (int i = 0; i<nums.size(); i++) {
			partial.push_back(nums[i]);
			dfs(rs, nums, partial, i);
			partial.pop_back();
		}
		return{ rs.begin(),rs.end() };

	}
	void dfs(set<vector<int>>&rs, vector<int>&nums, vector<int>&partial, int current_index) {
		if (partial.size() >= 2)
			rs.insert(partial);
		if (current_index >= nums.size())
			return;
		for (int i = current_index + 1; i<nums.size(); i++) {
			if (nums[i] >= partial.back()) {
				partial.push_back(nums[i]);
				dfs(rs, nums, partial, i);
				partial.pop_back();
			}
		}

	}
};

//int main() {
//	Solution_491 s;
//	s.findSubsequences(vector<int>{4, 6, 7, 7});
//}