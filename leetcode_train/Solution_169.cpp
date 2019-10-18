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


//投票法
//不断的消去不等的数字

class Solution_169 {
public:
	int majorityElement(vector<int>& nums) {
		int val = 0;
		int count = 0;
		for (auto &i : nums) {
			if (i == val)
				count++;
			else if (count == 0) {
				count = 1;
				val = i;
			}
			else
				count--;
		}
		return val;
	}
};