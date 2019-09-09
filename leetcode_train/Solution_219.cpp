#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


//Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
//in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
//
//Example 1:
//
//Input: nums = [1, 2, 3, 1], k = 3
//	Output : true
//	Example 2 :
//
//	Input : nums = [1, 0, 1, 1], k = 1
//	Output : true

class Solution_219 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		// for(int i=0;i<nums.size();i++){
		//    for(int j=i+1;j<=i+k&&j<nums.size();j++){
		//        if(nums[i]==nums[j])
		//            return true;
		//    }
		// }
		// return false;
		unordered_map<int, int>hash_map;
		for (int i = 0; i<nums.size(); i++) {
			if (hash_map.find(nums[i]) != hash_map.end() && i - hash_map[nums[i]] <= k)
				return true;
			else
				hash_map[nums[i]] = i;
		}
		return false;

	}
};