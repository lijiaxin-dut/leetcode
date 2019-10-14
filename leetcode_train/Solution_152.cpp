#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given an integer array nums, find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//Example 1:
//
//Input: [2, 3, -2, 4]
//	Output : 6
//	Explanation : [2, 3] has the largest product 6.
//	Example 2 :
//
//	Input : [-2, 0, -1]
//	Output : 0
//	Explanation : The result cannot be 2, because[-2, -1] is not a subarray.

//dp
//dp[i][j]��ʾi��j�ĳ˻�
//dp[i][j]=dp[i][j-1]*dp[j]
//�������Ľ������
//TLE

//dp
//������dp���飬����
//max_sub[i]��ʾ������[0, i]��Χ�ڲ���һ������nums[i]���ֵ����������˻���
//min_sub[i]��ʾ������[0, i]��Χ�ڲ���һ������nums[i]���ֵ���С������˻���
//��ʼ��ʱmax_sub[0]��min_sub[0]����ʼ��Ϊnums[0]�����඼��ʼ��Ϊ0��
//��ô������ĵڶ������ֿ�ʼ��������ô��ʱ�����ֵ����Сֵֻ��������������֮�������
//��max_sub[i - 1] * nums[i]��min_sub[i - 1] * nums[i]����nums[i]
//ʹ��rs���������������ֵ

class Solution_152 {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size();
		vector<vector<int>>dp(n, vector<int>(n, 1));
		int rs = nums[0];
		for (int i = 0; i<n; i++) {
			dp[i][i] = nums[i];
			rs = max(rs, nums[i]);
		}

		for (int length = 1; length <= n; length++) {
			for (int i = 0, j = i + length; i<n&&j<n; i++, j++) {
				dp[i][j] = dp[i][j - 1] * nums[j];
				rs = max(rs, dp[i][j]);
			}
		}
		return rs;
	}
	int maxProduct_dp(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int current_max = nums[0];
		int current_min = nums[0];
		int rs = nums[0];
		for (int i = 1; i<nums.size(); i++) {
			int p = current_max*nums[i];
			int q = current_min*nums[i];
			current_max = max(nums[i], max(p, q));
			current_min = min(nums[i], min(p, q));
			rs = max(current_max, rs);
		}
		return rs;
	}
	int maxProduct_dp_2(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> max_sub(nums.size(), 0);
		vector<int> min_sub(nums.size(), 0);
		max_sub[0] = nums[0];
		min_sub[0] = nums[0];
		int rs = nums[0];
		for (int i = 1; i<nums.size(); i++) {
			int p = max_sub[i - 1] * nums[i];
			int q = min_sub[i - 1] * nums[i];
			max_sub[i] = max(nums[i], max(p, q));
			min_sub[i] = min(nums[i], min(p, q));
			rs = max(max_sub[i], rs);
		}
		return rs;
	}
};

//int main() {
//	Solution_152 s;
//	vector<int>nums{ 2,3,-2,4 };
//	s.maxProduct(nums);
//}