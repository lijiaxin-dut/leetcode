#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
//
//You are a professional robber planning to rob houses along a street.
//Each house has a certain amount of money stashed.All houses 
//at this place are arranged in a circle.That means the first house 
//the neighbor of the last one.Meanwhile, adjacent houses have security system 
//connected and it will automatically contact the police if two adjacent houses 
//were broken into on the same night.
//
//Given a list of non - negative integers representing the amount of money of each house,
// determine the maximum amount of money you can rob tonight without alerting the police.
//
//Example 1:
//
//Input: [2, 3, 2]
//	Output : 3
//	Explanation : You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//	because they are adjacent houses.


//��һ��λ�������һ��λ������
//������ֽ�Ϊ����������
//��������һ��λ��
//���������һ��λ��

//�������ֵ

//dp[i]��ʾ��i�����ֵ����һ������i
//dp[i]=max(dp[i-1],nums[i]+dp[i-2])
//��ǰ����λ�����


class Solution_213 {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		else if (nums.size() == 1)
			return nums[0];
		else if (nums.size() == 2)
			return max(nums[0], nums[1]);
		//ȥ����һ��λ�ú����һ��λ��
		int n = nums.size();
		int no_first = help(nums, 1, n - 1, n - 1);
		int no_last = help(nums, 0, n - 2, n - 1);
		return max(no_first, no_last);
	}
	int help(vector<int>& nums, int start, int end, int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[start];
		if (n == 2)
			return max(nums[start], nums[start + 1]);
		vector<int>dp(n + 1, 0);
		dp[start] = nums[start];
		dp[start + 1] = max(nums[start], nums[start + 1]);
		for (int i = start + 2; i <= end; i++) {
			dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
		}
		return dp[end];

	}
};

//int main() { 
//	Solution_213 s;
//	s.rob(vector<int>{ 1,7,9,2 });
//}