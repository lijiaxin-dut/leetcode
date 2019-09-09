#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Given an array of size n, find the majority element.The majority element is the 
//element that appears more than ⌊ n / 2 ⌋ times.

//You may assume that the array is non - empty and the majority element always exist in the array.


//使用map统计每个元素出现的次数

class Solution_169 {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int>count;
		int half = nums.size() / 2;
		for (auto &one_number : nums) {
			count[one_number]++;
			if (count[one_number]>half)
				return one_number;
		}
		return 0;


	}
};