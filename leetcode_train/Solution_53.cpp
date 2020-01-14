#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an integer array nums, find the contiguous subarray 
//(containing at least one number) which has the largest sum and return its sum.


//1.�����С��0ʱ����������ͣ�����һ����������������й���


//2.���η�
//mid������һ��Ϊ2�������������ͷֱ�����ߣ��ұߺͺ����������
//�����������ʱ��mid�����Ž��У���mid��left��ͣ���¼���ֵ
//��mid��right��ͣ���¼���ֵ
//��������ֵ�е����ֵ



class Solution_53 {
public:

	int maxSubArray_dd(vector<int>& nums) {
		return maxSubArray_dd(nums, 0, nums.size() - 1);
	}
	int maxSubArray_dd(vector<int>& nums, int left, int right) {
		if (left > right) {
			return INT_MIN;
		}
		int mid = left + (right - left) / 2;
		int l_max = maxSubArray_dd(nums, left, mid - 1);
		int r_max = maxSubArray_dd(nums, mid + 1, right);
		int mid_left_max = 0;
		for (int i = mid - 1, sum = 0; i >= left; i--) {
			sum += nums[i];
			mid_left_max = max(sum, mid_left_max);
		}
		int mid_right_max = 0;
		for (int i = mid + 1, sum = 0; i <= right; i++) {
			sum += nums[i];
			mid_right_max = max(mid_right_max, sum);
		}
		return max(max(l_max, r_max), mid_left_max + mid_right_max + nums[mid]);

	}


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