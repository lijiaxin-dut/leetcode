#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].

//使用hash_map标记遇到过的数组

class Solution_1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int>hash_map;
		for (int i = 0; i<nums.size(); i++) {
			if (hash_map.find(nums[i]) != hash_map.end()) {
				return vector<int>{i, hash_map[nums[i]]};
			}
			else
				hash_map[target - nums[i]] = i;
		}
		return vector<int>{};
	}
};