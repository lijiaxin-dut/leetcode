#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description
//Given an array of n positive integers and a positive integer s, find the minimal length 
//of a contiguous subarray of which the sum �� s. If there isn't one, return 0 instead.

//ʹ������ָ�룬һ����ǵ�ǰsum����㣬һ����ǵ�ǰsum���յ�
//��sum>=sʱ��������������λ�ã�ֱ��sum<s


class Solution_209 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		int current_length = INT_MAX;
		int current_sum = 0;
		int current_start = 0;
		for (int i = 0; i<nums.size(); i++) {
			current_sum += nums[i];
			while (current_sum >= s) {
				current_length = min(i - current_start + 1, current_length);
				current_sum -= nums[current_start];
				current_start++;
			}
		}
		if (current_length == INT_MAX)
			return 0;
		return current_length;
	}
};

//int main() {
//	Solution_209 s;
//	vector<int>v{ 2,3,1,2,4,3 };
//	s.minSubArrayLen(7,v);
//}