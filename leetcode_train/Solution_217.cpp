#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//
//Given an array of integers, find if the array contains any duplicates.
//
//Your function should return true if any value appears at least twice in the array, 
//and it should return false if every element is distinct.
//
//Example 1:
//
//Input: [1, 2, 3, 1]
//	Output : true


class Solution_217 {
public:
	bool containsDuplicate_1(vector<int>& nums) {
		set<int> my_num;
		for (int i = 0; i<nums.size(); i++)
		{
			if (my_num.find(nums[i]) != my_num.end())
				return true;
			my_num.insert(nums[i]);
		}
		return false;
	}
};