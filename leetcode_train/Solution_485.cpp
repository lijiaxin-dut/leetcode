#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a binary array, find the maximum number of consecutive 1s in this array.
//
//Example 1:
//Input: [1, 1, 0, 1, 1, 1]
//	Output : 3
//	Explanation : The first two digits or the last three digits are consecutive 1s.
//	The maximum number of consecutive 1s is 3.
//


class Solution_485 {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int current_length = 0;
		int rs = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] == 1)
			{
				current_length++;
				rs = max(rs, current_length);
			}
			else
			{
				current_length = 0;
			}
		}
		return rs;

	}
};