#include<iostream>
#include<vector>

using namespace std;
//һ������Ϊn - 1�ĵ������������е��������ֶ���Ψһ�ģ�
//����ÿ�����ֶ��ڷ�Χ0��n - 1֮�ڡ�
//�ڷ�Χ0��n - 1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int left = 0;
		int right = nums.size();
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == mid) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left;

	}
};