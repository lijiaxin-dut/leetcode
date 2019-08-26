#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description
//Given an array of integers that is already sorted in ascending order, find two numbers such 
//that they add up to a specific target number.

//The function twoSum should return indices of the two numbers such that they add up to the 
//target, where index1 must be less than index2.

//Note:
//Your returned answers(both index1 and index2) are not zero - based.
//You may assume that each input would have exactly one solution and you may not use the same 
//element twice.

class Solution_167 {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int lo = 0;
		int hi = numbers.size() - 1;
		vector<int>rs;
		while (lo<hi) {
			if (numbers[lo] + numbers[hi]>target)
				hi--;
			else if (numbers[lo] + numbers[hi]<target)
				lo++;
			else {
				rs.push_back(lo + 1);
				rs.push_back(hi + 1);
				break;
			}
		}
		return rs;
	}
};