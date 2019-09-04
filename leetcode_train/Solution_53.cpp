#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an integer array nums, find the contiguous subarray 
//(containing at least one number) which has the largest sum and return its sum.


//�����С��0ʱ����������ͣ�����һ����������������й���
class Solution_53 {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int sum = 0;
		int rs = nums[0];
		for (int i = 0; i<nums.size(); i++) {
			sum += nums[i];
			rs = max(rs, sum);
			if (sum<0) {
				sum = 0;
				continue;
			}
		}
		return rs;

	}
};